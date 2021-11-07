#include <iostream>
using namespace std;


class MasClass
{

    int len;
    int* arr;
public:
    MasClass(int length)
    {
        len = length;
        arr = new int[length];
    }
    MasClass(const MasClass& obj)
    {
        len = obj.len;
        arr = new int[len];

        for (int i = 0; i < len; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    ~MasClass() 
    {
        cout << endl << "Array deleted" << endl;
        delete[] arr;
    }
    void setArray(int num, int value)
    {
        if ((num >= 0) && (num < len))
        {
            if ((value > -100) && (value < 100))
            {
                arr[num] = value;
            }
            else
            {
                cout << "Error value" << endl;
            }
        }
        else
        {
            cout << "Error index" << endl;
        }

    }
    int getArray(int num)
    {
        if ((num >= 0) && (num < len))
        {
            return arr[num];
        }
        else
        {
            cout << "Error index" << endl;
        }
    }
    void Sum(const MasClass& obj)
    {
        for (int i = 0; i < len && i < obj.len; i++)
        {
            arr[i] += obj.arr[i];
        }
    }
    void Sub(const MasClass& obj)
    {
        for (int i = 0; i < len && i < obj.len; i++)
        {
            arr[i] -= obj.arr[i];
        }
    }
    void random()
    {
        for (int i = 0; i < len; i++)
        {
            arr[i] = rand() % 10;
        }
    }
    void push_back(int value)
    {
        if (value >= -100 && value <= 100)
        {
            int* newArray = new int[len + 1];
            for (int i = 0; i < len; i++)
            {
                newArray[i] = arr[i];
            }
            newArray[len] = value;
            len++;
            delete[] arr;
            arr = newArray;
        }
        else cout << "Error" << endl;
    }
    void output() 
    {
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};
int main()
{
    MasClass arr1(2), arr2(2);
    arr1.random();
    arr2.random();
    arr1.push_back(2);
    return 0;
}