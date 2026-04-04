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
void toBinary(ll n,vector<ll>& bin){
    while(n){
        bin.push_back(n%2);
        n=n/2;
    }
    //reverse(bin.begin(),bin.end());
}
bool check(ll mid,ll n,map<ll,ll>& mp){
    ll incomplete=0;
    ll carry=0;
    for(int i=1;i<=n;i++){
        ll complete=min(mp[i],mid);
        incomplete=incomplete+(mp[i]-complete);
        ll remain=mid-complete;
        carry=carry+(remain/2);
    }
    if(carry>=incomplete){
        return true;
    }
    return false;
}
void solve(ll t,ll testcases){
    ll n,m;
    cin>>n>>m;
    set<ll> st;
    vector<vector<ll>> arr(n,vector<ll>(m));
    vector<vector<ll>> rows(1e5+1,vector<ll>());
    vector<vector<ll>> cols(1e5+1,vector<ll>());
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            rows[arr[i][j]].push_back(i+1);
            cols[arr[i][j]].push_back(j+1);
            st.insert(arr[i][j]);
        }
    }
    ll ans=0;
    for(ll c:st){
        sort(rows[c].begin(),rows[c].end());
        ll s=0;
        for(int i=0;i<rows[c].size();i++){
            ll contri=(i*rows[c][i])-s;
            ans+=contri;
            s+=rows[c][i];
        }
        sort(cols[c].begin(),cols[c].end());
        s=0;
        for(int i=0;i<cols[c].size();i++){
            ll contri=(i*cols[c][i])-s;
            ans+=contri;
            s+=cols[c][i];
        }
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
