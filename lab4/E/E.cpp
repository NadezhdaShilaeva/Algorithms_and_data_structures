// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int binary_search(int* arr, int n, int request)
{
    int left = -1, right = n, mid;
    while (right - 1 > left)
    {
        mid = (left + right) / 2;
        if (arr[mid] < request)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    if (right < n and arr[right] == request)
    {
        return right;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ifstream file_in("binsearch.in");
    ofstream file_out("binsearch.out");
    int i, n, m;
    file_in >> n;
    int* arr = new int[n];
    for (i = 0; i < n; ++i)
    {
        file_in >> arr[i];
    }
    file_in >> m;
    for (i = 0; i < m; ++i)
    {
        int request, idx;
        file_in >> request;
        idx = binary_search(arr, n, request);
        if (idx == -1)
        {
            file_out << -1 << " " << -1 << endl;
        }
        else
        {
            int j;
            for (j = idx; j >= 0 and arr[j] == request; --j);
            file_out << j + 2 << " ";
            for (j = idx; j < n and arr[j] == request; ++j);
            file_out << j << endl;
        }
    }
    delete[] arr;
    return 0;
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
