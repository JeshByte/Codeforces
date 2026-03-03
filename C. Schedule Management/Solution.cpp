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
void solve(ll t,ll total){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr;
    map<ll,ll> mp;
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        mp[input]++;
    }
    ll l=1;
    ll h=2*m;
    ll ans;
    while(l<=h){
        ll mid=h+(l-h)/2;
        if(check(mid,n,mp)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
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
