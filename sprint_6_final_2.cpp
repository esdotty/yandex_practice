https://contest.yandex.ru/contest/25070/run-report/115492785/

/*
-- ПРИНЦИП РАБОТЫ --
Для определения является ли карта оптимальной сформируем матрицу смежности таким обрязом, чтобы задача свелась к нахождению цикла в графе.
Для этого "переворачиваем" ребра типа В в графе.
Далее для нахождения циклов в графе используем алгоритм DFS с использованием массива цветов как это было описано в уроке Практикума:
https://practicum.yandex.ru/learn/algorithms/courses/5fe6b1ba-aaeb-43ee-81a4-86285d571e65/sprints/275306/topics/6ac39b36-1ef5-415f-a016-ba9a28159c24/lessons/ed8be4aa-6b01-4a4a-954d-e31472c710e6/
Если цикл был найден, значит карта маршрутов не оптимальна.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Алгоритм DFS будет иметь сложность O(V*V), т.к. для нахождения соседних вершин нужно просмотреть целиком всю строку матрицы, соответствующую этой вершине, для каждой из V вершин.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для хранения матрицы смежности выделяем O(V*V) памяти, для хранения массива цветов задействуется O(V) дополнительной памяти и кроме того так как при реализации была использована рекурсия,
глубина которой составляет O(V), то задействуется O(V) дополнительной памяти.
*/



#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool dfs(int v, const vector<vector<int>>& vertex, vector<string>& color)
{
    color[v] = "gray";

    for (int i = 0; i < vertex.size(); ++i)
    {
        if (vertex[v][i] == 1)
        {
            if (color[i] == "white")
            {
                if (!dfs(i, vertex, color))
                    return false;
            }
            else if (color[i] == "gray")
            {
                return false;
            }
        }
    }

    color[v] = "black";

    return true;
}

bool findLoop(const vector<vector<int>>& vertex)
{
    vector<string> color(vertex.size(), "white");

    for (int i = 0; i < vertex.size(); ++i)
    {
        if (color[i] == "white")
        {
            if (!dfs(i, vertex, color))
                return false;
        }
    }

    return true;
}

int main()
{
    int townCount;
    cin >> townCount;

    vector<vector<int>> vertex(townCount, vector<int>(townCount, 0));

    for (int i = 0; i < townCount - 1; ++i)
    {
        string line;
        cin >> line;

        for (int j = 0; j < line.size(); ++j)
        {
            if (line[j] == 'B')
                vertex[i + j + 1][i] = 1;
            else
                vertex[i][i + j + 1] = 1;
        }
    }

    if (findLoop(vertex))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
