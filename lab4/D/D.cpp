// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

void stack_push(int* stack, int& size, int number)
{
    ++size;
    stack[size] = number;
}

int stack_pop(int* stack, int& size)
{
    --size;
    return stack[size + 1];
}

int main()
{
    ifstream file_in("postfix.in");
    ofstream file_out("postfix.out");
    int* stack = new int[101];
    int i, size = 0;
    char symbol;
    while (file_in >> symbol)
    {
        if (symbol == '+' or symbol == '-' or symbol == '*')
        {
            int number2 = stack_pop(stack, size);
            int number1 = stack_pop(stack, size);
            if (symbol == '+')
            {
                stack_push(stack, size, number1 + number2);
            }
            if (symbol == '-')
            {
                stack_push(stack, size, number1 - number2);
            }
            if (symbol == '*')
            {
                stack_push(stack, size, number1 * number2);
            }
        }
        else
        {
            stack_push(stack, size, symbol - '0');
        }
    }
    file_out << stack[1];
    delete[] stack;
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
