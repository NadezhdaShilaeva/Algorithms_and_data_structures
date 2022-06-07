// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int hash_function(string, int);
void hash_put(vector<pair<string, string>>&, string, string);
int hash_get(vector<pair<string, string>>&, string);
void hash_delete(vector<pair<string, string>>&, string);

const int m = 1000003, m2 = 999983, p = 53;
string null = "0", deleted = "1";
vector<int> p_pow(20);

int hash_function(string x, int i)
{
	int hash = 0;
	for (int j = 0; j < x.size(); ++j)
	{
		hash = (hash + (x[j] - 'A') * p_pow[j] % m) % m;
	}
	return (hash + i * (1 + hash % m2)) % m;
}

void hash_put(vector<pair<string, string>>& map, string x, string y)
{
	int idx = hash_get(map, x);
	if (idx != -1)
	{
		map[idx].second = y;
		return;
	}
	for (int i = 0; i != m; ++i)
	{
		int j = hash_function(x, i);
		if (map[j].first == null or map[j].first == deleted)
		{
			map[j] = { x, y };
			return;
		}
	}
}

int hash_get(vector<pair<string, string>>& map, string x)
{
	for (int i = 0; i != m; ++i)
	{
		int j = hash_function(x, i);
		if (map[j].first == x)
		{
			return j;
		}
		if (map[j].first == null)
		{
			return -1;
		}
	}
	return -1;
}

void hash_delete(vector<pair<string, string>>& map, string x)
{
	if (hash_get(map, x) == -1)
	{
		return;
	}
	for (int i = 0; i != m; ++i)
	{
		int j = hash_function(x, i);
		if (map[j].first == x)
		{
			map[j] = { deleted, deleted };
			return;
		}
	}
}

int main()
{
	ifstream file_in("map.in");
	ofstream file_out("map.out");
	vector<pair<string, string>> map(m, { null, null });
	string operation, x, y;
	p_pow[0] = 1;
	for (int i = 1; i < 20; ++i)
	{
		p_pow[i] = p_pow[i - 1] * p % m;
	}
	while (file_in >> operation)
	{
		if (operation == "put")
		{
			file_in >> x >> y;
			hash_put(map, x, y);
		}
		if (operation == "get")
		{
			file_in >> x;
			int idx = hash_get(map, x);
			if (idx != -1)
			{
				file_out << map[idx].second << endl;
			}
			else
			{
				file_out << "none" << endl;
			}
		}
		if (operation == "delete")
		{
			file_in >> x;
			hash_delete(map, x);
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
