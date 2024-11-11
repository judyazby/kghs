#include <bits/stdc++.h>
#define MAXN 105
using namespace std;
int p[MAXN];
int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> p[i];
  int x, g, t = 0;
  while(cin >> x >> g){
    if(x == 0 && g == 0)
      break;
    t += p[x]*g;
  }
  cout << t << endl;
  return 0;
}