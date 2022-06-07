// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

void queue_push(int* queue, int& tail, int n)
{
    queue[tail] = n;
    if (tail == 100000)
    {
        tail = 0;
    }
    else
    {
        ++tail;
    }
}

int queue_pop(int* queue, int& head)
{
    int n = queue[head];
    if (head == 100000)
    {
        head = 0;
    }
    else
    {
        ++head;
    }
    return n;
}

int main()
{
    ifstream file_in("queue.in");
    ofstream file_out("queue.out");
    int* queue = new int[1000001];
    int i, m, n, head = 0, tail = 0;
    char symbol;
    file_in >> m;
    for (i = 0; i < m; ++i)
    {
        file_in >> symbol;
        if (symbol == '+')
        {
            file_in >> n;
            queue_push(queue, tail, n);
        }
        else
        {
            file_out << queue_pop(queue, head) << endl;
        }
    }
    delete[] queue;
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
