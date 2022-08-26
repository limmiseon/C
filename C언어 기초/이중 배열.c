#include <stdio.h>

int main() {
  int arr[2][5] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10}
  };

  int i, j;
  int rowLength = sizeof(arr) / sizeof(arr[0]);
  // rowLength = 40 / 20 = 2
  int columnLength = sizeof(arr[0]) / sizeof(arr[0][0]);
  // columnLength = 20 / 4 = 5
  int result = 0;

  for(i = 0; i < rowLength; i++) {
    for(j = 0; j < columnLength; j++) {
      result += arr[i][j];
    }
  }

  printf("%d", result);

  return 0;
}