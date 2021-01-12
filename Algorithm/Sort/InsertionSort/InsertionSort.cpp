#include <iostream>
#include <vector>
using namespace std;

void PrintArr(vector<int> arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

void InsertionSort(vector<int> arr)
{
    // for print array status
    printf("\n--Insertion Sort--\n");
    printf("Initial array\n");
    PrintArr(arr);

    for(int i = 2; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j > 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = key;

        // for print array status
        printf("key = %2d\n", key);
        PrintArr(arr);
    }
}

int main()
{
    int num = 0;

    printf("Enter the size of array: ");
    scanf("%d", &num);

    vector<int> arr(num+1, 0);

    printf("Enter %d numbers: ", num);
    for(int i = 1; i <= num; i++)
        scanf("%d", &arr[i]);
    
    InsertionSort(arr);
}