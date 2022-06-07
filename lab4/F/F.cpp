// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void binary_search(double* garland, int n)
{
    double left = 0, right = garland[0];
    while (right - left > 0.000001)
    {
        garland[1] = (double)((left + right) / 2);
        int i;
        for (i = 2; i < n; ++i)
        {
            garland[i] = (garland[i - 1] + 1) * 2 - garland[i - 2];
            if (garland[i] < 0)
            {
                break;
            }
        }
        if (i < n)
        {
            left = garland[1];
        }
        else
        {
            right = garland[1];
        }
    }
}

int main()
{
    ifstream file_in("garland.in");
    ofstream file_out("garland.out");
    int n;
    double a;
    file_in >> n >> a;
    double* garland = new double[n];
    garland[0] = a;
    binary_search(garland, n);
    file_out << fixed << setprecision(2) << garland[n - 1];
    delete[] garland;
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
