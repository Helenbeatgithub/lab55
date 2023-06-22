/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[],int low,int high);

void swap(int *a, int *b){
    int t= *a;
    *a = *b;
    *b = t;
}

void quicksort(int array[], int length){
    srand(time(NULL));
    quicksort_recursion(array, 0, length-1);
}

void quicksort_recursion(int array[], int low, int high){
    if(low<high)
    {
    //mid
    int pivot_index = partition(array, low, high);
    //left
    quicksort_recursion(array, low, pivot_index-1);
    //high
    quicksort_recursion(array, pivot_index+1, high);
    }
     
}

int partition(int array[], int low, int high){
    int pivot_index = low + (rand()% (high - low));
    
    if (pivot_index != high)
        swap(&array[pivot_index], &array[high]);
    
    int pivot_value = array[high];
    
    int i = low;
    
    for (int j = low; j<high; j++){
        if(array[j] < pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    
    swap(&array[i], &array[high]);
    return i;
}

int main()
{
    printf("Input array:");
    printf("2, 10, 56, 19, -4, 5, 7, 9");
    printf("\n");
    
    
    printf("Output array:");
    int array[] = {2, 10, 56, 19, -4, 5, 7, 9};
    int length = 8;
    

    quicksort(array, length);
    
     for (int i = 0; i < length; i++){
        printf("%d",  array[i]);
        if (i<length-1){
            printf(",");
        }
     }
    
        
    printf("\n");

    return 0;
}
