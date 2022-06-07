// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int INF = 1000000000;

int main()
{
    ifstream fin("negcycle.in");
    ofstream fout("negcycle.out");
    int n, w;
    fin >> n;
    vector<pair<pair<int, int>, int>> edges;
    vector<int> dist(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> w;
            if (w != INF)
            {
                edges.push_back({ {i, j}, w });
            }
        }
    }
    vector<int> pred(n + 1, -1);
    dist[1] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (auto& edge : edges)
        {
            int v1 = edge.first.first;
            int v2 = edge.first.second;
            int weight = edge.second;
            if (dist[v1] + weight < dist[v2])
            {
                dist[v2] = dist[v1] + weight;
                pred[v2] = v1;
            }
        }
    }
    vector<int> path;
    for (auto& edge : edges)
    {
        int v1 = edge.first.first;
        int v2 = edge.first.second;
        int weight = edge.second;
        if (dist[v1] + weight < dist[v2])
        {
            pred[v2] = v1;
            for (int i = 0; i < n - 1; ++i)
            {
                v2 = pred[v2];
            }
            int finish = v2;
            while (finish != pred[v2])
            {
                path.push_back(v2);
                v2 = pred[v2];
            }
            path.push_back(v2);
            path.push_back(finish);
            break;
        }
    }
    if (path.size() == 0)
    {
        fout << "NO";
    }
    else
    {
        fout << "YES" << endl << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; --i)
        {
            fout << path[i] << " ";
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
