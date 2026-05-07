#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ll=long long;
typedef __gnu_pbds::tree<pair<ll,ll>, __gnu_pbds::null_type, less<pair<ll,ll>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
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
// void printWithPrecision(auto n){
//     cout << fixed << setprecision(6) << n << '\n';
// }
bool comp(pair<ll,ll> seg,ll val){
    return seg.first>=val;
}
void solve(ll t,ll testcases){
    ll n,q;
    cin>>n>>q;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<pair<ll,ll>> queries;
    for(int i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        queries.push_back({l,r});
    }
    sort(queries.begin(),queries.end(),[](pair<ll,ll>& a, pair<ll,ll>& b){
       if(a.second!=b.second){
           return a.second>b.second;
       } 
       else{
           return a.first>b.first;
       }
    });
    ordered_set st;
    ll ind=0;
    map<ll,ll> mp;
    ll val=n;
    while(val>=1){
        if(ind<q && queries[ind].second>=val){
            st.insert({queries[ind].first,ind});
            ind++;
        }
        else{
            ll cnt=st.order_of_key({val+1,-1});
            mp[val]=cnt;
            val--;
        }
    }
    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second<<'\n';
    // }
    sort(arr.rbegin(),arr.rend());
    vector<ll> freq;
    for(auto it:mp){
        freq.push_back(it.second);
    }
    sort(freq.rbegin(),freq.rend());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(freq[i]*arr[i]);
    }
    cout<<ans<<'\n';
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
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
