https://contest.yandex.ru/contest/22450/run-report/106396829/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int dataSize;
    cin >> dataSize;

    vector<int> data(dataSize);
    int position = -1;

    for (int i = 0; i < dataSize; ++i)
    {
        cin >> data[i];
        if(data[i] == 0)
            position = i;
        else
        {
            if (position >= 0)
                data[i] = i - position;
            else
                data[i] = dataSize - i - 1;
        }
    }

    position = -1;

    for (int i = dataSize - 1; i >= 0; --i)
    {
        if(data[i] == 0)
            position = i;
        else
        {
            if(position == -1)
                continue;
            else if(data[i] > (position - i))
                data[i] = position - i;
        }
    }

    for (int dist : data)
        cout << dist << " ";
}
