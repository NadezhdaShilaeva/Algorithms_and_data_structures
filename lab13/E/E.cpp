// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex
{
    vector<int> next;
    vector<int> leaf;
    int parent;
    char pch;
    int suff_link;
    int out;
    bool is_found;
    vector<int> go;
};

void add_string(vector<vertex>& bor, string& str, int& condition, int i);
int go(vector<vertex>& bor, int v, char c);
int get_link(vector<vertex>& bor, int v);
bool is_term(vector<vertex>& bor, int v);

void add_string(vector<vertex>& bor, string& str, int& condition, int i)
{
    int v = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (bor[v].next[str[i] - 'a'] == -1)
        {
            vertex ver;
            bor.push_back(ver);
            bor[condition].next.resize(26, -1);
            bor[condition].go.resize(26, -1);
            bor[condition].suff_link = -1;
            bor[condition].out = -1;
            bor[condition].parent = v;
            bor[condition].pch = str[i] - 'a';
            bor[v].next[str[i] - 'a'] = condition++;
        }
        v = bor[v].next[str[i] - 'a'];
    }
    bor[v].leaf.push_back(i);
}

int go(vector<vertex>& bor, int v, char c)
{
    if (bor[v].go[c] == -1)
    {
        if (bor[v].next[c] != -1)
        {
            bor[v].go[c] = bor[v].next[c];
        }
        else
        {
            if (v == 0)
            {
                bor[v].go[c] = 0;
            }
            else
            {
                bor[v].go[c] = go(bor, get_link(bor, v), c);
            }
        }
    }
    return bor[v].go[c];
}

int get_link(vector<vertex>& bor, int v)
{
    if (bor[v].suff_link == -1)
    {
        if (v == 0 or bor[v].parent == 0)
        {
            bor[v].suff_link = 0;
        }
        else
        {
            bor[v].suff_link = go(bor, get_link(bor, bor[v].parent), bor[v].pch);
        }
    }
    return bor[v].suff_link;
}

int get_out(vector<vertex>& bor, int v)
{
    if (bor[v].out == -1)
    {
        int link = get_link(bor, v);
        if (link != 0 and link != -1)
        {
            if (bor[link].leaf.size() != 0)
            {
                bor[v].out = link;
            }
            else
            {
                bor[v].out = get_out(bor, link);
            }
        }
    }
    return bor[v].out;
}

int main()
{
    ifstream fin("search4.in");
    ofstream fout("search4.out");

    size_t n;
    fin >> n;
    vector<string> strs(n);
    string t;
    for (int i = 0; i < n; ++i)
    {
        fin >> strs[i];
    }
    fin >> t;
    
    vector<vertex> bor(1);
    bor[0].parent = 0;
    bor[0].suff_link = 0;
    bor[0].out = -1;
    bor[0].next.resize(26, -1);
    bor[0].go.resize(26, -1);
    int condition = 1;
    for (int i = 0; i < n; ++i)
    {
        add_string(bor, strs[i], condition, i);
    }

    for (int i = 0; i < bor.size(); ++i)
    {
        get_out(bor, i);
    }

    vector<bool> ans(n);
    int v = 0;
    for (int i = 0; i < t.size(); ++i)
    {
        v = go(bor, v, t[i] - 'a');
        int link = v;
        while (link != -1)
        {
            if (bor[link].is_found)
            {
                break;
            }
            bor[link].is_found = true;
            for (int j = 0; j < bor[link].leaf.size(); ++j)
            {
                ans[bor[link].leaf[j]] = true;
            }
            link = get_out(bor, link);
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (ans[i])
        {
            fout << "YES\n";
        }
        else
        {
            fout << "NO\n";
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
