﻿// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;
    fin >> s;

    vector<int> prefix(s.size() + 1, 0);
    int i = 1, j = 0;
    while (i < s.size())
    {
        if (s[i] == s[j])
        {
            prefix[i + 1] = j + 1;
            ++i;
            ++j;
        }
        else
        {
            if (j > 0)
            {
                j = prefix[j];
            }
            else
            {
                prefix[i + 1] = 0;
                ++i;
            }
        }
    }

    for (int i = 0; i < s.size(); ++i)
    {
        fout << prefix[i + 1] << " ";
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
