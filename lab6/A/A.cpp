// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int hash_function(int, int);
void hash_insert(vector<int>&, int);
bool hash_exists(vector<int>&, int);
void hash_delete(vector<int>&, int);

int m = 1000003, m2 = 999983, null = -1000000001, deleted = 1000000001;

int hash_function(int x, int i)
{
	return (abs(x) % m + i * (1 + abs(x) % m2)) % m;
}

void hash_insert(vector<int>& set, int x)
{
	if (hash_exists(set, x))
		return;
	for (int i = 0; i!=m; ++i)
	{
		int j = hash_function(x, i);
		if (set[j] == null or set[j] == deleted)
		{
			set[j] = x;
			return;
		}
	}
}

bool hash_exists(vector<int>& set, int x)
{
	for (int i = 0; i != m; ++i)
	{
		int j = hash_function(x, i);
		if (set[j] == x)
			return true;
		if (set[j] == null)
			return false;
	}
	return false;
}

void hash_delete(vector<int>& set, int x)
{
	if (!hash_exists(set, x))
		return;
	for (int i = 0; i != m; ++i)
	{
		int j = hash_function(x, i);
		if (set[j] == x)
		{
			set[j] = deleted;
			return;
		}
	}
}

int main()
{
	ifstream file_in("set.in");
	ofstream file_out("set.out");
	vector<int> set(m, null);
	string operation;
	int x;
	while (file_in >> operation)
	{
		file_in >> x;
		if (operation == "insert")
		{
			hash_insert(set, x);
		}
		if (operation == "exists")
		{
			if (hash_exists(set, x))
			{
				file_out << "true" << endl;
			}
			else
			{
				file_out << "false" << endl;
			}
		}
		if (operation == "delete")
		{
			hash_delete(set, x);
		}
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
