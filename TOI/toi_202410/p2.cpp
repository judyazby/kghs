#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  if(t*3 < 299) cout << t*3;
  else if(t <= 300) cout << 299;
  else if(299 + (t-300)*3 <= 699)
    cout << 299 + (t-300)*3;
  else if(t <= 750) cout << 699;
  else  cout << 699+(t-750)*3;
  cout << endl;
  return 0;
}