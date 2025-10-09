#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void shellSort(int *arr, int n)
{
    int num=0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        num++;
        cout<<"After pass "<<num<<" :";
        printArr(arr, 6);
    }
}

int main() {
    int arr[] = {205, 102, 310, 450, 120, 90};

    shellSort(arr, 6);
}