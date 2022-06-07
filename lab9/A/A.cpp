// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool cycle = false;

void dfs(int start, vector<int>& color, vector<vector<int>>& graph, vector<int> &answer)
{
    color[start] = 1;
    for (auto v : graph[start])
    {
        if (color[v] == 0)
        {
            dfs(v, color, graph, answer);
        }
        else
        {
            if (color[v] == 1)
            {
                cycle = true;
            }
        }
    }
    color[start] = 2;
    answer.push_back(start);
}

int main()
{
    ifstream file_in("topsort.in");
    ofstream file_out("topsort.out");
    int n, m, v1, v2;
    file_in >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, 0);
    vector<int> answer;
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == 0)
        {
            dfs(i, color, graph, answer);
        }
        if (cycle == true)
        {
            break;
        }
    }
    if (cycle == true)
    {
        file_out << -1;
    }
    else
    {
        for (int i = answer.size() - 1; i >= 0; --i)
        {
            file_out << answer[i] << " ";
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
