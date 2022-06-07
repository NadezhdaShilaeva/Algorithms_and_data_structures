// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int get(int start, vector<int>& parent)
{
    int root = start;
    while (parent[root] != root)
    {
        root = parent[root];
    }
    int i = start;
    while (parent[i] != i)
    {
        int j = parent[i];
        parent[i] = root;
        i = j;
    }
    return root;
}

void union_sets(int first, int second, vector<int>& parent, vector<int>& rang)
{
    first = get(first, parent);
    second = get(second, parent);
    if (first == second)
    {
        return;
    }
    if (rang[first] == rang[second])
    {
        ++rang[first];
    }
    if (rang[first] > rang[second])
    {
        parent[second] = first;
    }
    else
    {
        parent[first] = second;
    }
}

int main()
{
    ifstream file_in("spantree3.in");
    ofstream file_out("spantree3.out");
    int n, m;
    file_in >> n >> m;
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        file_in >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    long long mst = 0;
    vector<int> parent(n + 1), rang(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    for (auto edge : edges)
    {
        if (get(edge.second.first, parent) != get(edge.second.second, parent))
        {
            mst += edge.first;
            union_sets(edge.second.first, edge.second.second, parent, rang);
        }
    }
    file_out << mst;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"+
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
