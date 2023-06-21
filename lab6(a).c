/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]


void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int sizeOfLeft = m-l+1;
    int sizeOfRight = r-m;
    
    // Create temp arrays
    int LeftHalf[sizeOfLeft], RightHalf[sizeOfRight];


  // Copy data to temp arrays LeftHalf[] and RightHalf[]
    for (i = 0; i < sizeOfLeft; i++)
        LeftHalf[i] = array[l + i];
    
    for (j = 0; j < sizeOfRight; j++)
        RightHalf[j] = array[m+1 + j];
    
    // Merge the temp arrays back into array[left..right]   
i=0;
j=0;
k=l; // Initial index of merged subarray

while( i < sizeOfLeft && j < sizeOfRight){
    if(LeftHalf[i] <= RightHalf[j]){
        array[k] = LeftHalf[i];
        i++;
    }
    else{
        array[k] = RightHalf[j];
        j++;
    }
    k++;
}

// Copy the remaining elements of L[], if there are any
while (i< sizeOfLeft){
    array[k] = LeftHalf[i];
    i++;
    k++;
}

    // Copy the remaining elements of RightHalf[], if there are any
    while (j < sizeOfRight) {
        array[k] = RightHalf[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right){
    if(left < right){
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left)/2;

        // Sort first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);

        merge(array, left, mid , right);
    }
}

void printArray(int array[], int arraySize){
    int index;
    for (index = 0; index < arraySize; index++){
        printf("%d", array[index]);
        if(index < arraySize-1){
        printf(",");
        }
    }
    printf("\n");
}
    

int main()
{
    int array[] = {2, 10, 56, 19, -4, 5, 7, 9};
    int arraySize = sizeof(array) / sizeof(array[0]);

    printf("Given array is \n");
    printArray(array, arraySize);

    mergeSort(array, 0 , arraySize - 1);

    printf("\nSorted array is \n");
    printArray(array, arraySize);

    return 0;
}
