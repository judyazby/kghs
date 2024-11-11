#include <bits/stdc++.h>
using namespace std;
int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(){
  int m1, d1, m2, d2;
  cin >> m1 >> d1 >> m2 >> d2;
  int t1 = 0, t2 = 0;

  int cnt = 1;
  while(cnt != m1){
    t1 += d[cnt++];
  }
  t1 += d1;

  cnt = 1;
  while(cnt != m2){
    t2 += d[cnt++];
  }
  t2 += d2;
  cout << (t2+365-t1)%365 << endl;
  return 0;
}


/*
  回憶我是電視迷：
  5~10台：轉10-5次
  10~5台：轉(5+100)-10次
  總結：轉(t2+100-t1)%100次
*/