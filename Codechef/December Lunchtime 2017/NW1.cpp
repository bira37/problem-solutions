#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define mod(n) (n%1000000007)
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string days[] = { "mon", "tues", "wed", "thurs", "fri", "sat", "sun"};
		string curr;
		int d;
		cin >> d >> curr;
		int curri;
		map<string, int> cnt;
		for(int i=0; i<7; i++) if(days[i] == curr) curri = i;
		while(d--){
			cnt[days[curri]]++;
			curri++;
			curri %= 7;
		}
		for(int i=0; i<7; i++){
			if(i) cout << " ";
			cout << cnt[days[i]];
		}
		cout <<endl;
	}
}
	
