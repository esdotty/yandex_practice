https://contest.yandex.ru/contest/22781/run-report/107675445/

/*
-- ПРИНЦИП РАБОТЫ --
Для реализации дек был использован кольцевой буфер, реализованный как вектор заданного размера. Для добавления и удаления элементов
используются два поля head и tail, в которых хранятся индексы начала и конца дека.

Идея реализации взята из урока Практикума: https://practicum.yandex.ru/learn/algorithms/courses/7f101a83-9539-4599-b6e8-8645c3f31fad/sprints/210404/topics/3fe165ac-9a25-44db-b5bf-106709d1c140/lessons/b5036361-6d27-45be-ac0a-3946d9a0fcde/

Добавление в конец дека:
После добавления элемента в конец дека увеличиваем значение поля tail, и новый элемент будет записываться в следующую ячейку.
Значение tail берётся по модулю max_n. Это делается для того, чтобы первая ячейка следовала за последней.

При извлечении из начала дека удаляется добавленный ранее всех элемент. Значение поля head в методе  pop_front()
изменяется аналогично полю tail в методе push_back().
Если мы удалили элемент на какой-то позиции i в массиве, то в следующий раз нужно извлекать из ячейки i+1 по циклу.

Добавление элементов в начало дека и удаление из конца происходит "против часовой стрелки", если представить визуально зацикленный массив.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Т.к. не нужно выделять память, каждая операция добавления/удаления выполняется за O(1).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Максимальный размер дека задается числом m - создается вектор размера m, т.е. потребляет O(m) памяти.
*/

#include <iostream>
#include <optional>
#include <vector>


        using namespace std;

class Deque {
private:
    vector<optional<int>> items;
    int maxSize;
    int tail;
    int head;
    int size;

public:
    Deque(int _maxSize) {
        maxSize = _maxSize;
        items.resize(maxSize);
        tail = 0;
        head = 0;
        size = 0;
    }

    void push_back(int value)
    {
        if(size == maxSize)
        {
            cout << "error" << "\n";
            return;
        }

        items[tail] = value;
        tail = (tail + 1) % maxSize;
        ++size;
    }

    void push_front(int value)
    {
        if(size == maxSize)
        {
            cout << "error" << "\n";
            return;
        }

        int index = (head - 1 + maxSize) % maxSize;
        items[index] = value;
        head = index;
        ++size;
    }

    optional<int> pop_front()
    {
        if(size == 0)
            return nullopt;

        int item = items[head].value();

        items[head] = nullopt;
        head = (head + 1) % maxSize;
        --size;

        return item;
    }

    optional<int> pop_back()
    {
        if(size == 0)
            return nullopt;

        int index = (tail - 1 + maxSize) % maxSize;
        int item = items[index].value();

        items[index] = nullopt;
        tail = index;
        --size;

        return item;
    }
};

int main() {
    int commandCount;
    cin >> commandCount;

    int maxSize;
    cin >> maxSize;

    Deque deque(maxSize);

    for (int i = 0; i < commandCount; ++i)
    {
        string commandName;
        cin >> commandName;

        int value;
        optional<int> result;

        if (commandName == "push_back")
        {
            cin >> value;
            deque.push_back(value);
        }
        else if (commandName == "push_front")
        {
            cin >> value;
            deque.push_front(value);
        }
        else if (commandName == "pop_back")
        {
            result = deque.pop_back();

            if (result.has_value())
                cout << result.value() << "\n";
            else
                cout << "error" << "\n";
        }
        else
        {
            result = deque.pop_front();

            if (result.has_value())
                cout << result.value() << "\n";
            else
                cout <<"error" << "\n";
        }
    }

    return 0;
}


phypfwzwqhswfqzxxbufrodwhrdofhcqmsibiabkewnosxeivksjdtkheovkelddvidldtmefdvpumowepwexhxdgdscnhphnscogcvvvmilqnokvcfzrefhpboevnkejfxncdnhwjjbfauhokyrmtcrlpvxlxhsswcyqwmpqiusspioacaizoxhauzoyrngjsnrmumctumshkxsfthialqrzohsoyynlimqflthwhpaulefblqyvhlxhdmxfpeapupayuplyditvegxwhhmhoeewjjusodnihuqhfrjdkjsiarxmkjfbscapyqeqxjtlralmeielqoqhrbiijllhoysrdpcvbnykxfezujwrvxeruzejqpsslaclkphyxsywwshjvenpatbjmuwaxjbssnqwkvmefvxkaxlxhntwyqqpceggpizuxumtzlvajovramxdevgvieyzvocadlapsphthvdbzrictcnzlzvamqvngyffwrunjtwcfqjalpysyubbjfgnkvgypbsmkontlrxmknadzlolwenmiombjovmvbdlpinxnlstdgpjbcfvuppnqciodduwbmojwamuhbtaikmgeqppofiihwmgmcuorwiyqlpqtkdvpewhxnyylnubcrdbvvtvnazvmfpbwodguiimkfbrbgzxdhocqxpjmohbtjvygirfgpxuscxfbrorlvvfcfabjrcozehiivqsjnvitbufttfnkyecodzwbpcvrbevirdqpejqnwsucxaomwdoexfgnturmpkexhvfyfbhnhufjldfkbuscvqxvmijsyucsablfuxuhvausbqfzharwuvbykvtkwexerechpxxeshzyfzvxhperbxfnlszwqlvmgbimzarjwidekfbeaydpnydkrkcwiowunhmnayzpnpghnetcgftlvpkjujcysqkcgvdiuzvdzpbixkunxknbfhpvgokglmwpckmpjtqynhvebikvafaqpmbmapgxscavidcbxjqhhp

        File is too long to be displayed fully

