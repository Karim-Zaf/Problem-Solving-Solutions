#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
#define int ll 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


void solve(){
	int n , q ;
	cin >>n >> q ; 
	vector<int> v(n+1) ;
	for (int i= 1; i<=n ; i++ )cin >> v[i];
	while(q--){
		int l , r ; 
		cin >> l >> r ; 
		vector<int> nw ;

		for (int i = l; i <= r ; i++)nw .pb( v[i]);
		int sz = nw.size() ;
		vector<int> pref(sz+1) ,suff (sz+1) ;
		suff[sz-1]= nw[sz-1];
		pref[0] =nw[0] ;
		for (int i= 1; i<sz ;i++) pref[i]= __gcd(pref[i-1], nw[i]);
		for (int i= sz-2; i>=0 ;i--) suff[i]= __gcd(suff[i+1], nw[i]);
		int g=0; 
		for (int i= 0 ; i<sz;i++){
			int righ = 0, lef = 0; 
			if (i-1>=0) lef = pref[i-1];
			if (i+1<sz) righ = suff[i+1];
			int curr = __gcd (lef,righ);
			g = max(g,curr);
		}
		int x = 1e18;
		for (int i= 0 ; i< sz ;i++){
			int righ = 0, lef = 0; 
			if (i-1>=0) lef = pref[i-1];
			if (i+1<sz) righ = suff[i+1];
			int curr = __gcd (lef,righ);
			if (curr==g){
				x= min (x,nw[i]);
			}
		}
		for (int i= 0 ; i<sz; i++){
			if (nw[i]==x){
				cout << l + i << endl;
				break;
			}
		}

	}
}

int32_t main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
