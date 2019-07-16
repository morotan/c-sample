#include <stdio.h>
#define N 100

void main() {
  //Nまでの素数を表示
  int i, n, m;
  int data[N + 1], result[N + 1];
  //配列data[]すべてに１を代入
  for (i = 0; i < N+1; i++){
    data[i] = 1;
  }
  //0と1は素数から除外
  data[0] = 0;
  data[1] = 0;
  //素数の始めを２とする
  m = 2;
  //素数の数
  n = 0;
  do {
    //素数の倍数をリストdata[]から削除
    for (i = 2 * m; i < N + 1; i += m) {
      data[i] = 0;
    }
    //結果を格納
    result[n] = m;
    n++;
    //次の素数候補を見つける
    do {
      m++;
    } while (data[m] == 0 && m < N + 1);
  } while (m < N + 1);
  //結果の出力
  for (i = 0; i < n; i++){
    //10行ごとに改行タグを入れる
    printf("%d ", result[i]);
    if ((i+1) % 10 == 0){
      printf("\n");
    }
  }
  printf("\n");
}
