https://contest.yandex.ru/contest/25597/run-report/115990158/

/*
-- ПРИНЦИП РАБОТЫ --
Для решения задачи используется метод динамического программирования. В dp[j] храним информацию о том, можем ли мы получить сумму j,
используя любые подмножества из данных очков(scores). Искомое значение будет записано в ячейке dp[summ].

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Так как в алгоритме используются два вложенных цикла, то сложность алгоритма составит O(summ * N),где summ - сумма очков после разбиения, а N - количество партий.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для хранения массива dp выделяем O(summ) памяти.
*/



#include <iostream>
#include <vector>



using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> scores(n);
    int summ = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> scores[i];
        summ += scores[i];
    }

    if (summ % 2 != 0)
        cout << "False";
    else
    {
        summ = summ / 2;

        vector<bool> dp(summ + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i)
        {
            for (int j = summ; j >= scores[i]; --j)
            {
                dp[j] = dp[j] || dp[j - scores[i]];
            }

            if(dp[summ])
                break;
        }

        if (dp[summ])
            cout << "True";
        else
            cout << "False";
    }

    return 0;
}
