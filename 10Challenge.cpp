#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;

int *apply_all(const int array1[], size_t array1_size, const int array2[], size_t array2_size)
{
    int *const new_arr_ptr{new int[array1_size * array2_size]{}};
    vector<int> new_arr_values{};

    unsigned int pos{0};
    for (size_t i{0}; i <= (array1_size - 1); ++i)
        for (size_t k{0}; k <= (array2_size - 1); ++k)
        {
            new_arr_ptr[pos] = array1[i] * array2[k];
            ++pos;
        }

    return new_arr_ptr;
}

void print(const int *const array, size_t array_size, unsigned int array_num)
{
    cout << "\nArray " << array_num << ": [";
    for (size_t i{0}; i <= (array_size - 1); ++i)
        cout << " " << array[i] << " "; // pointer subscript notation or *(array + i)
    cout << "]";
}

int main()
{
    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    print(array1, array1_size, 1);
    print(array2, array2_size, 2);

    int *results = apply_all(array1, 5, array2, 3);
    print(results, 15, 3);

    delete[] results;

    return 0;
}