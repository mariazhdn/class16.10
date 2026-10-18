#include <iostream>
#include <string>
using namespace std;

typedef unsigned int uint;

class Sorting
{
    int* arr;
    uint size;

    public:
    Sorting() : arr(nullptr), size(0) {}

    Sorting(const int* _arr, uint n) : size(n) 
    {
        if (n > 0 && _arr != nullptr)
        {
            arr = new int[n];
            for (uint i = 0; i < n; ++i)
            {
                arr[i] = _arr[i];
            }
        }
        else
        {
            arr = nullptr;
            size = 0;
        }
    }

    ~Sorting() 
    {
        delete[] arr;
    }

    void stupid_sort_asc() 
    {
        if (arr == nullptr || size <= 1) return;

        int temp;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                i = -1;
            }
        }
    }

    void stupid_sort_desc() 
    {
        if (arr == nullptr || size <= 1) return;

        int temp;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                i = -1;
            }
        }
    }

    bool is_sort(const string& type = "asc")
    {
        if (arr == nullptr || size == 0)
        {
            throw invalid_argument("arr == nullptr або size == 0");
        }

        if (type == "asc")
        {
            for (uint i = 0; i < size - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    return false;
                }
            }
        }
        else if (type == "desc")
        {
            for (uint i = 0; i < size - 1; i++)
            {
                if (arr[i] < arr[i + 1])
                {
                    return false;
                }
            }
        }
        else 
        {
            throw invalid_argument("invalid type");
        }

        return true;
    }

    void print() const 
    {
        if (arr == nullptr || size == 0)
        {
            cout << "Array is empty\n";
            return;
        }
        for (uint i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int init_arr[] = { 1,0,5,6,4 };
    uint n = 5;

    Sorting sorter(init_arr, n);

    cout << "Array at first: ";
    sorter.print();

    sorter.stupid_sort_asc();
    cout << "Ascending order: "; 
    sorter.print();

    sorter.stupid_sort_desc();
    cout << "Descending order: ";
    sorter.print();

    return 0;
}