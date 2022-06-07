// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(int start, vector<int>& winner, vector<vector<int>>& graph)
{
    for (auto v : graph[start])
    {
        if (winner[v] == 0)
        {
            dfs(v, winner, graph);
        }
    }
    winner[start] = 2;
    for (auto v : graph[start])
    {
        if (winner[v] == 2)
        {
            winner[start] = 1;
            break;
        }
    }
}

int main()
{
    ifstream file_in("game.in");
    ofstream file_out("game.out");
    int n, m, v1, v2, v_start;
    file_in >> n >> m >> v_start;
    vector<vector<int>> graph(n + 1);
    vector<int> winner(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        file_in >> v1 >> v2;
        graph[v1].push_back(v2);
    }
    dfs(v_start, winner, graph);
    if (winner[v_start] == 1)
    {
        file_out << "First player wins";
    }
    else
    {
        file_out << "Second player wins";
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
