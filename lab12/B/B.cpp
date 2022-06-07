// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000001;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), min_last_num(n, INF), pos(n, -1), prev(n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i)
    {
        int length = lower_bound(min_last_num.begin(), min_last_num.end(), nums[i]) - min_last_num.begin();
        min_last_num[length] = nums[i];
        pos[length] = i;
        if (length != 0)
        {
            prev[i] = pos[length - 1];
        }
    }
    int ans;
    ans = lower_bound(min_last_num.begin(), min_last_num.end(), INF) - min_last_num.begin();
    
    cout << ans << endl;
    vector<int> path;
    int last = pos[ans - 1];
    while (last != -1)
    {
        path.push_back(nums[last]);
        last = prev[last];
    }
    for (int i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i] << " ";
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
