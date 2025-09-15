// https://codeforces.com/contest/1062/problem/B
// B. Math
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
const int MOD=1e9+7,M=1e5+5;
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
vector<bool>isPrime;
vector<int>prime;
void linearSieve(ll n){
	prime.clear();
	isPrime=vector<bool>(n,1);
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i<n;i++){
		if(isPrime[i])prime.push_back(i);
		for(int j=0;j<prime.size()&&i*prime[j]<M;j++){
			isPrime[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
}
vector<ll>v(1000002,0);
ll factorize(ll n){
//	vector<int>ans;
	map<int,int>mp;
	ll nw=n;
	if(n%2==0){
//		ans.push_back(2);
		while(n%2==0){
			mp[2]++;
			n/=2;
		}
	}
	for(ll i=3;i*i<=n;i+=2){
		if(n%i==0){
//			ans.push_back(i);
			while(n%i==0){
				mp[i]++;
				n/=i;
			}
		}
	}
	if(n!=1){
		mp[n]++;
//		ans.push_back(n);
	}
	ll sum=1;
	for(auto&it:mp){sum*=(it.second+1);}
	return sum;
}
int main(){
    fast
//	linearSieve(M);
//	TxtIO
	int t=1;
//	cin >> t;
	while(t--){
		vector<int>powers;
		for(int i=0;i<31;i++){
			powers.push_back(fp(2,i));
		}
		int n;
		cin>>n;
		map<int,int>mp;
		int n1=n;
		while(n%2==0){
			mp[2]++;
			n/=2;
		}
		for(int i=3;i*i<=n;i+=2){
			while(n%i==0){
				mp[i]++;
				n/=i;
			}
		}
		if(n!=1){mp[n]++;}
		int ans=1,mx=0;
		set<int>st;
		for(auto&it:mp){
//			cout<<it.first<<" "<<it.second<<N;
			st.insert(it.second);
			ans*=it.first;
			mx=max(mx,it.second);
		}
		int ans1=0,mx1=0;
		bool ok=0;
		if(mx>1){
			ans1++;
			for(auto&it:powers){
				if(it>=mx){
					if(it==mx){ok=1;}
					mx1=it;
					break;
				}
			}
			while(mx1%2==0){
				mx1/=2;
				ans1++;
			}
			if(ok&&st.size()==1){ans1--;}
		}
		cout<<ans<<" "<<ans1;
	}
}

