#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
bool comp(pair<ll,ll> seg,ll val){
    return seg.first>=val;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> segments;
    map<pair<ll,ll>,ll> mp;
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        segments.push_back({l,r});
        mp[{l,r}]++;
    }   
    bool duplicate=false;
    pair<ll,ll> val;
    for(auto it:mp){
        if(it.second>1){
            duplicate=true;
            val=it.first;
            break;
        }
    }
    if(duplicate){
        vector<ll> ind;
        for(int i=0;i<n;i++){
            if(segments[i]==val){
                ind.push_back(i+1);
                if(ind.size()==2){
                    break;
                }
            }
        }
        cout<<ind[0]<<" "<<ind[1]<<'\n';
        return;
    }
    map<pair<ll,ll>,ll> idx;
    for(int i=0;i<n;i++){
        idx[segments[i]]=i+1;
    }
    sort(segments.begin(),segments.end(),[](pair<ll,ll> a,pair<ll,ll> b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        else{
            return a.first>b.first;
        }
    });
    set<pair<ll,ll>> st;
    for(int i=0;i<n;i++){
        auto it=st.lower_bound({segments[i].first,0});
        if(it!=st.end()){
            pair<ll,ll> ele=*it;
            ll id1=ele.second;
            ll id2=idx[segments[i]];
            cout<<id1<<" "<<id2<<'\n';
            return;
        }
        st.insert({segments[i].first,idx[segments[i]]});
    }
    cout<<-1<<" "<<-1<<'\n';
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
