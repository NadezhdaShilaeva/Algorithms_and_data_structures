// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
    node* parent;
};

void insert_node(node*& root, node*& new_node)
{
    node* ptr_parent = nullptr;
    node* ptr = root;
    while (ptr != nullptr)
    {
        ptr_parent = ptr;
        if (new_node->key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    new_node->parent = ptr_parent;
    if (ptr_parent == nullptr)
    {
        root = new_node;
    }
    else
    {
        if (new_node->key < ptr_parent->key)
        {
            ptr_parent->left = new_node;
        }
        else
        {
            ptr_parent->right = new_node;
        }
    }
}

node* tree_search(node* ptr, int key)
{
    while (ptr != nullptr and key != ptr->key)
    {
        if (key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return ptr;
}

node* tree_search_before(node* ptr, int key)
{
    node* ptr_parent = nullptr;
    while (ptr != nullptr and key != ptr->key)
    {
        ptr_parent = ptr;
        if (key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return ptr_parent;
}

node* tree_minimum(node* ptr)
{
    while (ptr != nullptr and ptr->left != nullptr)
    {
        ptr = ptr->left;
    }
    return ptr;
}

node* tree_maximum(node* ptr)
{
    while (ptr!= nullptr and ptr->right != nullptr)
    {
        ptr = ptr->right;
    }
    return ptr;
}

node* next_node(node* ptr)
{
    if (ptr->right != nullptr)
    {
        return tree_minimum(ptr->right);
    }
    node* ptr_parent = ptr->parent;
    while (ptr_parent != nullptr and ptr == ptr_parent->right)
    {
        ptr = ptr_parent;
        ptr_parent = ptr_parent->parent;
    }
    return ptr_parent;
}

node* prev_node(node* ptr)
{
    if (ptr->left != nullptr)
    {
        return tree_maximum(ptr->left);
    }
    node* ptr_parent = ptr->parent;
    while (ptr_parent != nullptr and ptr == ptr_parent->left)
    {
        ptr = ptr_parent;
        ptr_parent = ptr_parent->parent;
    }
    return ptr_parent;
}

void moving_node(node*& root, node*& ptr1, node*& ptr2)
{
    if (ptr1->parent == nullptr)
    {
        root = ptr2;
    }
    else
    {
        if (ptr1 == ptr1->parent->left)
        {
            ptr1->parent->left = ptr2;
        }
        else
        {
            ptr1->parent->right = ptr2;
        }
    }
    if (ptr2 != nullptr)
    {
        ptr2->parent = ptr1->parent;
    }
}

void delete_node(node*& root, node* del_node)
{
    if (del_node->left == nullptr)
    {
        moving_node(root, del_node, del_node->right);
    }
    else
    {
        if (del_node->right == nullptr)
        {
            moving_node(root, del_node, del_node->left);
        }
        else
        {
            node* ptr = tree_minimum(del_node->right);
            if (ptr->parent != del_node)
            {
                moving_node(root, ptr, ptr->right);
                ptr->right = del_node->right;
                ptr->right->parent = ptr;
            }
            moving_node(root, del_node, ptr);
            ptr->left = del_node->left;
            ptr->left->parent = ptr;
        }
    }
}

int main()
{
    ifstream file_in("bstsimple.in");
    ofstream file_out("bstsimple.out");
    string operation;
    int x;
    node* root = nullptr;
    while (file_in >> operation)
    {
        file_in >> x;
        if (operation == "insert")
        {
            if (tree_search(root, x) == nullptr)
            {
                node* new_node = new node;
                new_node->key = x;
                new_node->left = nullptr;
                new_node->right = nullptr;
                insert_node(root, new_node);
            }
        }
        if (operation == "delete")
        {
            if (tree_search(root, x) != nullptr)
            {
                delete_node(root, tree_search(root, x));
            }
        }
        if (operation == "exists")
        {
            if (tree_search(root, x) != nullptr)
            {
                file_out << "true" << endl;
            }
            else
            {
                file_out << "false" << endl;
            }
        }
        if (operation == "next")
        {
            node* node_x = tree_search(root, x);
            if (node_x != nullptr)
            {
                if (next_node(node_x) == nullptr)
                {
                    file_out << "none" << endl;
                }
                else
                {
                    file_out << next_node(node_x)->key << endl;
                }
            }
            else
            {
                if (root == nullptr or x > tree_maximum(root)->key)
                {
                    file_out << "none" << endl;
                }
                else
                {
                    node* before_x = tree_search_before(root, x);
                    if (before_x->key < x)
                    {
                        file_out << next_node(before_x)->key << endl;
                    }
                    else
                    {
                        file_out << before_x->key << endl;
                    }
                }
            }
        }
        if (operation == "prev")
        {
            node* node_x = tree_search(root, x);
            if (node_x != nullptr)
            {
                if (prev_node(node_x) == nullptr)
                {
                    file_out << "none" << endl;
                }
                else
                {
                    file_out << prev_node(node_x)->key << endl;
                }
            }
            else
            {
                if (root == nullptr or x < tree_minimum(root)->key)
                {
                    file_out << "none" << endl;
                }
                else
                {
                    node* before_x = tree_search_before(root, x);
                    if (before_x->key > x)
                    {
                        file_out << prev_node(before_x)->key << endl;
                    }
                    else
                    {
                        file_out << before_x->key << endl;
                    }
                }
            }
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
