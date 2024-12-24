
https://contest.yandex.ru/contest/22781/run-report/107417886/

/*
-- ПРИНЦИП РАБОТЫ --
Для реализации парсинга арифмитического выражения в польской нотации был использован стек(на массиве)
как этот было описано в условии задачи.
Если на вход поступает операнд, то он помещается на вершину стека, если знак операции, то выполняется операция над
двумя операндами в порядке их добавления. Результат помещается на вершину стека.
После обработки всех элементов входной последовательности на печать выводится результат, который находится на вершине стека.


-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Добавление во входной стек стоит O(1), извлечение тоже О(1).
Каждый элемент будет добавлен и удален из стека ровно один раз.
Это значит, что добавление и извлечение n элементов(операндов) в сумме будет стоить O(n). Кроме того, каждый раз после обработки
знака операции на стек помещается результат примерно n - 1 раз. Т.е. сложность составит O(n).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
В худшем случает стек будет содержать n элементов, в лучшем 2 элемента
т.е. потреблять в среднем O(n/2) памяти.
*/

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

class Stack {
private:
    vector<int> items;

public:
    void push(int item)
    { items.push_back(item); }

    int pop()
    {
        int item = items.back();
        items.pop_back();

        return item;
    }

    int size()
    { return items.size(); }
};

int main() {

    Stack stack;

    string inputLine;
    getline(cin, inputLine, '\n');

    stringstream streamLine;
    streamLine << inputLine;

    while (!streamLine.eof())
    {
        string item;
        streamLine >> item;

        int item_1;
        int item_2;

        if ((item != "+") && (item != "-") && (item != "*") && (item != "/"))
        {
            int value = stoi(item);
            stack.push(value);
        }
        else
        {
            item_1 = stack.pop();
            item_2 = stack.pop();

            if (item == "*")
            {
                stack.push(item_2 * item_1);
            }
            else if (item == "/")
            {
                int result = floor((double)item_2 / (double)item_1);
                stack.push(result);
            }
            else if (item == "-")
            {
                stack.push(item_2 - item_1);
            }
            else
            {
                stack.push(item_2 + item_1);
            }
        }
    }

    cout << stack.pop();

    return 0;
}
