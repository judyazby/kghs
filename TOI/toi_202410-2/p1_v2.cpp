#include <bits/stdc++.h>
#define MAXN 200005

/*
  每點選一次就排序一次，時間複雜度會爆炸。
  值得注意的是，不點、升序再降序結果相同。
  同理，點一次、升序再降序再升序結果相同。
  因此，僅需觀察每個屬性最後一次點擊是在第幾次。
  又因為寫4種屬性*2種排序和點擊次數排序的比較函式，
  加總快要20種很崩潰，所以設定結構屬性時可嘗試簡化。
*/


// 定義四個屬性。為了後面輸入、寫比較函式方便，定義為陣列
struct File{
  int attr[4];
};
/* 定義點擊狀態。
type：代表第幾個屬性，配合陣列索引值，平移成0~3
last：最後一次是在第幾次點擊出現
dec：是否為降序排列
*/
struct Click{
  int type, last;
  bool dec;
};
Click ck[4];  // 四種屬性的點擊狀態

/*
  如果不用匿名函式的話，用這個版本。
  以最後一次點擊的次數來排序，越前面越先排
*/
// bool tcmp(Click x, Click y){
//   return x.last < y.last;
// }

File fs[MAXN];  // 所有檔案的屬性資訊
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++)
      cin >> fs[i].attr[j];
  }
  int next = 0, prev = 0;
  for(int i = 0; i < 4; i++){
    ck[i].dec = false;
    ck[i].last = -1; // 沒被點過
  }
  for(int i = 0; i < k; i++){
    cin >> next;
    ck[next-1].type = next-1;
    ck[next-1].last = i;

    if(i != 0 && prev == next){ // 有連續點擊
      ck[next-1].dec = 1-ck[next-1].dec;
    }else{ // 非連點，為升序排列
      ck[next-1].dec = false;
    }
    prev = next;
  }
  /*
    匿名函式版本。
    以最後一次點擊的次數來排序，越前面越先排。
    為處理重複值，需使用stable_sort而非sort
  */
  stable_sort(ck, ck+4, [](const Click &x, const Click y){
    return x.last < y.last;
  });
  // stable_sort(ck, ck+4, tcmp);
  for(int i = 0; i < 4; i++){
    // 沒被點過，略過不處理排序
    int dec = ck[i].dec, type = ck[i].type;
    if(ck[i].last == -1)  continue; 
    /*
      dec：第 i 個（依最後出現時間點排序）點擊是否為降序
      type：第 i 個（依最後出現時間點排序）點擊是第幾個屬性
      檔案會根據是第幾個屬性，在匿名函式以升序或降序排列
      
      然後匿名函式也可以先寫在外面，再放入內建排序函式！
      ref: https://dangerlover9403.pixnet.net/blog/post/212984595
    */
    auto cmp = [dec, type](const File &x, const File &y){
      if(!dec)
        return x.attr[type] < y.attr[type];
      else
        return x.attr[type] > y.attr[type];
      /*
        簡化寫法：
        return dec == (x.attr[type] > y.attr[type]);
      */
    };
    // 為處理重複值，需使用stable_sort而非sort
    stable_sort(fs, fs+n, cmp);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++)
      cout << fs[i].attr[j] << " \n"[j==3];
  }
  return 0;
}
/*
5 3
1 100 1 24
11 2015 3 1024
30 3030 1 256
2 366 3 4096
34 2533 2 65536
1 3 3

3 7
1 2 5 8
2 4 6 9
3 3 6 7
2 2 2 3 3 3 3
*/