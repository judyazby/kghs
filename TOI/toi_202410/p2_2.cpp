#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin >> t;
  int a = t*3;
  int b = 299+max(0, (t-300)*3);
  int c = 699+max(0, (t-750)*3);
  cout << min(a, min(b, c)) << endl;
  return 0;
}