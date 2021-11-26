#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
using namespace std;


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    string size, sizeStr;
    vector <int> v1, v2, repeat;
    vector<int>::iterator it = repeat.begin();
    int size1 = 0, size2 = 0;
    double average1 = 0, average2 = 0;
    cout << "Введите размеры двух массивов через пробел: ";
    getline(cin, size);
    for (int i = 0; i < size.size(); i++)
    {
        sizeStr += size[i];
        if (isspace(size[i]))
        {
            sizeStr.pop_back();
            size1 = stoi(sizeStr);
            sizeStr = "";
        }
    }
    size2 = stoi(sizeStr);
    for (int i = 0; i < size1; i++)
    {
        v1.push_back(rand() % 201 - 100);
    }
    for (int i = 0; i < size2; i++)
    {
        v2.push_back(rand() % 201 - 100);
    }
    cout << "Вывод массива 1: ";
    for (int i = 0; i < size1; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    cout << "Вывод массива 2: ";
    for (int i = 0; i < size2; i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size1; i++)
    {
        average1 += v1[i];
    }
    cout << "Среднее арифметическое первого массива : " << average1 / size1 << endl;
    for (int i = 0; i < size2; i++)
    {
        average2 += v2[i];
    }
    cout << "Среднее арифметическое второго массива : " << average2 / size2 << endl;
    cout << "Пересекающие элементы: " << endl;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (v1[i] == v2[j])
            {
                for (int k = 0; k <= repeat.size(); k++)
                {
                    if (find(repeat.begin(), repeat.end(), v1[i]) == repeat.end())
                    {
                        repeat.push_back(v1[i]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < repeat.size(); i++)
    {
        cout << repeat[i] << " ";
    }
    cout << endl;
}