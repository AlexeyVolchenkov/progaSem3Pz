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
        int i = 0;
        cout << endl << "Array deleted " << i << endl;
        delete[] arr;
        i++;
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
    void Sum(const MasClass& obj, const MasClass& obj1)
    {
        int* newArray;
        if (obj.len < obj1.len)
        {
            len = obj1.len;
            newArray = new int[obj1.len];
            for (int i = 0; i < obj.len; i++)
            {
                newArray[i] = obj.arr[i] + obj1.arr[i];
            }
            for (int i = obj.len; i < obj1.len; i++)
            {
                newArray[i] = obj1.arr[i];
            }
        }
        else
        {
            len = obj.len;
            newArray = new int[obj.len];
            for (int i = 0; i < obj1.len; i++)
            {
                newArray[i] = obj1.arr[i] + obj1.arr[i];
            }
            for (int i = obj1.len; i < obj.len; i++)
            {
                newArray[i] = obj.arr[i];
            }
        }
        delete[] arr;
        arr = newArray;
    }
    void Sub(const MasClass& obj, const MasClass& obj1)
    {
        int size = 0;
        int* newArray;
        if (obj.len < obj1.len)
        {
            len = obj1.len;
            newArray = new int[obj1.len];
            for (int i = 0; i < obj.len; i++)
            {
                newArray[i] = obj.arr[i] - obj1.arr[i];
            }
            for (int i = obj.len; i < obj1.len; i++)
            {
                newArray[i] = obj1.arr[i];
            }
        }
        else
        {
            size = obj1.len;
            len = obj.len;
            newArray = new int[obj.len];
            for (int i = 0; i < obj1.len; i++)
            {
                newArray[i] = obj1.arr[i] - obj1.arr[i];
            }
            for (int i = obj1.len; i < obj.len; i++)
            {
                newArray[i] = obj.arr[i];
            }
        }
        delete[] arr;
        arr = newArray;
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
    MasClass arr1(5), arr2(7), arr3(0);
    arr1.random();
    arr2.random();
    arr3.Sum(arr1, arr2);
    arr3.Sub(arr1, arr2);
    return 0;
}