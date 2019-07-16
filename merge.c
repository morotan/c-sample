#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 8

void merge_sort(int*, int, int);
void showData(int*, int);

void main(){
  int array[MAX_LENGTH] = {55, 13, 3, 45, 74, 87, 46, 30};
  showData(array, MAX_LENGTH);
  merge_sort(array, 0, MAX_LENGTH-1);
}

void merge_sort(int* pArray, int start, int end){
  //作業用配列（再帰呼び出しをするためstaticで定義する）
  static int tmp[MAX_LENGTH];
  //作業用データ
  int middle, i, j, k;
  if(start>=end){
    return;
  }
  //startとendの中間位置を分割点とする
  middle = (start + end) / 2;
  //前半部分を再帰的に整列
  merge_sort(pArray, start, middle);
  //後半部分を再帰的に整列
  merge_sort(pArray, middle+1, end);
  //仮想領域のデータをマージしながらコピーする
  k=0;
  for(i=start; i<=middle; i++){ //先頭から大きい順
    tmp[k] = pArray[i];
    k++;
  }
  for(j=end; j>=middle+1; j--){ //末端から大きい順
    tmp[k] = pArray[j];
    k++;
  }
  //末端からデータを取得してマージしていく
  i=0;
  j=end-start;
  for(k=start; k<=end; k++){
    if(tmp[i] < tmp[j]){  //末端が大きい
      pArray[k] = tmp[j]; //末端から先頭へ
      j--;  //次の末端
    }
    else{ //先頭が大きい
      pArray[k] = tmp[i]; //先頭から先頭へ
      i++;  //次の先頭
    }
  }
  //結果を出力
  showData(pArray, MAX_LENGTH);
}

void showData(int* array, int length) {
  int i;
  for(i=0; i<length; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}
