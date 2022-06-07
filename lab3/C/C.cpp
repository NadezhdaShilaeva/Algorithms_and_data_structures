// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void counting_sort(vector<string>& arr, int index)
{
    int i;
    vector<int> count(26, 0);
    for (i = 0; i < arr.size(); ++i)
    {
        count[arr[i][index] - 'a']++;
    }
    for (i = 1; i < 26; ++i)
    {
        count[i] += count[i - 1];
    }
    vector<string> arr_sort(arr.size());
    for (i = arr.size() - 1; i >= 0; --i)
    {
        arr_sort[count[arr[i][index] - 'a'] - 1] = arr[i];
        --count[arr[i][index] - 'a'];
    }
    arr = arr_sort;
}

int main()
{
    ifstream file_in("radixsort.in");
    ofstream file_out("radixsort.out");
    int n, m, k, i;
    file_in >> n >> m >> k;
    vector<string> arr(n);
    for (i = 0; i < n; ++i)
    {
        file_in >> arr[i];
    }
    for (i = 0; i < k; ++i)
    {
        counting_sort(arr, m - i - 1);
    }
    for (i = 0; i < n; ++i)
    {
        file_out << arr[i] << endl;
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
