#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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
ll fact(ll n,ll MOD){
    ll ans=1;
    for(int i=n;i>=1;i--){
        ans=(ans*n)%MOD;
    }
    return ans;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),[](pair<ll,ll>& a,pair<ll,ll>&b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
    });
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    // }
    ordered_set st;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll req=st.order_of_key(arr[i].first);
        ans+=(st.size()-req);
        st.insert(arr[i].first);
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
