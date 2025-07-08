// https://codeforces.com/contest/1559/problem/C
// C. Mocha and Hiking  
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define N "\n";
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(s) s.size()
//#define fill(s) iota(ans.begin(),ans.end(),0);
typedef  long long ll;
typedef  long double ld;
typedef  unsigned long long ull;
#define ull unsigned long long
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
const int MOD=1e9+7,M=1e6+5;
//const ll inf=1e16;
ll mul(ll a,ll b){return (1ll*a*b)%MOD;}
int sub(ll a,ll b){return ((a-b)%MOD+MOD)%MOD;}
int add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
ll lcm(ll x, ll y) {return x / __gcd(x, y) * y;}
bool iseven(ll n) {if ((n & 1)){return 0;}else {return 1;}}
ll ncr(ll n,ll m){ll z=1;for(ll i=0;i<m;i++){z=z*(n-i)/(i+1);}return z;}
void swp(ll &a,ll &b){a^=b;b^=a;a^=b;}
ll fp(int n,int p){if(!p){return 1;}ll rem=fp(n,p>>1);rem*=rem;if(p&1){rem*=n;}return rem;}
//int fact[M],inv[M];
//int power(int a,int b){int ans=1;while(b){if(b&1)ans=mul(ans,a);a=mul(a,a);b/=2;}return ans;}
//int ncr(int n, int r) {return mul(fact[n], mul(inv[n - r], inv[r]));}
//void precompute() {fact[0] = inv[0] = 1;for (int i = 1; i <=M; ++i) {fact[i] = mul(fact[i - 1], i);inv[i] = power(fact[i], MOD - 2);}}
// 3d
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
//int dz[]={0,0,0,0,1,-1};

// 2d
//int dx[]={1,0,0,-1,1,1,-1,-1};
//int dy[]={0,-1,1,0,1,-1,1,-1};
//char path[]={'D','L','R','U'};

// knight
//int dx[]={2,2,-2,-2,1,-1,1,-1};
//int dy[]={1,-1,1,-1,2,2,-2,-2};
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update
int n,m;
vector<vector<int>>g;
bool vis[200005];
vector<int>path;
void dfs(int indx){
	vis[indx]=1;	
	for(auto&it:g[indx]){
		if(!vis[it]){
			dfs(it);
		}
	}
	path.push_back(indx);
}
int main(){
    fast
//	TxtIO
	int t=1;
	cin >> t;
	while (t--) {
		cin>>n;
    	g.clear();
    	g.resize(n+2);
    	for(int i=1;i<n;i++){g[i].push_back(i+1);}
    	for(int i=1;i<=n;i++){
    		cin>>m;
    		if(m==0){g[i].push_back(n+1);}
			else{g[n+1].push_back(i);}
		}
		for(int i=1;i<=n+1;i++){
			path.clear();
			memset(vis,0,n+5);
			dfs(i);
			if(sz(path)==n+1){
				reverse(all(path));
				for(auto&it:path){
					cout<<it<<" ";
				}
				break;
			}
		}
		cout<<N;
	}
}