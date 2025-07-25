#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
const ll MOD=998244353;
long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
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
ll DP(vector<vector<tuple<ll,ll,ll>>>& arr,ll l,ll m,vector<ll>& dp){
    if(l>m){
        return 1;
    }
    if(dp[l]!=-1){
        return dp[l];
    }
    ll ans=0;
    for(auto it:arr[l]){
        ll r=get<0>(it);
        ll p=get<1>(it);
        ll q=get<2>(it);
        ll val=1;
        val=((val*p)%MOD);
        val=((val*findInverse(q-p,MOD))%MOD);
        val=((val*DP(arr,r+1,m,dp))%MOD);
        ans=((ans+val)%MOD);
    }
    dp[l]=ans;
    return dp[l];
}
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<vector<tuple<ll,ll,ll>>> arr(m+1);
    ll total=1;
    for(int i=0;i<n;i++){
        ll l,r,p,q;
        cin>>l>>r>>p>>q;
        arr[l].push_back(make_tuple(r,p,q));
        total=((total*((q-p)%MOD))%MOD);
        total=((total*findInverse(q,MOD))%MOD);
    }
    vector<ll> dp(m+1,-1);
    ll ans=((total*DP(arr,1,m,dp))%MOD);
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
} 
