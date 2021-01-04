#include <stdio.h>

int get_max(int* a) {
    int mx = a[0];
    int i;
    for (i = 1; i < 8; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
void radix_sort (int* a, int n) {
    int bucket[10][10], bucket_cnt[10];
    int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
    lar = get_max(a);
    while (lar > 0) {
        NOP++;
        lar /= 10;
    }
    for (pass = 0; pass < NOP; pass++) {
        for (i = 0; i < 10; i++) {
            bucket_cnt[i] = 0;
        }
        for (i = 0; i < n; i++) {
            r = (a[i] / divisor) % 10;
            bucket[r][bucket_cnt[r]] = a[i];
            bucket_cnt[r] += 1;
        }
        i = 0;
        for (k = 0; k < 10; k++) {
            for (j = 0; j < bucket_cnt[k]; j++) {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}

int main() {

    int array[] = {8,5,2,7,9,3,1,4};
    radix_sort(array, 8);

    for (int i = 0; i < 8; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");


    return 0;
}