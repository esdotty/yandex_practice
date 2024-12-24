https://contest.yandex.ru/contest/25070/run-report/115508616/

/*
-- ПРИНЦИП РАБОТЫ --
Для поиска максимального остового дерева был использован алгоритм Прима с приоритетной очередью с поддержанием максимума, чтобы выбирать ребро
с максимальным весом было легко.
(https://practicum.yandex.ru/learn/algorithms/courses/5fe6b1ba-aaeb-43ee-81a4-86285d571e65/sprints/275306/topics/6ac39b36-1ef5-415f-a016-ba9a28159c24/lessons/10af9290-9ef2-4b02-bf1d-8f4deb892b7f/)

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Сложность алгоритма Прима с использованием приоритетной очереди  O(ЕlogV), где Е - число ребер, а V - число вершин.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для хранения списка смежности выделяем O(V + Е) памяти, для хранения добавленных вершин - O(V), в приоритетной очереди может хранится в худшем случае О(Е) ребер.
*/



#include <iostream>
#include <stdint.h>
#include <queue>
#include <vector>


        using namespace std;

struct Edge {
    int to;
    int weight;
};


int findMaxST(int count, vector<vector<Edge>>& vertex)
{
    vector<uint8_t> addedVertex(count + 1, 0);

    priority_queue<pair<int, int>> pq;

    int start = 1;
    pq.push({0, start});
    int maxWeightSum = 0;

    while (!pq.empty())
    {
        auto [weight, u] = pq.top();
        pq.pop();

        if (addedVertex[u] == 1)
            continue;
        addedVertex[u] = 1;
        maxWeightSum += weight;

        for (const auto& edge : vertex[u])
        {
            if (addedVertex[edge.to] == 0)
            {
                pq.push({edge.weight, edge.to});
            }
        }
    }

    for (int i = 1; i < count + 1; ++i)
    {
        if (addedVertex[i] == 0)
        {
            maxWeightSum = 0;
            break;
        }
    }

    return maxWeightSum;
}


int main()
{
    int vertexCount;
    cin >> vertexCount;

    int edgesCount;
    cin >> edgesCount;

    vector<vector<Edge>> vertex(vertexCount + 1);

    for (int i = 0; i < edgesCount; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        vertex[u].push_back({v, w});
        vertex[v].push_back({u, w});
    }

    if (vertexCount == 1)
        cout << "0";
    else
    {

        int MaxWeightSumm = findMaxST(vertexCount, vertex);

        if (MaxWeightSumm == 0)
            cout << "Oops! I did it again";
        else
            cout << MaxWeightSumm;
    }

    return 0;
}
