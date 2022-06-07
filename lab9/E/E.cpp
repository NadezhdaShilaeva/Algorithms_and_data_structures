// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n;

bool hamilton_dfs(int start, vector<vector<int>>& graph, vector<vector<int>>& graph_tr, vector<bool>& vis, vector<int>& path)
{
    for (auto v : graph_tr[start])
    {
        if (!vis[v])
        {
            return false;
        }
    }
    path.push_back(start);
    if (path.size() == n)
    {
        return true;
    }
    vis[start] = true;
    for (int i = graph[start].size() - 1; i >= 0; --i)
    {
        if (!vis[graph[start][i]])
        {
            if (hamilton_dfs(graph[start][i], graph, graph_tr, vis, path))
            {
                return true;
            }
        }
    }
    vis[start] = false;
    path.pop_back();
    return false;
}

int main()
{
    ifstream file_in("hamiltonian.in");
    ofstream file_out("hamiltonian.out");
    int m, v1, v2;
    file_in >> n >> m;
    vector<vector<int>> graph(n + 1), graph_tr(n + 1);
    vector<bool> vis(n + 2, false);
    vector<int> deg_in(n + 1, 0);
    vector<int> deg_out(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2;
        graph[v1].push_back(v2);
        graph_tr[v2].push_back(v1);
        ++deg_in[v2];
        ++deg_out[v1];
    }
    bool hamilton = false;
    int nothing_in = 0, nothing_out = 0;
    int vertex_out = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (deg_in[i] == 0)
        {
            ++nothing_in;
            vertex_out = i;
        }
        if (deg_out[i] == 0)
        {
            ++nothing_out;
        }
    }
    if (nothing_in == 1 and nothing_out == 1)
    {
        vector<int> path;
        if (hamilton_dfs(vertex_out, graph, graph_tr, vis, path))
        {
            hamilton = true;
        }
    }
    if (hamilton)
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
