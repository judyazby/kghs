#include <iostream>
using namespace std;
int main(){
  int l, w, h, k;
  cin >> l >> w >> h >> k;
  if (!(l%k || w%k || h%k))
    cout << (l*w*h)/(k*k*k);
  else
    cout << 0;
  return 0;
}