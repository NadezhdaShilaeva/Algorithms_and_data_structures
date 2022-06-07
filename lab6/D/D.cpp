// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int m = 100003, m2 = 99991, p = 53;
string null = "0", deleted = "1";
vector<int> p_pow(20);

ofstream file_out("multimap.out");

struct node
{
    string key;
    node* left;
    node* right;
    node* parent;
};

void insert_node(node*&, node*&);
node* tree_search(node*, string);
node* tree_minimum(node*);
node* tree_maximum(node*);
void moving_node(node*&, node*&, node*&);
void delete_node(node*&, node*);
void tree_walk(node*, vector<string>&);

int get_hash(string);
int hash_function(int, int);
bool hash_exists_val(vector<pair<string, node*>>& map, int, string);
void hash_put(vector<pair<string, node*>>& map, string, string, int);
int hash_get_key(vector<pair<string, node*>>& map, string, int);
void hash_get(vector<pair<string, node*>>& map, string, int);
void hash_delete(vector<pair<string, node*>>& map, string, string, int);
void hash_deleteall(vector<pair<string, node*>>& map, string, int);

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

node* tree_search(node* ptr, string key)
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
    while (ptr != nullptr and ptr->right != nullptr)
    {
        ptr = ptr->right;
    }
    return ptr;
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

void tree_walk(node* ptr, vector<string>& values)
{
    values.push_back(ptr->key);
    if (ptr->left != nullptr)
    {
        tree_walk(ptr->left, values);
    }
    if (ptr->right != nullptr)
    {
        tree_walk(ptr->right, values);
    }
}



int get_hash(string x)
{
    int hash = 0;
    for (int j = 0; j < x.size(); ++j)
    {
        hash = (hash + (x[j] - 'A') * p_pow[j] % m) % m;
    }
    return hash;
}

int hash_function(int hash, int i)
{
    return (hash + i * (1 + hash % m2)) % m;
}

bool hash_exists_val(vector<pair<string, node*>>& map, int idx, string y)
{
    node* root = map[idx].second;
    if (tree_search(root, y) == nullptr)
        return false;
    else
        return true;
}

void hash_put(vector<pair<string, node*>>& map, string x, string y, int hash)
{
    int idx = hash_get_key(map, x, hash);
    if (idx != -1)
    {
        if (hash_exists_val(map, idx, y))
            return;
        node* new_node = new node;
        new_node->key = y;
        new_node->left = nullptr;
        new_node->right = nullptr;
        insert_node(map[idx].second, new_node);
        return;
    }
    for (int i = 0; i != m; ++i)
    {
        int j = hash_function(hash, i);
        if (map[j].first == null or map[j].first == deleted)
        {
            map[j].first = x;
            node* new_node = new node;
            new_node->key = y;
            new_node->left = nullptr;
            new_node->right = nullptr;
            new_node->parent = nullptr;
            map[j].second = new_node;
            return;
        }
    }
}

int hash_get_key(vector<pair<string, node*>>& map, string x, int hash)
{
    for (int i = 0; i != m; ++i)
    {
        int j = hash_function(hash, i);
        if (map[j].first == x)
        {
            return j;
        }
        if (map[j].first == null)
        {
            return -1;;
        }
    }
    return -1;
}

void hash_get(vector<pair<string, node*>>& map, string x, int hash)
{
    int idx = hash_get_key(map, x, hash);
    if (idx == -1)
    {
        file_out << 0 << endl;
        return;
    }
    vector<string> values;
    node* root = map[idx].second;
    tree_walk(root, values);
    file_out << values.size() << ' ';
    for (int i = 0; i < values.size(); ++i)
    {
        file_out << values[i] << ' ';
    }
    file_out << endl;
}

void hash_delete(vector<pair<string, node*>>& map, string x, string y, int hash)
{
    int idx = hash_get_key(map, x, hash);
    if (idx == -1)
        return;
    else
    {
        node* root = map[idx].second;
        if (tree_search(root, y) != nullptr)
        {
            delete_node(map[idx].second, tree_search(root, y));
        }
        if (map[idx].second == nullptr)
        {
            map[idx].first = deleted;
        }
    }
}

void hash_deleteall(vector<pair<string, node*>>& map, string x, int hash)
{
    int idx = hash_get_key(map, x, hash);
    if (idx == -1)
        return;
    map[idx].first = deleted;
    map[idx].second = nullptr;
}

int main()
{
    ifstream file_in("multimap.in");
    vector<pair<string, node*>> map(m, { null, nullptr });
    string operation, x, y;
    p_pow[0] = 1;
    for (int i = 1; i < 20; ++i)
    {
        p_pow[i] = p_pow[i - 1] * p % m;
    }
    while (file_in >> operation)
    {
        file_in >> x;
        int hash = get_hash(x);
        if (operation == "put")
        {
            file_in >> y;
            hash_put(map, x, y, hash);
        }
        if (operation == "get")
        {
            hash_get(map, x, hash);
        }
        if (operation == "delete")
        {
            file_in >> y;
            hash_delete(map, x, y, hash);
        }
        if (operation == "deleteall")
        {
            hash_deleteall(map, x, hash);
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
