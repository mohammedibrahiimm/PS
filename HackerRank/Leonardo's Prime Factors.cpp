// Leonardo's Prime Factors
// https://www.hackerrank.com/contests/infinitum16-firsttimer/challenges/leonardo-and-prime/copy-from/1397390021
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */
typedef  long long ll;
const int M=1e8+5;
vector<bool>isPrime;
vector<ll>prime;
void linearSieve(ll n){
    prime.clear();
    isPrime=vector<bool>(n,1);
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<n;i++){
        if(isPrime[i])prime.push_back(i);
        for(int j=0;j<(int)prime.size()&&i*prime[j]<M;j++){
            isPrime[i*prime[j]]=0;
            if(i%prime[j]==0)break;
        }
    }
}
int primeCount(ll n) {
    int ans=0;
    ll ans1=1;
    for(auto&it:prime){
        if(ans1*it<=n&&ans1*it>ans1){
            ans1*=it;
            ans++;
        }
        else{break;}
    }
    cout<<1ll*ans1<<"\n";
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    linearSieve(M);
    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
