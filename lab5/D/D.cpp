// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main()
{
    ifstream file_in("quack.in");
    ofstream file_out("quack.out");
    vector<unsigned short int> registr(26, 0);
    queue<unsigned short int> que;
    vector<string> prog;
    map<string, int> labels;
    string command;
    int i = 0;
    while (file_in >> command)
    {
        prog.push_back(command);
        if (command[0] == ':')
        {
            command.erase(0, 1);
            labels.emplace(command, i);
        }
        ++i;
    }
    unsigned short int x, y;
    string label;
    for (i = 0; i < prog.size(); ++i)
    {
        if (prog[i] == "+")
        {
            x = que.front();
            que.pop();
            y = que.front();
            que.pop();
            que.push(x + y);
            continue;
        }
        if (prog[i] == "-")
        {
            x = que.front();
            que.pop();
            y = que.front();
            que.pop();
            que.push(x - y);
            continue;
        }
        if (prog[i] == "*")
        {
            x = que.front();
            que.pop();
            y = que.front();
            que.pop();
            que.push(x * y);
            continue;
        }
        if (prog[i] == "/")
        {
            x = que.front();
            que.pop();
            y = que.front();
            que.pop();
            que.push(x / y);
            continue;
        }
        if (prog[i] == "%")
        {
            x = que.front();
            que.pop();
            y = que.front();
            que.pop();
            que.push(x % y);
            continue;
        }
        if (prog[i][0] == '>')
        {
            x = que.front();
            que.pop();
            registr[prog[i][1]-'a'] = x;
            continue;
        }
        if (prog[i][0] == '<')
        {
            que.push(registr[prog[i][1] - 'a']);
            continue;
        }
        if (prog[i] == "P")
        {
            x = que.front();
            que.pop();
            file_out << x << endl;
            continue;
        }
        if (prog[i][0] == 'P')
        {
            file_out << registr[prog[i][1] - 'a'] << endl;
            continue;
        }
        if (prog[i] == "C")
        {
            x = que.front();
            que.pop();
            file_out << (char)(x % 256);
            continue;
        }
        if (prog[i][0] == 'C')
        {
            file_out << (char)(registr[prog[i][1] - 'a'] % 256);
            continue;
        }
        if (prog[i][0] == ':')
        {
            continue;
        }
        if (prog[i][0] == 'J')
        {
            label = prog[i];
            label.erase(0, 1);
            i = labels.find(label)->second;
            continue;
        }
        if (prog[i][0] == 'Z')
        {
            if (registr[prog[i][1] - 'a'] == 0)
            {
                label = prog[i];
                label.erase(0, 2);
                i = labels.find(label)->second;
            }
            continue;
        }
        if (prog[i][0] == 'E')
        {
            if (registr[prog[i][1] - 'a'] == registr[prog[i][2] - 'a'])
            {
                label = prog[i];
                label.erase(0, 3);
                i = labels.find(label)->second;
            }
            continue;
        }
        if (prog[i][0] == 'G')
        {
            if (registr[prog[i][1] - 'a'] > registr[prog[i][2] - 'a'])
            {
                label = prog[i];
                label.erase(0, 3);
                i = labels.find(label)->second;
            }
            continue;
        }
        if (prog[i] == "Q")
        {
            i = prog.size();
            continue;
        }
        x = stoi(prog[i]);
        que.push(x);
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
