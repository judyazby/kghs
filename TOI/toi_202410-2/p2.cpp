#include <bits/stdc++.h>
#define MAXN 18
// #define DEBUG
using namespace std;

/*
  其實他是相鄰不同色的著色問題。顏色aka組別。
  3著色問題是np-complete，沒有多項式時間的解法。
  先以無向圖存放所有的點及其鄰居。
  接著，遞迴窮舉3^n種可能性。
  當組合完畢，檢查點有沒有跟鄰居顏色重複？
  重複的話為不合理的解（剪枝），否則為合理的解。
  因為n非常小，最高3^16種組合，實際上不會剛好120條邊
  檢查到一半發現顏色不夠會剪枝，因此時間複雜度不會超過。
*/

vector<int> nei[MAXN];
int arr[MAXN];  // 紀錄每個學生分別在第幾組（1~3）
int permutation(int n, int arr[], int now){
  if(now == n){ // 分組完畢
#ifdef DEBUG
    for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
#endif
    bool ok = true;
    for(int i = 0; i < n && ok; i++){
      ok = true;
      for(int j = 0; j < nei[i].size(); j++){
        int v = nei[i][j];
        if(arr[v] == arr[i]){ // 自己不能跟任何鄰居一樣
          ok = false;
          break;
        }
      }
    }
    if(!ok){  // 要取最小值，回傳一個不合理的大數
      return 20;  // n <= 16，不可能差20個人
    }else{
      // 不能邊檢查邊加，因為每個人被連到的次數不同
      int ppl[3] = {0};
      for(int i = 0; i < n; i++)  ppl[arr[i]]++;
#ifdef DEBUG
      cout << "WOW ok ";
      for(int i = 0; i < 3; i++)
        cout << ppl[i] << " \n"[i==2];
#endif
      int mn = 20, mx = 0;
      for(int i = 0; i < 3; i++){
        mn = min(mn, ppl[i]);
        mx = max(mx, ppl[i]);
      }
#ifdef DEBUG
      cout << mx-mn << endl;
#endif
      return mx-mn;
    }
  }else{
    int mn = 20;
    for(int i = 0; i < 3; i++){
      arr[now] = i;
      mn = min(mn, permutation(n, arr, now+1));
    }
    return mn;
  }
}
int main(){
  int n, m, x, y;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    nei[x-1].push_back(y-1);
    nei[y-1].push_back(x-1);
  }
  int ans = permutation(n, arr, 0);
  if(ans == 20) cout << -1 << endl;
  else  cout << ans << endl;
  return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
1 5

4 6
1 2
1 3
1 4
2 3
2 4
3 4

6 1
1 2
*/