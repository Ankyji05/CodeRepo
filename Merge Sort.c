/*******************************************************************************/

// merge sort

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int arr1 = m - l + 1;
    int arr2 = r-m;
    
    int leftArray[arr1], rightArray[arr2];
    
    for (int i=0; i < arr1; i++)
    {
        leftArray[i] = arr[l + i];
    }
    for (int j=0; j < arr2; j++)
    {
        rightArray[j] = arr[m+j+1];
    }
    
    
    int i = 0;
    int j = 0;
    int k = l;
    while(i < arr1 && j < arr2)
    {
        if(leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    while(i < arr1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while(j < arr2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}




void mergeSort(int arr[], int l, int r )
{
    if(l < r )
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    for(int i=0; i< size; i++)
    {
        printf("%d ",A[i]);
    }
}

int main()
{
    int arr[20],size;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    printf("Enter the elements in the array.");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,size-1);
    printf("Sorted array is :");
    printArray(arr,size);
    return 0;
}
