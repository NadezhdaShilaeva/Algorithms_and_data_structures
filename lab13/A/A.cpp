﻿// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("search1.in");
    ofstream fout("search1.out");

    string p, t;
    fin >> p >> t;
    vector<int> ans;
    int delta = t.size() - p.size();
    for (int i = 0; i <= delta; ++i)
    {
        int j;
        for (j = 0; j < p.size(); ++j)
        {
            if (t[i + j] != p[j])
            {
                break;
            }
        }
        if (j == p.size())
        {
            ans.push_back(i + 1);
        }
    }

    fout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        fout << ans[i] << " ";
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
