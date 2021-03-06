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
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
//#define MULTIPLE_TEST_CASE
int solution(vector<int>& v) {
  int n = v.size();
  vector<vector<int>> p(2 * n, vector<int>(2, 0));
  p[0][0] = v[0];
  for (int i = 1; i < 2 * n; i++) {
    p[i][0] += p[i - 1][0];
    p[i][1] += p[i - 1][1];
    p[i][i % 2] += v[i % n];
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, p[i + n - 1][i % 2] - (i - 1 >= 0 ? p[i - 1][i % 2] : 0));

  return ans;
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, 0, n, 1) cin >> v[i];
    cout << solution(v) << endl;
  }
}

