#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
int partition(int *arr, int lower_ind, int upper_ind)
{
=======
int partition(int* arr, int lower_ind, int upper_ind) {
>>>>>>> d03427783b37ef659bf3e11397b1b91f6a31f6a1
    int l = lower_ind;
    int u = upper_ind;
    int pivot = arr[lower_ind];
    int temp;
<<<<<<< HEAD
    while (1)
    {
        while (l <= upper_ind && arr[l] <= pivot)
        {
            ++l;
        }
        while (u >= lower_ind && arr[u] > pivot)
        {
            --u;
        }
        if (l >= u)
        {
=======
    while (1) {
        while (l <= upper_ind && arr[l] <= pivot) {
            ++l;
        }
        while (u >= lower_ind && arr[u] > pivot) {
            --u;
        }
        if (l >= u) {
>>>>>>> d03427783b37ef659bf3e11397b1b91f6a31f6a1
            break;
        }
        temp = arr[l];
        arr[l] = arr[u];
        arr[u] = temp;
    }
    temp = arr[lower_ind];
    arr[lower_ind] = arr[u];
    arr[u] = temp;
    return u;
}

<<<<<<< HEAD
void quick_sort(int *arr, int lower_ind, int upper_ind)
{
    if (lower_ind < upper_ind)
    {
=======
void quick_sort(int* arr, int lower_ind, int upper_ind) {
    if (lower_ind < upper_ind) {
>>>>>>> d03427783b37ef659bf3e11397b1b91f6a31f6a1
        int pivot_ind = partition(arr, lower_ind, upper_ind);
        quick_sort(arr, lower_ind, pivot_ind - 1);
        quick_sort(arr, pivot_ind + 1, upper_ind);
    }
}

<<<<<<< HEAD
int main()
{
    int arr[] = {3, 5, 8, 9, 4};

    printf("Unsorted array :\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
=======
int main() {
    int arr[] = {3, 5, 8, 9, 4};

    printf("Unsorted array :\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
>>>>>>> d03427783b37ef659bf3e11397b1b91f6a31f6a1
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array :\n");
    quick_sort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
<<<<<<< HEAD
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
=======
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
>>>>>>> d03427783b37ef659bf3e11397b1b91f6a31f6a1
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}