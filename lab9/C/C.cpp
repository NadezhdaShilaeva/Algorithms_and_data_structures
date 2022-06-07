// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool bipartite = true;

void dfs(int start, vector<int>& color, vector<vector<int>>& graph)
{
    for (auto v : graph[start])
    {
        if (color[v] == 0)
        {
            color[v] = 3 - color[start];
            dfs(v, color, graph);
        }
        else
        {
            if (color[v] == color[start])
            {
                bipartite = false;
            }
        }
    }
}

int main()
{
    ifstream file_in("bipartite.in");
    ofstream file_out("bipartite.out");
    int n, m, v1, v2;
    file_in >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, 0);
    vector<int> cycle_path;
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == 0)
        {
            color[i] = 1;
            dfs(i, color, graph);
        }
    }
    if (bipartite)
    {
        file_out << "YES" << endl;
    }
    else 
    {
        file_out << "NO" << endl;
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
