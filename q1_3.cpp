// Pure Prim Implementation
// 裸Prim. 反正图不大点不多就暴力了暴力 过了就 ok
// 节点编号从1开始0.0, 坑了一发
// 初始化忘了自己到自己距离设为0, 坑连打 /w\...

#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i, l, r) for (int (i) = l; i < r; i ++)
#define ll long long
#define N 505

int rmap[N][N];
int lowcost[N];
int n, m;

int prim(int v0)
{
  int ans = 0;

  rep(i, 0, n)
    lowcost[i] = rmap[v0][i];

  rep(i, 0, n-1) {
    int rmin = 0x7fffffff;
    int pos;
    rep(j, 0, n) {
      if (lowcost[j] && lowcost[j] < rmin) {
        rmin = lowcost[j];
        pos = j;
      }
    }
    ans += rmin;
    lowcost[pos] = 0;

    rep(j, 0, n)
      if (lowcost[j] > rmap[pos][j] && lowcost[j])
        lowcost[j] = min(lowcost[j], rmap[pos][j]);
  }

  return ans;
}

int main()
{
  cin >> n >> m;
  memset(rmap, 0x7f, sizeof rmap);
  rep(i, 0, n) rmap[i][i] = 0;
  int v1, v2, w;

  while (m --) {
    cin >> v1 >> v2 >> w;
    v1 --;
    v2 --;
    rmap[v1][v2] = w;
    rmap[v2][v1] = w;
  }

  cout << prim(0) << endl;

  return 0;
}
