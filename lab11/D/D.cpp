// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long INF = 5000000000000000001;

void dfs(int start, vector<vector<int>>& graph, vector<bool>& vis)
{
    vis[start] = true;
    for (auto v : graph[start])
    {
        if (!vis[v])
        {
            dfs(v, graph, vis);
        }
    }
}

int main()
{
    ifstream fin("path.in");
    ofstream fout("path.out");
    int n, m, start;
    fin >> n >> m >> start;
    vector<pair<pair<int, int>, long long>> edges(m);
    vector<vector<int>> graph(n + 1);
    vector<long long> dist(n + 1, INF);
    for (int i = 0; i < m; ++i)
    {
        fin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        graph[edges[i].first.first].push_back(edges[i].first.second);
    }
    dist[start] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        bool change = false;
        for (auto edge : edges)
        {
            int v1 = edge.first.first;
            int v2 = edge.first.second;
            long long weight = edge.second;
            if (dist[v1] < INF and dist[v1] + weight < dist[v2])
            {
                dist[v2] = max(-INF, dist[v1] + weight);
                change = true;
            }
        }
        if (!change)
        {
            break;
        }
    }
    vector<bool> vis(n + 1, false);
    for (auto edge : edges)
    {
        int v1 = edge.first.first;
        int v2 = edge.first.second;
        long long weight = edge.second;
        if (dist[v1] < INF and dist[v1] + weight < dist[v2] and !vis[v2])
        {
            dfs(v2, graph, vis);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == INF)
        {
            fout << '*' << endl;
        }
        else if (vis[i])
        {
            fout << '-' << endl;
        }
        else
        {
            fout << dist[i] << endl;
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
