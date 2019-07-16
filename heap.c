#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5

void swap(int*, int, int);
int downheap(int*, int, int);
void showData(int*, int);
void heap_sort(int*, int);

void main(){
  //最初に0を入れるため最大値に+1
  int array[MAX_LENGTH + 1] = {0, 4, 2, 5, 6, 1};
  //ソート処理
  heap_sort(array, MAX_LENGTH);
}

void heap_sort(int* pArray, int size){
  int i = 1;
  showData(pArray, size);
  while(downheap(pArray, i, size)){
    //途中経過を出力
    showData(pArray, size);
    i++;
  }
}

int downheap(int* pArray, int start, int end){
  int parent, child, r = 0;
  //子ノードのスタート位置
  child = end;
  //末端要素から辿り、親要素より値が大きければ入れ替える
  do{
    //親ノードの番号を取得
    parent = start + (child - start) / 2;
    //バイナリツリーの末端が親より大きければ入れ替え
    if(pArray[child] > pArray[parent]){
      swap(pArray, child, parent);
      r = 1;
    }
    child--;  //次の子ノードへ
  }while(parent > start);
  return r;
}

void swap(int* pArray, int m, int n){
  int tmp = pArray[m];
  pArray[m] = pArray[n];
  pArray[n] = tmp;
}

void showData(int* pArray, int length){
  int i;
  for(i = 1; i < length + 1; i++){
    printf("%d ", pArray[i]);
  }
  printf("\n");
}
