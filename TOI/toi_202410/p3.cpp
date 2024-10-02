#include <iostream>
using namespace std;

int nprime(int n){
  int p = 0;  // 1和自己
  for(int i = 1; i <= n; i++){
    if(n%i == 0)  p++;
  }
  return p;
}

int main(){
  int x, y;
  cin >> x >> y;
  int n = y, m = 2, temp;
  for(int i = y-1; i >= x; i--){
    temp = nprime(i);
    if(temp >= m){
      n = i;
      m = temp;
    }
  }
  cout << n << " " << m << endl;
  return 0;
}