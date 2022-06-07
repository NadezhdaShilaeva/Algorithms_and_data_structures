// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ifstream file_in("spantree.in");
    ofstream file_out("spantree.out");
    int n;
    file_in >> n;
    vector<pair<int, int>> points(n);
    vector<pair<float, pair<int, int>>> edges;
    for (int i = 0; i < n; ++i)
    {
        file_in >> points[i].first >> points[i].second;
    }
    float mst = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            float dist = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
            edges.push_back({ dist, {i, j} });
        }
    }
    vector<int> colors(n);
    for (int i = 0; i < n; ++i)
    {
        colors[i] = i;
    }
    sort(edges.begin(), edges.end());
    for (auto edge : edges)
    {
        if (colors[edge.second.first] != colors[edge.second.second])
        {
            mst += edge.first;
            int color_new = colors[edge.second.first];
            int color_old = colors[edge.second.second];
            for (int i = 0; i < n; ++i)
            {
                if (colors[i] == color_old)
                {
                    colors[i] = color_new;
                }
            }
        }
    }
    file_out << fixed << setprecision(5) << mst;
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
