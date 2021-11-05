#include <iostream>
using namespace std;


class MasClass
{

    int len;
    int* arr;
    int* arr1;
    int* arr2;
    int* newArray;
public:
    MasClass(int length)
    {
        len = length;
        arr = new int[length];
        newArray = new int[length + 1];
        arr1 = new int[length];
        arr2 = new int[length];
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
        delete[] arr1;
        delete[] arr2;
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
    void Sum()
    {
        for (int i = 0; i < len; i++)
        {
            arr1[i] += arr2[i];
        }
    }
    void Sub()
    {
        cout << endl;
        for (int i = 0; i < len; i++)
        {
            arr1[i] -= arr2[i];
        }
    }
    void random()
    {
        for (int i = 0; i < len; i++)
        {
            arr[i] = rand() % 10;
        }
        for (int i = 0; i < len; i++)
        {
            arr1[i] = rand() % 10;
        }
        for (int i = 0; i < len; i++)
        {
            arr2[i] = rand() % 10;
        }
    }
    void push_back(int value)
    {
        if (value >= -100 && value <= 100)
        {
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
};
int main()
{
    MasClass a(2);
    return 0;
}