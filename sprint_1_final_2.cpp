https://contest.yandex.ru/contest/22450/run-report/106901788/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr(9,0);
    string data;
    int winScore = 0;

    int k;
    cin >> k;

    for (int i = 0; i < 4; ++i)
    {
        cin >> data;
        for (int j = 0; j < 4; ++j)
        {
            if(data[j] == '.')
                continue;
            else
                ++arr[data[j] - '0' - 1];
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        if (arr[i] > 0 && 2*k >= arr[i])
            ++winScore;
    }

    cout << winScore;
}
