// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(int start, vector<bool>& vis, vector<vector<int>>& graph, int count_comp, vector<int>& component)
{
    vis[start] = true;
    component[start] = count_comp;
    for (auto v : graph[start])
    {
        if (!vis[v])
        {
            dfs(v, vis, graph, count_comp, component);
        }
    }
}

int main()
{
    ifstream file_in("components.in");
    ofstream file_out("components.out");
    int n, m, v1, v2;
    file_in >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> vis(n, false);
    vector<int> component(n);
    int count_comp = 0;
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2;
        graph[v1 - 1].push_back(v2 - 1);
        graph[v2 - 1].push_back(v1 - 1);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            ++count_comp;
            dfs(i, vis, graph, count_comp, component);
        }
    }
    file_out << count_comp << endl;
    for (int i = 0; i < n; ++i)
    {
        file_out << component[i] << " ";
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
