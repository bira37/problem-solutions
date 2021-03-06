#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int l[n], r[n];
  for(int i=0; i<n; i++) cin >> l[i];
  for(int i=0; i<n; i++) cin >> r[i];
  int ans[n];
  for(int i=0; i<n; i++){
    ans[i] = n - (l[i] + r[i]);
  }
  for(int i=0; i<n; i++){
    int lef = 0, rig = 0;
    for(int j = 0; j <i; j++){
      lef += ans[i] < ans[j];
    }
    for(int j = i+1; j<n; j++){
      rig += ans[i] < ans[j];
    }
    if(lef != l[i] || rig != r[i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for(int i=0; i<n; i++){
    cout << ans[i] << " ";
  }
  cout << endl;
}

