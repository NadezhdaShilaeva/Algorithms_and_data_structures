// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int height_node(vector<int>& parent, int node, int height)
{
    if (parent[node] == 0)
    {
        return height;
    }
    height_node(parent, parent[node], height + 1);
}

int main()
{
    ifstream file_in("height.in");
    ofstream file_out("height.out");
    int i, n, height = 0, max_height = 0;
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
        if (left[i] == 0 and right[i] == 0)
        {
            height = height_node(parent, i, 1);
            if (height > max_height)
            {
                max_height = height;
            }
        }
    }
    file_out << max_height;
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
