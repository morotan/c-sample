#include <stdio.h>

#define MAX_LENGTH 5

void showData(int*, int);

void main(){
  int array[MAX_LENGTH] = {5, 2, 3, 1, 4};
  int i, j, tmp;
  //先頭２つの要素のループ
  for(i=1; i < MAX_LENGTH; i++){
    //配列の表示
    showData(array, MAX_LENGTH);
    j = i;
    //定められた範囲内での順序入れ替え（先頭まで探索）
    while(j>=1 && array[j-1] < array[j]){
      tmp = array[j-1];
      array[j-1] = array[j];
      array[j] = tmp;
      j--;
      showData(array, MAX_LENGTH);
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
