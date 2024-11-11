#include <bits/stdc++.h>
using namespace std;
int main(){
  int a[2][5];
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 5; j++)
      cin >> a[i][j];
  int output = -1, next = 0;
  while(output != 0){
    if(a[next][0] % 3 == 0){
      int mx = 0;
      for(int j = 0; j < 5; j++){
        if(a[next][j] > mx)
          mx = a[next][j];
      }
      output = mx;
      for(int j = 0; j < 5; j++){
        if(a[next][j] == mx)
          a[next][j] /= 2;
      }
    }else{
      int mn = 1005;
      for(int j = 0; j < 5; j++){
        if(a[next][j] != 0 && a[next][j] < mn)
          mn = a[next][j];
      }
      // 非0最小值?!都是0怎麼辦？！
      if(mn == 1005)  mn = 0;

      output = mn;
      for(int j = 0; j < 5; j++){
        if(a[next][j] == mn)
          a[next][j] -= 1;
      }
      
    }
    cout << output << endl;
    if(output == 0) break;
    if(output % 2)  next = 0;
    else  next = 1;
  }
  return 0;
}