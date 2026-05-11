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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> points;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    vector<ll> x,y;
    for(int i=0;i<n;i++){
        x.push_back(points[i].first);
        y.push_back(points[i].second);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll ans;
    if(n&1){
        ans=1;
    }
    else{
        ll t1=x[n/2]-x[n/2 - 1]+1;
        ll t2=y[n/2]-y[n/2 - 1]+1;
        ans=t1*t2;
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
