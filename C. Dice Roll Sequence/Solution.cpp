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
bool check(ll a,ll b){
    if(a!=b && b!=(7-a)){
        return true;
    }
    return false;
}
ll solve_tabulation(vector<ll>& arr) {
    int n = arr.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(7, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int prev = 0; prev <= 6; prev++) {
            ll keep = 1e18;
            if (prev == 0 || check(prev, arr[i])) {
                keep = dp[i + 1][arr[i]];
            }

            ll change = 1e18;
            for (int j = 1; j <= 6; j++) {
                if (prev == 0 || check(prev, j)) {
                    change = min(change, 1 + dp[i + 1][j]);
                }
            }
            
            dp[i][prev] = min(keep, change);
        }
    }

    return dp[0][0];
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll ans=solve_tabulation(arr);
    cout<<ans<<'\n';
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
