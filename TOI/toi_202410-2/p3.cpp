#include <bits/stdc++.h>
#define MAXN 102
#define MAXW 100005
int w[MAXN];
int dp[MAXN][MAXW];
using namespace std;
int main(){
  int n, s = 0;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> w[i];
    s += w[i];
  }
  if(s%2) cout << 0 << endl;
  else{
    int W = s/2;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= W; j++){
        if(w[i] <= j)
          dp[i][j] = max(dp[i-1][j-w[i]]+w[i], dp[i-1][j]);
        else
          dp[i][j] = dp[i-1][j];
      }
    }
    if(dp[n][W] == W) cout << 1 << endl;
    else  cout << 0 << endl;
  }
  return 0;
}