#include <stdio.h>

#define MAX_LENGTH 5

void showData(int*, int);

void main(){
  int array[MAX_LENGTH] = {5, 2, 3, 1, 4};
  int i, j, tmp;
  //先頭の要素のループ
  for(i=0; i < MAX_LENGTH-1; i++){
    //配列の表示
    showData(array, MAX_LENGTH);
    for(j=i+1; j < MAX_LENGTH; j++){
      if(array[i] < array[j]){
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
  showData(array, MAX_LENGTH);
}

void showData(int* array, int length){
  int i;
  for(i=0; i < length; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}
