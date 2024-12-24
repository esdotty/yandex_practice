//https://contest.yandex.ru/contest/23815/run-report/113056565/

/*
-- ПРИНЦИП РАБОТЫ --
Идея реализации взята из урока Практикума: https://practicum.yandex.ru/learn/algorithms/courses/64238f3a-611a-4618-a86d-adf78b1990f3/sprints/275303/topics/6f583b01-7370-422a-ba94-71203f6e0c27/lessons/de1f260f-8007-4db5-9030-a40411985941/
и принципа, описанного в условиях задачи. В отличии от обычной быстрой сортировки, здесь на этапе разделения массива на части меньшего размера заводим
переменные для хранения индексов left и right, которые изначально будут указывать на левый и правый концы отрезка соответственно. Это сделано для того, чтобы не использовать дополнительную память.
Будем их двигать на встречу друг другу до тех пор пока элемент с индексом  left больше опорного, а с right меньше.
Таким образом получаем, что все элементты левее left больше опорного элемента, правее от right меньше.
Элементы, на которых остановились, нарушают порядок и мы меняем их местами и переходим к следующим элементам массива.
Будем повторять это действие до тех пор, пока left и right не столкнутся.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Сложность алгоритма в худшем случае О(n^2), а в среднем O(nlogn) и зависит от выбоора опорного элемента

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
При реализации была использована рекурсия, каждый рекурсивный вызов задействует память на стеке.
Глубина рекурсии составляет O(logn), соответсвенно задействуется O(logn) дополнительной памяти.
*/


#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    string login;
    int score;
    int fine;

    /*
    friend bool operator > (const Node& left, const Node& right)
    {
        if (left.score > right.score)
            return true;
        else if (left.score == right.score)
        {
            if (left.fine < right.fine)
                return true;
            else if (left.fine == right.fine)
            {
                if (left.login < right.login)
                    return true;
            }
        }

        return false;
    }
*/

    friend bool operator < (const Node& left, const Node& right)
    { return (right > left); }

    bool operator > (const Node& other) const
    {
        if (this->score > other.score)
            return true;
        else if (this->score == other.score)
        {
            if (this->fine < other.fine)
                return true;
            else if (this->fine == other.fine)
            {
                if (this->login < other.login)
                    return true;
            }
        }

        return false;
    }
};

std::tuple<int, int> partition(std::vector<Node>& array, Node& pivot, int left, int right)
{
    int l = left;
    int r = right;

    while (l <= r)
    {
        while (array[r] < pivot)
            r--;

        while (array[l] > pivot)
            l++;

        if (l <= r)
        {
            swap(array[l], array[r]);
            l++;
            r--;
        }
    }

    return {r, l};
}

void quicksort(std::vector<Node>& array, int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int index = left + rand() % (right - left + 1);
        Node pivot = array[index];
        auto [x, y] = partition(array, pivot, left, right);

        quicksort(array, left, x);
        quicksort(array, y, right);
    }
}

int main()
{
    int count;
    cin >> count;

    vector<Node> arr(count);

    for (int i = 0; i < count; ++i)
    {
        cin >> arr[i].login;
        cin >> arr[i].score;
        cin >> arr[i].fine;
    }

    quicksort(arr, 0 , count - 1);

    for (int i = 0; i < count; ++i)
        cout << arr[i].login << "\n";

    return 0;
}
