// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main()
{
    ifstream file_in("input.txt");
    ofstream file_out("output.txt");
    int n, m;
    file_in >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
    queue<pair<int, int>> que;
    pair<int, int> finish;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            file_in >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                parent[i][j] = make_pair(-2, -2);
                que.push(make_pair(i, j));
            }
            if (maze[i][j] == 'T')
            {
                finish = make_pair(i, j);
            }
        }
    }
    while (!que.empty() and parent[finish.first][finish.second] == make_pair(-1, -1))
    {
        int v_line = que.front().first;
        int v_col = que.front().second;
        que.pop();
        if (v_line > 0 and maze[v_line - 1][v_col] != '#' and parent[v_line - 1][v_col] == make_pair(-1, -1))
        {
            parent[v_line - 1][v_col] = make_pair(v_line, v_col);
            que.push(make_pair(v_line - 1, v_col));
        }
        if (v_line < n - 1 and maze[v_line + 1][v_col] != '#' and parent[v_line + 1][v_col] == make_pair(-1, -1))
        {
            parent[v_line + 1][v_col] = make_pair(v_line, v_col);
            que.push(make_pair(v_line + 1, v_col));
        }
        if (v_col > 0 and maze[v_line][v_col - 1] != '#' and parent[v_line][v_col - 1] == make_pair(-1, -1))
        {
            parent[v_line][v_col - 1] = make_pair(v_line, v_col);
            que.push(make_pair(v_line, v_col - 1));
        }
        if (v_col < m - 1 and maze[v_line][v_col + 1] != '#' and parent[v_line][v_col + 1] == make_pair(-1, -1))
        {
            parent[v_line][v_col + 1] = make_pair(v_line, v_col);
            que.push(make_pair(v_line, v_col + 1));
        }
    }
    vector<char> path;
    if (parent[finish.first][finish.second] == make_pair(-1, -1))
    {
        file_out << -1;
    }
    else
    {
        pair<int, int> v = finish;
        while (parent[v.first][v.second] != make_pair(-2, -2))
        {
            pair<int, int> v_par = parent[v.first][v.second];
            if (v.first == v_par.first + 1)
            {
                path.push_back('D');
            }
            if (v.first == v_par.first - 1)
            {
                path.push_back('U');
            }
            if (v.second == v_par.second + 1)
            {
                path.push_back('R');
            }
            if (v.second == v_par.second - 1)
            {
                path.push_back('L');
            }
            v = v_par;
        }
        file_out << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; --i)
        {
            file_out << path[i];
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
