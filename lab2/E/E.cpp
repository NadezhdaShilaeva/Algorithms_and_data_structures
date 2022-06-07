// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void QuickSortMode(int left, int right, vector<int>& arr, int k)
{
    int i, j, key;
    key = arr[(left + right) / 2];
    i = left;
    j = right;
    do
    {
        while (arr[i] < key)
        {
            i++;
        }
        while (arr[j] > key)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if ((left < j) and (k >= left) and (k <= j))
    {
        QuickSortMode(left, j, arr, k);
    }
    if ((i < right) and (k >= i) and (k <= right))
    {
        QuickSortMode(i, right, arr, k);
    }
}

int main()
{
    ifstream file_in("kth.in");
    ofstream file_out("kth.out");
    int i, n, k;
    file_in >> n >> k;
    vector<int> arr(max(n, 2));
    int a, b, c;
    file_in >> a >> b >> c;
    file_in >> arr[0] >> arr[1];
    for (i = 2; i < n; i++)
    {
        arr[i] = (int)((int)(a * arr[i - 2]) + (int)(b * arr[i - 1]) + c);
    }
    QuickSortMode(0, n - 1, arr, k - 1);
    file_out << arr[k - 1];
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
