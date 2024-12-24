https://contest.yandex.ru/contest/26133/run-report/116193464/

/*
-- ПРИНЦИП РАБОТЫ --
Для решения задачи был использован наивный алгоритм. Каждый раз при извлечении из буфера слова и его распаковки обновляем текущее значение общего префикса,
сравнивая префикс и слово посимвольно.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Для поиска общего префикса мы единожды проходимся по набору слов, соответвенно алгоритма составит O(m),где m - количество запакованных слов.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Для распаковки слов была использована рекурсия, глубина которой в худшем случае равна примерно n/2,
где  n - длина запакованного слова. Т.е. будет задействовано О(n/2) дополнительной памяти.
*/



#include <iostream>
#include <string>



        using namespace std;

std::string unpack(const std::string& s, int& index)
{
    std::string result;

    while (index < s.size() && s[index] != ']')
    {
        if (std::isdigit(s[index]))
        {
            int repeat_count = s[index] - '0';
            index += 2;
            std::string substring = unpack(s, index);
            index++;
            for (int i = 0; i < repeat_count; ++i)
            {
                result.append(substring);
            }
        }
        else
        {
            result.push_back(s[index++]);
        }
    }

    return result;
}

string unpackString(const string& s, size_t prefixSize)
{
    int index = 0;
    std::string result;

    while (index < s.size() && index < prefixSize)
    {
        result.append(unpack(s, index));
    }

    return result;
}


int main()
{
    int count;
    cin >> count;
    cin.ignore();

    string prefix;
    getline(cin, prefix);
    prefix = unpackString(prefix, prefix.size());

    for (int i = 0; i < count - 1; ++i)
    {
        string word;
        getline(cin, word);

        word = unpackString(word, prefix.size());

        size_t index = 0;

        while (index < prefix.size() && index < word.size() && prefix[index] == word[index])
        {
            ++index;
        }
        prefix.resize(index);

        if (prefix.empty())
        {
            break;
        }
    }

    cout << prefix;

    return 0;
}
