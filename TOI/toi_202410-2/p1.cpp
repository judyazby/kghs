#include <bits/stdc++.h>
#define MAXN 200005
struct File{
  int a, b, c, d;
};
File fs[MAXN];
struct Click{
  int type, last;
  bool dec, clk;
};
Click ck[4];

bool tcmp(Click x, Click y){
  return x.last < y.last;
}

using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> fs[i].a >> fs[i].b >> fs[i].c >> fs[i].d;
  int next = 0, prev = 0;
  for(int i = 0; i < 4; i++){
    ck[i].dec = 0;
    ck[i].clk = 0;
  }
  for(int i = 0; i < k; i++){
    cin >> next;
    ck[next-1].type = next;
    ck[next-1].last = i;
    ck[next-1].clk = true;

    if(i != 0 && prev == next){
      ck[next-1].dec = 1-ck[next-1].dec;
    }else{
      ck[next-1].dec = false;
    }
    prev = next;
  }
  sort(ck, ck+4, tcmp);
  for(int i = 0; i < 4; i++){
    if(!ck[i].clk)  continue;
    if(ck[i].type == 1){
      if(!ck[i].dec)
        sort(fs, fs+n, [](File& x, File& y){
          return x.a < y.a;
        });
      else{
        sort(fs, fs+n, [](File& x, File& y){
          return x.a < y.a;
        });
        sort(fs, fs+n, [](File& x, File& y){
          return x.a > y.a;
        });
      }
    }else if(ck[i].type == 2){
      if(!ck[i].dec)
        sort(fs, fs+n, [](File& x, File& y){
          return x.b < y.b;
        });
      else{
        sort(fs, fs+n, [](File& x, File& y){
          return x.b < y.b;
        });
        sort(fs, fs+n, [](File& x, File& y){
          return x.b > y.b;
        });
      }
    }else if(ck[i].type == 3){
      if(!ck[i].dec)
        sort(fs, fs+n, [](File& x, File& y){
          return x.c < y.c;
        });
      else{
        sort(fs, fs+n, [](File& x, File& y){
          return x.c < y.c;
        });
        sort(fs, fs+n, [](File& x, File& y){
          return x.c > y.c;
        });
      }
    }else{
      if(!ck[i].dec)
        sort(fs, fs+n, [](File& x, File& y){
          return x.d < y.d;
        });
      else{
        sort(fs, fs+n, [](File& x, File& y){
          return x.d < y.d;
        });
        sort(fs, fs+n, [](File& x, File& y){
          return x.d > y.d;
        });
      } 
    }
  }
  for(int i = 0; i < n; i++){
    cout << fs[i].a << " " << fs[i].b << " " << fs[i].c << " " << fs[i].d << endl;
  }
  return 0;
}