#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
 
        exp = exp >> 1;
 
        base = (base * base) % mod;
    }
    return result;
}
ll findInverse(ll n,ll MOD){
    return modExpo(n,MOD-2,MOD);
}
ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}
int countPrimes(int n) {
    int ans=0;
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            ans++;
            for(int j=i*2;j<n;j+=i){
                prime[j]=false;
            }
        }
    }
    return ans;
}
ll maxSubarraySum(vector<ll> &arr) {
    ll res = arr[0];
    ll maxEnding = arr[0];
 
    for (int i = 1; i < arr.size(); i++) {
 
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
 
        res = max(res, maxEnding);
    }
    return res;
}
struct Compare {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b) {
        if(a.first!=b.first){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    }
};
const ll MAXN = 100005;
const ll K = 20; 

ll st[MAXN][K];
ll logs[MAXN];


void precomputeLogs(ll n) {
    logs[1] = 0;
    for (int i = 2; i <= n; i++)
        logs[i] = logs[i / 2] + 1;
}


void build(const vector<ll>& arr, ll n) {
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j < K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}


ll query(ll L, ll R) {
    ll j = logs[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    if(n==2 || n==3){
        cout<<"NO SOLUTION\n";
        return;
    }
    for(int i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    cout<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
