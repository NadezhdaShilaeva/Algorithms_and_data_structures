// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(int start, vector<pair<int, vector<int>>>& tree, vector<vector<int>>& max_count)
{
    for (auto v : tree[start].second)
    {
        dfs(v, tree, max_count);
    }
    max_count[start][1] = tree[start].first;
    for (auto v : tree[start].second)
    {
        max_count[start][0] += max(max_count[v][0], max_count[v][1]);
        max_count[start][1] += max_count[v][0];
    }
}

int main()
{
    ifstream fin("selectw.in");
    ofstream fout("selectw.out");

    int n, pred, root, cost;
    fin >> n;
    vector<pair<int, vector<int>>> tree(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        fin >> pred >> cost;
        tree[i].first = cost;
        if (pred == 0)
        {
            root = i;
        }
        else
        {
            tree[pred].second.push_back(i);
        }
    }
    vector<vector<int>> max_count(n + 1, vector<int>(2, 0));
    dfs(root, tree, max_count);
    fout << max(max_count[root][0], max_count[root][1]);
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
