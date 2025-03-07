#include <stdio.h>



int main() {
int arr[] = {1, 2, 3, 4, 5};
int len = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < len; i++) {
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}