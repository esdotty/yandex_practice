//https://contest.yandex.ru/contest/23815/run-report/112955087/
/*
-- ПРИНЦИП РАБОТЫ --
Идея реализации взята из урока Практикума: https://practicum.yandex.ru/learn/algorithms/courses/64238f3a-611a-4618-a86d-adf78b1990f3/sprints/275303/topics/6f583b01-7370-422a-ba94-71203f6e0c27/lessons/79194e62-a934-4152-8497-525b8e996cdb/
и основана на алгориттме бинарноого поиска, с тем отличием, что на входе частично отсортированный массив.
На каждой итерации мы проверяем является ли "левый" интервал относительно центрального элемента отсортированным и проверяем входит ли искомое число в этот интервал. Если да, то
продолжаем поиск в этотм интервале, если нет ищем в правом интервале. Если интервал не отсортирован, проверяем входит ли искомое число в "правый" интервал, который в
этот случае отсортирован. Если да, то продолжаем поиск в этом интервале, если нет ищем в "левом" интервале.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Сложность алгоритма - O(logn).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Данный алгоритм не задействует дополнительную память
*/

//#include "solution.h"
#include <vector>
#include <cassert>

int broken_search(const std::vector<int>& vec, int k)
{
    int left = 0;
    int right =  vec.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] == k)
        {
            return mid;
        }

        if (vec[mid] >= vec[left])
        {
            if (k >= vec[left] && k <= vec[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (k >= vec[mid] && k <= vec[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

void test() {
    std::vector<int> arr = {19, 21, 100, 101, 1, 4, 5, 7, 12};
    assert(6 == broken_search(arr, 5));
}
