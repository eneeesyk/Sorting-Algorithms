#include <stdio.h>


int swap(int* a, int idx1, int idx2)
{
    int tmp = a[idx1];

    a[idx1] = a[idx2];
    a[idx2] = tmp;
    return 0;
}

int partition(int* a,int first,int last,int pivot_idx)
{
    int first_s1= first;
    int last_s1 = first;
    int first_unknown = first +1;
    for (; first_unknown <= last;first_unknown++) {
        if (a[first_unknown] < a[pivot_idx]) {
            last_s1++;
            swap(a, first_unknown, last_s1);
        }
    }

    swap(a, first, last_s1);
    return last_s1;
}

int quick_sort(int* a, int first, int last){
    if (first >= last) return 0;//base

    int pivot = first;

       int pivot_idx = first;
       pivot_idx = partition(a, first, last, pivot);

    quick_sort(a, first, pivot_idx -1);
    quick_sort(a, pivot_idx+1, last);


}

int main() {

    int a[] = {8,5,2,7,9,3,1,4};
    quick_sort(a, 0, 7);

    for (int i = 0; i < 8; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
