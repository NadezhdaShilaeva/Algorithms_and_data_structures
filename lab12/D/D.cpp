﻿// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");

    int n, m;
    fin >> n >> m;
    vector<vector<int>> desk(n + 3, vector<int>(m + 3, 0));
    for (int k = 2; k <= n + 1; ++k)
    {
        int i = k, j = 2;
        while (i > 1 and j <= m + 1)
        {
            if (i == 2 and j == 2)
            {
                desk[i][j] = 1;
            }
            else
            {
                desk[i][j] = desk[i - 1][j - 2] + desk[i + 1][j - 2] + desk[i - 2][j - 1] + desk[i - 2][j + 1];
            }
            --i;
            ++j;
        }
    }
    for (int k = 3; k <= m + 1; ++k)
    {
        int i = n + 1, j = k;
        while (i > 1 and j <= m + 1)
        {
            if (i == 2 and j == 2)
            {
                desk[i][j] = 1;
            }
            else
            {
                desk[i][j] = desk[i - 1][j - 2] + desk[i + 1][j - 2] + desk[i - 2][j - 1] + desk[i - 2][j + 1];
            }
            --i;
            ++j;
        }
    }
    fout << desk[n + 1][m + 1];
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