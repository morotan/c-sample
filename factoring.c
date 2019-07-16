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
  //素因数分解する数値を入力
  int num, j;
  int pf[N+1];
  printf("素因数分解する%dまでの数値：", N);
  scanf("%d", &num);
  if (N > num){
    m=num;
    i=0;
    j=0;
    do {
      if(num%result[i] == 0){
        num = num/result[i];
        pf[j] = result[i];
        j++;
      }
      else{
        i++;
      }
    } while (num > 1 || i < n);
  }
  else{
    printf("数値が大きすぎる\n");
  }
  //結果の出力
  printf("結果：%d= ", m);
  for (i = 0; i < j; i++){
    //素因数分解の出力
    if (i==0){
      printf("%d", pf[i]);
    }
    else {
      printf("☓%d", pf[i]);
    }
  }
  printf("\n");
}
