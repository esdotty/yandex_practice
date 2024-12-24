https://contest.yandex.ru/contest/25597/run-report/116018726/

/*
-- ПРИНЦИП РАБОТЫ --
Для поиска расстояния Левенштейна для двух строк был использован алгоритм Вагнера-Фишера (https://ru.wikipedia.org/wiki/%D0%A0%D0%B0%D1%81%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%B8%D0%B5_%D0%9B%D0%B5%D0%B2%D0%B5%D0%BD%D1%88%D1%82%D0%B5%D0%B9%D0%BD%D0%B0#%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%92%D0%B0%D0%B3%D0%BD%D0%B5%D1%80%D0%B0_%E2%80%94_%D0%A4%D0%B8%D1%88%D0%B5%D1%80%D0%B0)
идея, которого заключается в том, чтобы вычислить матрицу dp, таким образом, что dp[i][j] - минимально возможная "цена" изменения,
производимого над строкой (вставка, замена или удаление).
Искомое значение будет содержаться в ячейке dp[N][M] матрицы.
Для расчетов нам достаточно хранить две строки текущую и предыдущую этой матрицы, что существенно сократит задействованную память.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Так как в алгоритме используются два вложенных цикла, то сложность алгоритма составит O(M * N),где M и N длины строк.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для хранения двух строк матрицы использованы два одномерных вектора, соответственно выделяем O(2 * N) памяти.
*/



#include <algorithm>
#include <iostream>
#include <string>
#include <vector>



using namespace std;

int main()
{
    string s;
    getline(cin, s, '\n');

    string t;
    getline(cin, t, '\n');

    int m = s.length();
    int n = t.length();

    if (m == 0)
        return n;

    if (n == 0)
        return m;

    vector<int> prev(n + 1, 0);
    vector<int> current(n + 1, 0);

    for (int j = 0; j <= n; j++)
        prev[j] = j;

    for (int i = 1; i <= m; i++)
    {
        current[0] = i;

        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                current[j] = prev[j - 1];
            }
            else
            {
                current[j] = 1 + min(current[j - 1], min(prev[j], prev[j - 1]));
            }
        }

        prev.swap(current);
    }

    cout << prev[n];

    return 0;
}
