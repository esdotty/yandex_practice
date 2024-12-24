https://contest.yandex.ru/contest/24414/run-report/114090806/

/*
-- ПРИНЦИП РАБОТЫ --
На первом этапе составляется словарь уникальных слов, которые встречаются в документах. В словаре храним индекс документа и частоту вхождения данного слова в документ.
Словарь реализован как хэш таблица, где ключом является слово, а значение - это еще одна хэш таблица, хранящая пару индекс документа - частота вхождеия слова.
При обработке каждого из запросов проверяем наличие данного слова в словаре и рассчитываем релевантность документа как сумму числа вхождеий каждого уникального слова из запроса в документ.
Результат представляет собой вектор, содержащий релевантность каждого документа.
Результирующий вектор сортируем по убыванию релевантности и отображаем первые пять результатов.


N - слов в документах
K - слов в запросах
L - число документов
M - число запросов

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Добавление в словарь слов и проверка/расчет вхождений  - О(N*L), в словарь запросов - О(К*M), сортировка результирующего вектора - О(Llog5).
Результирующая сложность будет равна сумме этих величин - О(N*L) + О(К*M) + О(Llog5)

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Словарь слов - О(N*L), словарь запросов - О(К*M)), результирующий вектор - О(L), вектор индексов документов - О(L), суммарно - О(N*L) + О(К*M) + 2*О(L)
*/


#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


using namespace std;

int main()
{
    int docCount;
    cin >> docCount;

    string line;
    getline(cin, line, '\n');

    unordered_map <string, unordered_map<int, int>> dictionary;

    for (int i = 0; i < docCount; i++)
    {
        string inputLine;
        getline(cin, inputLine, '\n');

        stringstream streamLine;
        streamLine << inputLine;

        while (!streamLine.eof())
        {
            string word;
            streamLine >> word;
            if (dictionary.contains(word))
                ++dictionary[word][i];
            else
                dictionary[word][i] = 1;
        }
    }

    int requestCount;
    cin >> requestCount;

    string line_;
    getline(cin, line_, '\n');

    for (int j = 0; j < requestCount; j++)
    {
        string inputLine;
        getline(cin, inputLine, '\n');

        stringstream streamLine;
        streamLine << inputLine;

        set<string> request;
        vector<int> result(docCount,0);

        while (!streamLine.eof())
        {
            string word;
            streamLine >> word;

            if (request.contains(word))
            {
                continue;
            }

            if (dictionary.contains(word))
            {
                for (const auto & [docIndex, wordRelevance] : dictionary[word])
                {
                    result[docIndex] += wordRelevance;
                }
            }

            request.insert(word);
        }

        vector<int> indexVec (docCount, 0);
        for (int i = 0; i < docCount; ++i)
            indexVec[i] = i;

        partial_sort(indexVec.begin(), indexVec.begin() + min(docCount, 5), indexVec.end(), [&result](int lhs, int rhs)
             {
                 if (result[lhs] == result[rhs])
                     return lhs < rhs;
                 return result[lhs] > result[rhs];});

        for (int i = 0;
             i < 5 &&
             result[indexVec[i]] > 0 &&
             i < result.size();
             i++)
            cout << indexVec[i] + 1 << " ";

        cout << "\n";
    }

    return 0;
}

