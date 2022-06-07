// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void merge(vector<int>&, int, int, int);
void merge_sort(vector<int>&, int, int);
long long inversions = 0;

void merge_sort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    else
    {
        return;
    }
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n_left_arr = mid - left + 1;
    int n_right_arr = right - mid;
    vector<int> left_arr(n_left_arr);
    vector<int> right_arr(n_right_arr);
    int i;
    for (i = 0; i < n_left_arr; i++)
    {
        left_arr[i] = arr[left + i];
    }
    for (i = 0; i < n_right_arr; i++)
    {
        right_arr[i] = arr[mid + i + 1];
    }
    int l = 0, r = 0;
    for (i = left; i <= right; i++)
    {
        if ((r == n_right_arr) or (l < n_left_arr and left_arr[l] <= right_arr[r]))
        {
            arr[i] = left_arr[l];
            l++;
        }
        else
        {
            arr[i] = right_arr[r];
            r++;
            inversions += (n_left_arr - l);
        }
    }
}

int main()
{
    ifstream file_in("inversions.in");
    ofstream file_out("inversions.out");
    int i, j, left, right, n;
    file_in >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
    {
        file_in >> arr[i];
    }
    merge_sort(arr, 0, arr.size() - 1);
    file_out << inversions;
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
