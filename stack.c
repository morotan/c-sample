#include <stdio.h>
//配列の大きさ
#define MAX_LENGTH 100
//スタック格納配列の用意
typedef struct {
  int array[MAX_LENGTH];  //データ格納配列
  int current;  //現在の位置
} STACK;

//スタックの初期化
void init(STACK*);
//値のプッシュ
int push(STACK*, int);
//値のポップ
int pop(STACK*, int*);

void main() {
  STACK s;
  int value, i;
  //スタックの初期化
  init(&s);
  //1,2,3の順に値をプッシュ
  for(i=1; i<=3; i++) {
    push(&s, i);
  }
  //値をポップ
  while(pop(&s, &value)) {
    printf("%d ", value);
  }
  printf("\n");
}

//スタックの初期化
void init(STACK* pStack){
  int i;
  for(i=0; i<MAX_LENGTH; i++){
    pStack->array[i] = 0;
  }
  pStack->current = 0;
}

//値のプッシュ
int push(STACK* pStack, int value){
  //蓄積されたデータに空きがあるかどうか
  if(pStack->array[pStack->current] < MAX_LENGTH){
    //空いているところにデータを格納
    pStack->array[pStack->current] = value;
    //格納場所を一つずらす
    pStack->current++;
    return 1;
  }
  //データを格納しきれなかった
  return 0;
}

//値のポップ
int pop(STACK* pStack, int* pValue){
  //格納されたデータがある場合
  if(pStack->current > 0){
    //格納されたデータに移動
    pStack->current--;
    *pValue = pStack->array[pStack->current];
    return 1;
  }
  //格納されたデータはない
  return 0;
}
