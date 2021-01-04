#include <stdio.h>

int buf[100];

int merge(int* a, int first, int mid, int last)
{
    printf("merge [%d:%d:%d]\n",first,mid, last);

    printf("unsorted ");
    for (int i = first; i <= last; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");

    int f1 = first;
    int l1 = mid;
    int f2 = mid+1;
    int l2 = last;
    int index;

    for (index = 0; f1<=l1 && f2<=l2;) {
        if (a[f1]<a[f2])
            buf[index++] = a[f1++];
        else
            buf[index++] = a[f2++];
    }

    for (int i = f1; i <= l1; i++)
        buf[index++] = a[i];
    for (int i = f2; i <= l2; i++)
        buf[index++] = a[i];
    //copy buff
    for (int i = 0; i < index; i++) {
        a[first + i] = buf[i];
    }
    printf("sorted ");
    for (int i = first; i <= last; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n-------------------");
    printf("\n");
    return 0;
}


int merge_sort(int* a, int first, int last)
{
    for (int i = first; i < last; i++) {
        printf("%d ",a[i]);
        printf("\n");
    }

    if(first >= last){
        return 0;
    }
    int mid = (first + last)/2;
    merge_sort(a, first, mid);
    merge_sort(a, mid+1, last);

    return merge(a, first, mid, last);
}

int main(){
    int array[] = {8,5,2,7,9,3,1,4};
    merge_sort(array, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d",array[i]);
    }
    printf("\n");

    return 0;
}