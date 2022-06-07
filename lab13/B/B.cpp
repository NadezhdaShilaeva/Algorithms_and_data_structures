// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("search2.in");
    ofstream fout("search2.out");

    const int h = 2, k = 1000000001;
    string p, t;
    cin >> p >> t;
    int m = p.size(), n = t.size(), hash_p = 0, hash_t = 0, h_m = 1;
    if (m > n)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans;
    for (int i = 0; i < m; ++i)
    {
        h_m = (long long)(h_m * h) % k;
        hash_p = ((hash_p * h) % k + (p[i] - 'A')) % k;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        hash_t = ((hash_t * h) % k + (t[i] - 'A')) % k;
    }
    for (int i = m - 1; i < n; ++i)
    {
        if (i > m - 1)
        {
            hash_t = ((hash_t * h) % k + k - ((long long)(t[i - m] - 'A') * h_m) % k + (t[i] - 'A')) % k;
        }
        else
        {
            hash_t = ((hash_t * h) % k + (t[i] - 'A')) % k;
        }
        if (hash_t != hash_p)
        {
            continue;
        }
        int j;
        for (j = 0; j < m; ++j)
        {
            if (p[j] != t[i - m + 1 + j])
            {
                break;
            }
        }
        if (j == m)
        {
            ans.push_back(i - m + 2);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
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
