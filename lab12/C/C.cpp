// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    int size_min, size_max;
    cin >> str1 >> str2;
    if (str1.size() > str2.size())
    {
        swap(str1, str2);
    }
    size_min = str1.size();
    size_max = str2.size();

    vector<int> max_subseq(size_min + 1, 0);
    vector<vector<bool>> pred(size_max + 1, vector<bool>(size_min + 1, 0));

    for (int i = 1; i <= size_max; ++i)
    {
        int max_sub_i_1_j_1 = 0;
        for (int j = 1; j <= size_min; ++j)
        {
            int tmp = max_subseq[j];
            if (str1[j - 1] == str2[i - 1])
            {
                max_subseq[j] = max_sub_i_1_j_1 + 1;
            }
            else
            {
                if (max_subseq[j] >= max_subseq[j - 1])
                {
                    pred[i][j] = 1;
                }
                else
                {
                    max_subseq[j] = max_subseq[j - 1];
                    pred[i][j] = 0;
                }
            }
            max_sub_i_1_j_1 = tmp;
        }
    }

    string ans;
    int i = size_max;
    int j = size_min;
    while (i != 0 and j != 0)
    {
        if (str2[i - 1] == str1[j - 1])
        {
            ans += str2[i - 1];
            i -= 1;
            j -= 1;
        }
        else
        {
            if (pred[i][j] == 1)
            {
                i -= 1;
            }
            else
            {
                j -= 1;
            }
        }
    }
    for (i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i];
    }
    cout << endl;
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
