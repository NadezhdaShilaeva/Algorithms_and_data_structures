// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

long long INF = 2000000000001;

int main()
{
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");
    int n, m, u1, u2, weight;
    fin >> n >> m;
    set<pair<int, long long>> unused;
    vector<long long> dist(n, INF);
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        fin >> u1 >> u2 >> weight;
        graph[u1 - 1].push_back({ u2 - 1, weight });
        graph[u2 - 1].push_back({ u1 - 1, weight });
    }
    dist[0] = 0;
    unused.insert({ 0, 0 });
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
    for (int i = 0; i < n; ++i)
    {
        fout << dist[i] << " ";
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
