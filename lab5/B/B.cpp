// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void binary_tree_check(vector<int>& key, vector<int>& left, vector<int>& right, int node, bool& binary_tree, int min_key, int max_key)
{
    if (key[node] <= min_key or key[node] >= max_key)
    {
        binary_tree = false;
    }
    if (!binary_tree)
    {
        return;
    }
    if (left[node] != 0)
    {
        binary_tree_check(key, left, right, left[node], binary_tree, min_key, key[node]);
    }
    if (right[node] != 0)
    {
        binary_tree_check(key, left, right, right[node], binary_tree, key[node], max_key);
    }
}

int main()
{
    ifstream file_in("check.in");
    ofstream file_out("check.out");
    int i, n;
    bool binary_tree = true;
    file_in >> n;
    vector<int> key(n + 1), left(n + 1), right(n + 1), parent(n + 1, 0);
    for (i = 1; i <= n; ++i)
    {
        file_in >> key[i] >> left[i] >> right[i];
        parent[left[i]] = i;
        parent[right[i]] = i;
    }
    for (i = 1; i <= n; ++i)
    {
        if (parent[i] == 0)
        {
            binary_tree_check(key, left, right, i, binary_tree, -1000000001, 1000000001);
        }
    }
    if (binary_tree)
    {
        file_out << "YES";
    }
    else
    {
        file_out << "NO";
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
