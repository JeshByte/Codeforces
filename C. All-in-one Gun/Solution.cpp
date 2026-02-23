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
const ll MAXN = 1000005;
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
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}


ll query(ll L, ll R) {
    ll j = logs[R - L + 1];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}
void solve(ll t){
    ll n,h,k;
    cin>>n>>h>>k;
    vector<ll> arr;
    ll s=0;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        s+=input;
    }
    if(h%s==0){
        ll times=(h/s);
        ll ans=(times*n)+((times-1)*k);
        cout<<ans<<'\n';
    }
    else{
        ll times=(h/s);
        ll ans=(times*(n+k));
        h=h-(times*s);
        precomputeLogs(n);
        build(arr,n);
        ll mini=1e10;
        ll total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
            mini=min(mini,arr[i]);
            ll maxi=query(i+1,n-1);
            ll tp=total;
            if(mini<maxi){
                 tp=tp-mini+maxi;
            }
            if(h-tp<=0){
                cout<<ans+i+1<<'\n';
                return;
            }
        }
    }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
