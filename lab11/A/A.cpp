// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

long long INF = 2000000000001;

int main()
{
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");
    int n, start, finish, weight;
    fin >> n >> start >> finish;
    --start;
    --finish;
    set<pair<int, long long>> unused;
    vector<long long> dist(n, INF);
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin >> weight;
            if (weight != -1 and i != j)
            {
                graph[i].push_back({ j, weight });
            }
        }
    }
    dist[start] = 0;
    unused.insert({ 0, start });
    while (!unused.empty())
    {
        int v1 = unused.begin()->second;
        unused.erase(unused.begin());
        for (auto u : graph[v1])
        {
            int v2 = u.first;
            int weight = u.second;
            if (dist[v1] + weight < dist[v2])
            {
                unused.erase({ dist[v2], v2 });
                dist[v2] = dist[v1] + weight;
                unused.insert({ dist[v2], v2 });
            }
        }
    }
    if (dist[finish] == INF)
    {
        fout << -1;
    }
    else
    {
        fout << dist[finish];
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
