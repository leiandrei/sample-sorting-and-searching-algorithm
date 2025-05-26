#include <stdio.h>
#include <stdlib.h>

int *allocated_array(int num);
void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void sort(int *arr, int low, int high);
int recursive_search(int *arr, int low, int high, int target);

int main()
{
    int num, target;

    printf("Enter a number of elements: ");
    scanf("%d", &num);

    int *arr = allocated_array(num);

    if (!arr) {
        return 1;
    }

    printf("\n=== Enter the Elements in the Array ===\n");
    for (int i = 0; i < num; i++) {
        printf("Element[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    sort(arr, num);

    printf("\n=== Search for an Element ===\n");
    printf("Try to search for an element: ");
    scanf("%d", &target);

    int search = recursive_search(arr, 0, num - 1, target);

    if (search != -1) {
        printf("Element %d found at index[%d].\n", target, search);
    } else {
        printf("Element not found in the array.\n");
    }

    free(arr);
    return 0;
}

int *allocated_array(int num)
{
    int *arr = calloc(num, sizeof(int));

    if (!arr) {
        perror("Memory Allocation Failed!");
        return NULL;
    }

    return arr;
}

void sort(int *arr, int num)
{
    for (int i = 1; i < num; i++) {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

int recursive_search(int *arr, int low, int high, int target)
{
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return recursive_search(arr, mid + 1, high, target);
    } else {
        return recursive_search(arr, low, mid - 1, target);
    }
}
