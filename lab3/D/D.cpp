// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ofstream file_out("priorityqueue.out");

int inf = 1000000001;

void min_heapify(vector<pair<int, int>>&, int);
void heap_push(vector<pair<int, int>>&, int, int);
void heap_decrease_key(vector<pair<int, int>>&, int, int);
void heap_extract_min(vector<pair<int, int>>&);

void min_heapify(vector<pair<int, int>>& arr, int i)
{
    int left, right, smallest;
    left = i * 2 + 1;
    right = (i + 1) * 2;
    if ((left < arr.size()) and (arr[left].first < arr[i].first))
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if ((right < arr.size()) and (arr[right].first < arr[smallest].first))
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        min_heapify(arr, smallest);
    }
}

void heap_push(vector<pair<int, int>>& arr, int key, int number_str)
{
    arr.push_back({ inf, number_str });
    heap_decrease_key(arr, number_str, key);
}

void heap_decrease_key(vector<pair<int, int>>& arr, int number_str, int key)
{
    int i;
    for (i = 0; arr[i].second!=number_str; ++i);
    arr[i].first = key;
    while ((i > 0) and (arr[i].first < arr[(i - 1) / 2].first))
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heap_extract_min(vector<pair<int, int>>& arr)
{ 
    if (arr.size() == 0)
    {
        file_out << '*' << endl;
    }
    else
    {
        file_out << arr[0].first << endl;
        arr[0] = arr.back();
        arr.pop_back();
        min_heapify(arr, 0);
    }
}

int main()
{
    ifstream file_in("priorityqueue.in");
    string operation;
    vector<pair<int, int>> arr;
    int number_str = 0;
    while (file_in >> operation)
    {
        ++number_str;
        if (operation == "push")
        {
            int x;
            file_in >> x;
            heap_push(arr, x, number_str);
        }
        if (operation == "extract-min")
        {
            heap_extract_min(arr);
        }
        if (operation == "decrease-key")
        {
            int x, y;
            file_in >> x >> y;
            heap_decrease_key(arr, x, y);
        }
    }
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
