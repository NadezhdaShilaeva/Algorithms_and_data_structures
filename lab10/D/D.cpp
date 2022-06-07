// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

const int INF = 1000000001;
int root = 0;
long long result = 0;

void dfs(int start, vector<vector<pair<int, int>>>* graph, vector<bool>& vis, bool zero_weight)
{
    vis[start] = true;
    for (auto& u : (*graph)[start])
    {
        if (!vis[u.first] and (u.second == 0 or !zero_weight))
        {
            dfs(u.first, graph, vis, zero_weight);
        }
    }
}

void dfs_path(int start, vector<vector<pair<int, int>>>* graph, vector<bool>& vis, list<int>& path)
{
    vis[start] = true;
    for (auto& u : (*graph)[start])
    {
        if (!vis[u.first] and u.second == 0)
        {
            dfs_path(u.first, graph, vis, path);
        }
    }
    path.push_front(start);
}

vector<vector<pair<int, int>>>* reverse_graph(vector<vector<pair<int, int>>>* graph)
{
    vector<vector<pair<int, int>>>* rev_graph = new vector<vector<pair<int, int>>>(graph->size());
    for (int v1 = 0; v1 < graph->size(); ++v1)
    {
        for (auto& v2 : (*graph)[v1])
        {
            (*rev_graph)[v2.first].push_back({ v1, v2.second });
        }
    }
    return rev_graph;
}

void make_comp(int v1, int color, vector<vector<pair<int, int>>>* graph, vector<int>& colors)
{
    colors[v1] = color;
    for (auto& v2 : (*graph)[v1])
    {
        if (colors[v2.first] == -1 and v2.second == 0)
        {
            make_comp(v2.first, color, graph, colors);
        }
    }
}

vector<vector<pair<int, int>>>* condensation(vector<vector<pair<int, int>>>* rev_graph)
{
    vector<bool> vis(rev_graph->size(), false);
    list<int> path;
    for (int i = 0; i < rev_graph->size(); ++i)
    {
        if (!vis[i])
        {
            dfs_path(i, rev_graph, vis, path);
        }
    }
    vector<vector<pair<int, int>>>* graph = reverse_graph(rev_graph);
    vector<int> colors(graph->size(), -1);
    int color = 0;
    for (auto& v : path)
    {
        if (colors[v] == -1)
        {
            make_comp(v, color, graph, colors);
            ++color;
        }
    }
    delete graph;
    root = colors[root];
    vector<vector<pair<int, int>>>* new_graph = new vector<vector<pair<int, int>>>(color);
    for (int v1 = 0; v1 < rev_graph->size(); ++v1)
    {
        for (auto& v2 : (*rev_graph)[v1])
        {
            if (colors[v1] != colors[v2.first])
            {
                (*new_graph)[colors[v1]].push_back({ colors[v2.first], v2.second });
            }
        }
    }
    return new_graph;
}

void find_mst(vector<vector<pair<int, int>>>* rev_graph)
{
    int v;
    for (v = 0; v < rev_graph->size(); ++v)
    {
        int min_edge = INF;
        for (auto& u : (*rev_graph)[v])
        {
            min_edge = min(min_edge, u.second);
        }
        for (auto& u : (*rev_graph)[v])
        {
            u.second -= min_edge;
        }
        if (v != root)
        {
            result += min_edge;
        }
    }
    vector<vector<pair<int, int>>>* graph = reverse_graph(rev_graph);
    vector<bool> vis(graph->size(), false);
    dfs(root, graph, vis, true);
    delete graph;
    for (v = 0; v < rev_graph->size(); ++v)
    {
        if (!vis[v])
        {
            break;
        }
    }
    if (v == rev_graph->size())
    {
        return;
    }
    vector<vector<pair<int, int>>>* new_graph = condensation(rev_graph);
    //delete rev_graph;
    find_mst(new_graph);
    //delete new_graph;
}

int main()
{
    ifstream file_in("chinese.in");
    ofstream file_out("chinese.out");
    int n, m;
    file_in >> n >> m;
    vector<vector<pair<int, int>>>* graph = new vector<vector<pair<int, int>>>(n);
    int v1, v2, weight;
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2 >> weight;
        (*graph)[v1 - 1].push_back({ v2 - 1, weight });
    }
    vector<bool> vis(n, false);
    dfs(root, graph, vis, false);
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            file_out << "NO" << endl;
            return 0;
        }
    }
    file_out << "YES" << endl;
    vector<vector<pair<int, int>>>* rev_graph = reverse_graph(graph);
    delete graph;
    find_mst(rev_graph);
    file_out << result;
    return 0;
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
/* 5 8
1 2 5
1 3 5
3 2 2
2 4 1
4 2 1
3 5 1
5 3 1
4 5 2*/