https://contest.yandex.ru/contest/24414/run-report/114042818/

/*
-- ПРИНЦИП РАБОТЫ --
Хэш таблица с целочисленными ключами была реализована с помощью массива. Для разрешения коллизий используется метод цепочек, который реализован на основе связного списка.
Для удаления ключа, добавления и получения значения по ключу номер корзины(индекс элемента в массиве) рассчитывается методом деления.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Вставка в массив по индексу выполняется за O(1), соответственно в среднем операции с хэш таблицей так же будут выполняться в среднем за O(1).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Помимо памяти, выделенной под массив для хранения таблицы O(N), где N - максимальное количество ключей в хэш-таблице (наиболее близкое простое число), будет задействована память
для хранения данных в случае коллизий. В худшем случае это О(N/2). Суммарно:  О(N) +  О(N/2)
*/



#include <cstdint>
#include <iostream>
#include <vector>

#define bucket_size 100003


using namespace std;


class SelfMadeMap {
public:
    SelfMadeMap()
    { items = new Node*[bucket_size]; }

private:
    class Node{
    public:

        int key;
        int  value;
        Node* next;

        Node(){ }

        Node(int _key, int _value)
        {
            this->key = _key;
            this->value = _value;
            this->next = NULL;
        }
    };

    Node** items;

    int hashFunction(int key)
    { return (key % bucket_size + bucket_size) % bucket_size; }

public:
    void put(int key, int value)
    {
        int index = this->hashFunction(key);

        if(items[index] == NULL)
        {
            Node* item = new Node(key, value);
            items[index] = item;
        }
        else
        {
            Node* item = items[index];

            while (item->next != NULL && item->key != key)
                item = item->next;

            if (item->key == key)
                item->value = value;
            else
            {
                Node* newItem = new Node(key, value);
                newItem->next = items[index];
                items[index] = newItem;
            }
        }
    }

    void get(int key)
    {
        int index = this->hashFunction(key);

        if(items[index] == NULL)
            cout << "None" << "\n";
        else
        {
            Node* item = items[index];

            if (item->key == key)
            {
                cout << item->value << "\n";
                return;
            }

            while (item->next != NULL && item->key != key)
                item = item->next;

            if (item->key == key)
                cout << item->value << "\n";
            else
                cout << "None" << "\n";
        }
    }

    void erase(int key)
    {
        int index = this->hashFunction(key);

        if(items[index] == NULL)
            cout << "None" << "\n";
        else
        {
            Node* item = items[index];

            if (item->key == key)
            {
                cout << item->value << "\n";
                items[index] = item->next;
                delete item;
                return;
            }

            Node* prev;

            while (item->next != NULL && item->key != key)
            {
                prev = item;
                item = item->next;
            }

            if (item->key == key)
            {
                cout << item->value << "\n";
                prev->next = item->next;
                delete item;
            }
            else
                cout << "None" << "\n";
        }
    }
};

int main()
{
    SelfMadeMap map;

    int commandCount;
    cin >> commandCount;

    for (int i = 0; i < commandCount; ++i)
    {
        string commandName;
        cin >> commandName;

        int key;

        if (commandName == "get")
        {
            cin >> key;
            map.get(key);
        }
        else if (commandName == "delete")
        {
            cin >> key;
            map.erase(key);
        }
        else if (commandName == "put")
        {
            cin >> key;
            int value;
            cin >> value;

            map.put(key, value);
        }
    }

    return 0;
}
