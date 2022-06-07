// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void stack_push(char* stack, int& size, char bracket)
{
    ++size;
    stack[size] = bracket;
}

void stack_pop(char* stack, int& size)
{
    --size;
}

int main()
{
    ifstream file_in("brackets.in");
    ofstream file_out("brackets.out");
    string brackets;
    while (file_in >> brackets)
    {
        char* stack = new char[10001];
        int i, size = 0;
        for (i = 0; i < brackets.size(); ++i)
        {
            if (brackets[i] == '(' or brackets[i] == '[')
            {
                stack_push(stack, size, brackets[i]);
            }
            else
            {
                if (size != 0 and ((brackets[i] == ')' and stack[size] == '(') or (brackets[i] == ']' and stack[size] == '[')))
                {
                    stack_pop(stack, size);
                }
                else
                {
                    break;
                }
            }
        }
        if (i == brackets.size() and size == 0)
        {
            file_out << "YES" << endl;
        }
        else
        {
            file_out << "NO" << endl;
        }
        delete[] stack;
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
