#include <stdio.h>

//#define MAX_LENGTH 5

#define MAX_LENGTH 8

void showData(int*, int);

void main(){
  int array[MAX_LENGTH] = {41,23,55,36,14,32,59,90};
  int i, j, step, tmp;
  //飛ばしていく数を設定
  step = MAX_LENGTH / 2;
  while(step > 0){
    //途中の結果
    showData(array, MAX_LENGTH);
    for(i=0; i < MAX_LENGTH; i++){
      j = i;
      tmp = array[i]; //array[i]は値が変わるのでtmpに置き換える　　　　　　　　　　　　　　　
      //定められた範囲内での順序入れ替え（先頭まで探索）
      while(j>=step && array[j-step] < tmp){
        array[j] = array[j-step];
        j-=step;  //jを対照要素位置にする。
        //showData(array, MAX_LENGTH);
      }
      array[j] = tmp;  //このｊはj-stepの位置です。非常にわかりづらい。
    }
    step /= 2;  //探索範囲を半分にする。
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
