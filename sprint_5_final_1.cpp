https://contest.yandex.ru/contest/24810/run-report/114819368/

/*
-- ПРИНЦИП РАБОТЫ --
Для сортировки списка участников использована пирамидальная сортировка кучей. Куча реализована с помощью массива.
На первом этапе создаем пустую бинарную убывающую кучу. Далее в неё по одному добавляем все элементы массива, сохраняя свойства кучи.
На вершине кучи располагается самый больший элемент. Далее извлекаем наиболее приоритетные элементы (с самым большим значение), удаляя их из кучи.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
На первом этапе создается бинарная куча. Сложность этой операции - О(1).
Добавление в бинарную кучу в худшем случае - O(nlogn), извлечение из бинарной кучи  - O(nlogn). Суммарно: O(nlogn) + O(nlogn) + О(1)

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для сортировки создаем кучу размером О(n) и массив для хранения результата размером О(n), соответственно задействуется 2*О(n) дополнительной памяти
*/



#include <cstdint>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Node {
public:
    string login;
    int score;
    int fine;

    Node(string _login, int _score, int _fine) :
        login(_login),
        score(_score),
        fine(_fine)
    { }

    bool operator > (const Node& other) const
    {
        if (score != other.score)
            return score > other.score;
        if (fine != other.fine)
            return fine < other.fine;
        return login < other.login;
    }

    bool operator < (const Node& other) const
    {
        return other > *this;
    }
};

class Heap {
private:
    vector<Node> items;

private:
    void sift_up(int index)
    {
        if (index == 0)
        {
            return;
        }

        int parent_index = (index - 1) / 2;

        if (items[parent_index] < items[index])
        {
            swap(items[parent_index], items[index]);
            sift_up(parent_index);
        }
    }

    void sift_down(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left > items.size() - 1)
        {
            return;
        }

        int index_largest = left;
        if (right <= items.size() - 1 && items[right] > items[left])
        {
            index_largest = right;
        }

        if (items[index_largest] > items[index])
        {
            swap(items[index], items[index_largest]);
            sift_down(index_largest);
        }
    }

public:
    Heap() { }

    void add(const string _login, int _score, int _fine)
    {
        Node node(_login, _score, _fine);

        items.push_back(node);
        int index = items.size() - 1;
        sift_up(index);
    }

    string pop()
    {
        string result = items[0].login;
        items[0] = items[items.size() - 1];
        items.pop_back();

        if (items.size() > 1)
            sift_down(0);

        return result;
    }

    int size ()
    {
        return items.size();
    }
};

int main()
{
    int count;
    cin >> count;

    Heap heap;
    string login;
    int score = 0;
    int fine = 0;


    for (int i = 0; i < count; ++i)
    {
        cin >> login;
        cin >> score;
        cin >> fine;

        heap.add(login, score, fine);
    }

    vector<string> result;
    while (heap.size() > 0)
    {
        string name = heap.pop();
        result.push_back(name);
    }

    for (auto login : result)
        cout << login << "\n";

    return 0;
}
