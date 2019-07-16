#include <stdio.h>
//配列の大きさ
#define MAX_LENGTH 100
//スタック格納配列の用意
typedef struct {
  int array[MAX_LENGTH];  //データ格納配列
  int first;  //最初の位置
  int last;  //最後の位置
}QUEUE;

//キューの初期化
void init(QUEUE*);
//値のエンキュー
int enqueue(QUEUE*, int);
//値のデキュー
int dequeue(QUEUE*, int*);

void main() {
  QUEUE q;
  int value, i;
  //スタックの初期化
  init(&q);
  //1,2,3の順に値をプッシュ
  for(i=1; i<=3; i++) {
    enqueue(&q, i);
  }
  //値をポップ
  while(dequeue(&q, &value)) {
    printf("%d ", value);
  }
  printf("\n");
}

//スタックの初期化
void init(QUEUE* pQueue){
  int i;
  for(i=0; i<MAX_LENGTH; i++){
    pQueue->array[i] = 0;
  }
  pQueue->first = 0;
  pQueue->last = 0;
}

//値のプッシュ
int enqueue(QUEUE* pQueue, int value){
  //lastの次の格納場所がfirstならば失敗
  if((pQueue->last + 1) % MAX_LENGTH == pQueue->first){
    return 0;
  }
  //キューに新しい値を入れる
  pQueue->array[pQueue->last] = value;
  //キューのlast位置を更新
  pQueue->last = (pQueue->last + 1) % MAX_LENGTH;
  return 1;
}

//値のポップ
int dequeue(QUEUE* pQueue, int* pValue){
  //キューにデータがない場合
  if(pQueue->first == pQueue->last){
    return 0;
  }
  //先頭から値を取り出す
  *pValue = pQueue->array[pQueue->first];
  //キューの先頭を次に移す
  pQueue->first = (pQueue->first + 1) % MAX_LENGTH;
  return 1;
}
