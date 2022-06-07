// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void heap_sort(vector<int>&, int);
void build_max_heap(vector<int>&, int);
void max_heapify(vector<int>&, int, int);

void heap_sort(vector<int>& arr, int heap_size)
{
    build_max_heap(arr, heap_size);
    for (int i = arr.size() - 1; i > 0; --i)
    {
        swap(arr[i], arr[0]);
        --heap_size;
        max_heapify(arr, 0, heap_size);
    }
}

void build_max_heap(vector<int>& arr, int heap_size)
{
    for (int i = arr.size() / 2 - 1; i >= 0; --i)
    {
        max_heapify(arr, i, heap_size);
    }
}

void max_heapify(vector<int>& arr, int i, int heap_size)
{
    int left, right, largest;
    left = i * 2 + 1;
    right = (i + 1) * 2;
    if ((left < heap_size) and (arr[left] > arr[i]))
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if ((right < heap_size) and (arr[right] > arr[largest]))
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        max_heapify(arr, largest, heap_size);
    }
}

int main()
{
    ifstream file_in("sort.in");
    ofstream file_out("sort.out");
    int n, i;
    file_in >> n;
    vector<int> arr(n);
    for (i = 0; i < n; ++i)
    {
        file_in >> arr[i];
    }
    heap_sort(arr, n);
    for (i = 0; i < n; ++i)
    {
        file_out << arr[i] << " ";
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
