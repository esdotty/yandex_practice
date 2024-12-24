https://contest.yandex.ru/contest/24810/run-report/114698128/

/*
-- ПРИНЦИП РАБОТЫ --
Для удаления вершины из бинарного дерева поиска:
проверяем найдена ли вершина, если нет возвращаем nullptr. Определяем в левом или правои поддереве находится вершина. После того как вершина найдена
определяем является ли она листом,
имеет одного потомка (парвого или левого) или двух потомков. Если вершина имеет двух потомков, то находим максисмум в левом поддереве, эта вершина
объединит распадающиеся поддеревья. Заменяем ей удаленную.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Сложность удаления вершины - О(h) и обусловлена глубиной рекурсивного вызова;
h - высота дерева

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Так как при реализации была использована рекурсия, глубина которой составляет O(h), то задействуется O(h) дополнительной памяти.
В хужшем случае это - O(n), в лучшем  - O(logn). n - число вершин
*/



#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>
#include <stack>

Node* remove(Node* root, int key){
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->value)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->value)
    {
        root->right = remove(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;

        }
        else if (root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = root->left;

            while (temp->right != nullptr)
            {
                temp = temp->right;
            }

            root->value = temp->value;

            root->left = remove(root->left, temp->value);
        }
    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({nullptr, nullptr, 2});
    Node node2({&node1, nullptr, 3});
    Node node3({nullptr, &node2, 1});
    Node node4({nullptr, nullptr, 6});
    Node node5({&node4, nullptr, 8});
    Node node6({&node5, nullptr, 10});
    Node node7({&node3, &node6, 5});
    Node* newHead = remove(&node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == &node5);
    assert(newHead->right->value == 8);
}

int main() {
    test();
}
#endif
