// Greedy.
// Trick: when (a.w - a.l) == (b.w - b.l)
// /w\...我居然忘记等于的情况了...这么裸这么裸呜呜呜呜...
#include <iostream>
#include <algorithm>
using namespace std;

#define rep(i, l, r) for (int (i) = l; i < r; i ++)
#define MAXN 100000
#define ll long long
struct node{
  int w, l;
} a[MAXN];

bool cmp(struct node a, struct node b) {
  if ((a.w - a.l) == (b.w - b.l)) return a.w > b.w;
  return (a.w - a.l) > (b.w - b.l);
}

int main()
{
  int n;
  ll ans;
  int time;
  while (cin >> n) {
    ans = 0;
    time = 0;
    rep(i, 0, n) cin >> a[i].w >> a[i].l;
    sort(a, a + n, cmp);
    rep(i, 0, n) {
      time += a[i].l;
      ans += time * a[i].w;
    }
    cout << ans << endl;
  }
  return 0;
}
