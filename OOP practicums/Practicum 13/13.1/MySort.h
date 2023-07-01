#pragma once
#include <cstring>

template <typename T>
void sortt(T* arr, int n)
{
	T key;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
	}
}

template<>
inline void sortt<char>(char arr[], int n)
{
    char output[strlen(arr)];
    int count[255 + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; arr[i]; ++i)
    {
        ++count[arr[i]];
    }

    for (i = 1; i <= 255; ++i)
    {
        count[i] += count[i - 1];
    }


    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

