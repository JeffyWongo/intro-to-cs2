#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0)
    {
        return nullptr;
    }
    if(arrSize == 1)
    {
        return arr;
    }
    else
    {
        const int* tempmin = min(arr, arrSize - 1);
        if(arr[arrSize - 1] < *tempmin)
        {
            return arr + arrSize - 1;
        }
        else
        {
            return tempmin;
        }
    }
}