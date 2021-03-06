
#include <bits/stdc++.h>
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);
const int M = 1000000007;
// const int M = 998244353;
using ll = long long;
using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k, int m = M) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2, m);
  ax = mod(ax * ax, m);
  if (k % 2) ax = mod(ax * n, m);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

int uf[312345], sz[312345], d[312345];
void init(int n) {
  for (int i = 0; i <= n; i++) {
    uf[i] = i, sz[i] = 1;
  }
}

void dummy() {
  char c;
  cin >> c;
}

int get(int a) { return uf[a] = (uf[a] == a ? a : get(uf[a])); }

bool merge(int a, int b) {
  a = get(a), b = get(b);
  if (a == b) return 0;
  if (sz[a] < sz[b]) swap(a, b);
  uf[b] = a;
  sz[a] += sz[b];
  return 1;
}

//#define MULTIPLE_TEST_CASE
void solution() {
  int n, q, s;
  cin >> n >> q >> s;
  init(n);
  vector<tuple<int, int, int>> v;
  map<ii, int> m;
  int tot = 0;
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    tot += c;
    v.pb(mt(-c, a, b));
    m[ii(a, b)] = i + 1;
  }
  sort(all(v));
  for (auto t : v) {
    auto& [c, a, b] = t;
    c = -c;
    if (merge(a, b)) {
      // cout << "used " << a << " " << b << endl;
      m.erase(ii(a, b));
      tot -= c;
    }
  }
  for (auto t : v) {
    auto& [c, a, b] = t;
    c = -c;
    if (!m.count(ii(a, b))) continue;
    if (tot > s) {
      // cout << "kept " << a << " " << b << endl;
      m.erase(ii(a, b));
      tot -= c;
    }
  }
  vector<int> ans;
  for (auto p : m) ans.pb(p.ss);
  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";
  cout << endl;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

