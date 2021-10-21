/*
There are N persons standing in the queue. They are numbered from 1 to N.
 Hi is the height of the person i. Pi is the number of persons who are taller than i and standing in front of i. 
Given these two arrays H and P, your task is to find the actual order of the queue. 
It is guaranteed that the height of each person will be unique

example
i/p
6
5 3 2 6 1 4
0 1 2 0 3 2

o/p
1 2 3 5 4 6


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; //g++ ll.cpp -o ll.exe  
typedef long double ld;
typedef pair < ll, ll > iii; //all elements to 0   .\ll.exe
const ll mod = 1e9 + 7;

ll n;
struct node {
  ll h;
  ll p;
  ll pos;
};
vector < node > ar;

bool sortby(const node & a,
  const node & b) {
  return (a.h < b.h);

}

vector < ll > g;

void build(ll index, ll l, ll r) {
  if (l == r) {
    g[index] = 1;
    return;
  }

  ll mid = (l + r) / 2;

  build(2 * index, l, mid);
  build(2 * index + 1, mid + 1, r);

  g[index] = g[2 * index] + g[2 * index + 1];
  return;
}

ll query(ll index, ll l, ll r, ll val) {

  if (l == r)
    return l;

  ll mid = (l + r) / 2;

  if (g[2 * index] >= val)
    return (query(2 * index, l, mid, val));

  val = val - g[2 * index];

  return (query(2 * index + 1, mid + 1, r, val));

}

void update(ll index, ll l, ll r, ll pos) {

  if (l > pos || pos > r)
    return;;

  if (l == r) {
    g[index] = 0;

    return;
  }

  ll mid = (l + r) / 2;

  update(2 * index, l, mid, pos);
  update(2 * index + 1, mid + 1, r, pos);
  g[index] = g[2 * index] + g[2 * index + 1];
  return;

}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  ar.resize(n + 1);
  g.resize(4 * n + 4);
  ll a;

  for (ll i = 1; i <= n; i++) {
    cin >> a;
    ar[i].h = a;
    ar[i].pos = i;
  }

  for (ll i = 1; i <= n; i++) {
    cin >> a;
    ar[i].p = a;

  }

  sort(ar.begin() + 1, ar.end(), sortby);
  vector < ll > ans, ans2;
  ans.resize(n + 2);
  ans2.resize(n + 2);
  build(1, 1, n);

  for (ll i = 1; i <= n; i++) {
    ll ans1;
    ans1 = query(1, 1, n, ar[i].p + 1);
    //cout<<ans1<<endl;
    ans[ans1] = ar[i].pos;
    ans2[ans1] = ar[i].h;
    update(1, 1, n, ans1);

  }

  for (ll i = 1; i <= n; i++)
    cout << ans[i] << " ";

  return 0;
}
