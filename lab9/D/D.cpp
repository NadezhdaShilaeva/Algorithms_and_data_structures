// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int components = 0;

void dfs(int start, vector<bool>& vis, vector<vector<int>>& graph, vector<int>& topologic)
{
    vis[start] = 1;
    for (auto v : graph[start])
    {
        if (!vis[v])
        {
            dfs(v, vis, graph, topologic);
        }
    }
    topologic.push_back(start);
}

void dfs_tr(int start, vector<int>& ver_comp, vector<vector<int>>& graph_tr)
{
    ver_comp[start] = components;
    for (auto v : graph_tr[start])
    {
        if (ver_comp[v] == 0)
        {
            dfs_tr(v, ver_comp, graph_tr);
        }
    }
}

int main()
{
    ifstream file_in("cond.in");
    ofstream file_out("cond.out");
    int n, m, v1, v2;
    file_in >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> graph_tr(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> topologic;
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2;
        graph[v1].push_back(v2);
        graph_tr[v2].push_back(v1);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(i, vis, graph, topologic);
        }
    }
    vector<int> ver_comp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        if (ver_comp[topologic[i]] == 0)
        {
            ++components;
            dfs_tr(topologic[i], ver_comp, graph_tr);
        }
    }
    file_out << components << endl;
    for (int i = 1; i <= n; ++i)
    {
        file_out << ver_comp[i] << " ";
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
