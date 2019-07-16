#include <stdio.h>

void main() {
  int m, n, d, i = 0;

  printf("最大公約数の計算\n数値１（整数）:");
  scanf("%d", &m);
  printf("数値２（整数）:");
  scanf("%d", &n);
  // m < nなら入れ替え
  if(m < n) {
    int tmp = m;
    n = m;
    n = tmp;
    //printf("割る数が大きいため数値を入れ替え\n");
  }
  do {
    //ユークリッド互除法による
    d = m % n;
    m = n;
    n = d;
    //if(i > 1000){
    //  break;
    //}
    i = i + 1;
  } while (d != 0);
  //if (d == 0){
    printf("最大公約数は%d\n", m);
  //}
  //else {
  printf("%d回計算\n", i);
  //}
}
