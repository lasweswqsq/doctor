#include <stdio.h>

void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
  }
int min_element(int *array, int l, int r) {
    int pos = l;
    while (l < r) {
      if (array[l] < array[pos])
        pos = l;
      ++l;
    }
    return pos;
  }
void sort(int *array, int n) {
    for (int i = 0; i < n-1 ; ++i) {
      int min_pos = min_element(array, i, n);
      swap(&array[i], &array[min_pos]);
      // Note: If you have difficulty understanding this function, uncomment the following lines, run the code and look at the output.
      // for (int i = 0; i < n; ++i)
      //   printf("%d ", array[i]);
      // printf("\n");
    }
  }
  int main(void) {
    int a[] = {8, 5, 7, 1, 4, 2};
    sort(a, 4);
    for (int i = 0; i < 6; ++i)
      printf("%d ", a[i]);
    printf("\n");
  }
  
  