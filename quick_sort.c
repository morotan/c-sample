#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 7

void quick_sort(int*, int);
void quick_sort_part(int*, int, int);
void swap(int*, int, int);
void showData(int*, int);

void main(){
  int array[MAX_LENGTH] = {4, 2, 5, 6, 1, 9, 3};
  quick_sort(array, MAX_LENGTH);
}

void quick_sort(int* pArray, int size){
  //引数0は左要素、size-1は右要素
  quick_sort_part(pArray, 0 ,size - 1);
}

//部分クイックソート
void quick_sort_part(int* pArray, int left, int right){
  int i, j, pivot;
  //leftがright以上なら処理終了
  if(left >= right){
    return;
  }
  //軸を左端要素の値に設定する
  pivot = pArray[left];
  i = left;   //左要素
  j = right;  //右要素
  while(1){
    while(pArray[i] < pivot){
      //左値が軸より大きい値を探索
      i++;
    }
    while(pArray[j] > pivot){
      //右側が軸より小さい値を探索
      j--;
    }
    //探索が終わったらループを抜ける
    if(i >= j){
      break;
    }
    //入れ替え処理
    swap(pArray, i, j);
  }
  //配列の表示
  showData(pArray, MAX_LENGTH);
  //軸要素から左に２以上要素があれば軸より左の配列を再帰的にソート
  if(left < i-1){
    quick_sort_part(pArray, left, i-1);
  }
  //軸要素から右に２以上要素があれば軸より右の配列を再帰的にソート
  if(right > j+1){
    quick_sort_part(pArray, j+1, right);
  }
}

void swap(int* pArray, int i, int j){
  int tmp = pArray[i];
  pArray[i] = pArray[j];
  pArray[j] = tmp;
}

void showData(int* pArray, int length){
  int i;
  for(i=0; i<length; i++){
    printf("%d ", pArray[i]);
  }
  printf("\n");
}
