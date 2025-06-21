// https://codeforces.com/problemset/problem/1829/F
// dfs and similar graphs math 1300





#includebitsstdc++.h
#includeextpb_dsassoc_container.hpp
#includeextpb_dstree_policy.hpp
using namespace __gnu_pbds;
using namespace std;
#define fast ios_basesync_with_stdio(false),cout.tie(NULL),cin.tie(NULL);
#define N n;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(s) s.size()
#define fill(s) iota(ans.begin(),ans.end(),0);
typedef  long long ll;
typedef  long double ld;
typedef  unsigned long long ull;
#define ull unsigned long long
#define TxtIO   freopen(input.txt,r,stdin); freopen(output.txt,w,stdout);
const int MOD=1e9+7,M=1e5+5;
const ll inf=1e16;
ll mul(ll a,ll b){return (1llab)%MOD;}
int sub(ll a,ll b){return ((a-b)%MOD+MOD)%MOD;}
int add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
ll lcm(ll x, ll y) {return x  __gcd(x, y)  y;}
bool iseven(ll n) {if ((n & 1)){return 0;}else {return 1;}}
ll ncr(ll n,ll m){ll z=1;for(ll i=0;im;i++){z=z(n-i)(i+1);}return z;}
void swp(ll &a,ll &b){a^=b;b^=a;a^=b;}
ll fp(int n,int p){if(!p){return 1;}ll rem=fp(n,p1);rem=rem;if(p&1){rem=n;}return rem;}
int fact[M],inv[M];
int power(int a,int b){int ans=1;while(b){if(b&1)ans=mul(ans,a);a=mul(a,a);b=2;}return ans;}
int ncr(int n, int r) {return mul(fact[n], mul(inv[n - r], inv[r]));}
void precompute() {fact[0] = inv[0] = 1;for (int i = 1; i =M; ++i) {fact[i] = mul(fact[i - 1], i);inv[i] = power(fact[i], MOD - 2);}}
 3d
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};

 2d
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,-1,1,0,1,-1,1,-1};
char path[]={'D','L','R','U'};

 knight
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};
#define ordered_set treeint, null_type,lessint, rb_tree_tag,tree_order_statistics_node_update
int main(){
    fast
	TxtIO
	int t=1;
	cin  t;
	while (t--) {
		int n,m;
		cinnm;
		vectorvectorintv(n+1);
		for(int i=0;im;i++){
			int l,r;
			cinlr;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		vectorintv1(n+1,0);
		queueintq;
		mapint,intmp;
		for(int i=1;i=n;i++){
			if(v[i].size()==1){
				v1[i]=1;
				mp[1]++;
				q.push(i);
			}
		}
		int mx=0;
		while(!q.empty()){
			int nw=q.front();
			q.pop();
			for(auto&itv[nw]){
				if(!v1[it]){
					v1[it]=v1[nw]+1;
					mp[v1[it]]++;
					mx=max(mx,v1[it]);
					q.push(it);
				}
			}
		}
		coutmp[mx-1] mp[1]mp[mx-1]N;
	}
}
