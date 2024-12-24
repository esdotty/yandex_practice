https://contest.yandex.ru/contest/26133/run-report/116193464/

/*
-- ПРИНЦИП РАБОТЫ --
Для решения задачи используется метод динамического программирования. В dp[i] храним информацию о том, является ли какое-нибудь слово из набора суффиксом текущий подстроки
при условии, что начало подстроки так же можно разбить на слова из набора.
Искомое значение будет записано в ячейке dp[n], где n - длина искомого текста для разбиения.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Так как в алгоритме используются два вложенных цикла, то сложность алгоритма составит O(n * m),где m - количество уникальных слов в наборе.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для хранения массива dp выделяем O(n) памяти.
*/



#include <iostream>
#include <set>
#include <string>
#include <stdint.h>
#include <vector>



using namespace std;

int main()
{
    string line;
    cin >> line;

    int count;
    cin >> count;

    set<string> words;

    for (int i = 0; i < count; ++i)
    {
        string word;
        cin >> word;

        words.insert(word);
    }

    int n = line.length();
    vector<uint8_t> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (auto word : words)
        {
            int len = word.length();

            if(i >=len && line.substr(i - len, len) == word && dp[i - len] == 1)
            {
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[n] == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
