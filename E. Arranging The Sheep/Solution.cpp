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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt=count(s.begin(),s.end(),'*');
    if(cnt==0 || cnt==n){
        cout<<0<<'\n';
        return;
    }
    ll k=cnt;
    vector<ll> sheeps(k+1,0);
    ll ind=1;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            sheeps[ind]=i+1;
            ind++;
        }
    }
    vector<ll> ml(k+1,0),mr(k+1,0);
    ml[1]=0;
    for(int i=2;i<=k;i++){
        ml[i]=ml[i-1]+(abs(sheeps[i]-sheeps[i-1])-1)*(i-1);
    }
    mr[k]=0;
    for(int i=k-1;i>=1;i--){
        mr[i]=mr[i+1]+(abs(sheeps[i]-sheeps[i+1])-1)*(k-i);
    }
    ll ans=1e12;
    for(int i=1;i<=k;i++){
        ans=min(ans,ml[i]+mr[i]);
        //cout<<ans<<'\n';
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
