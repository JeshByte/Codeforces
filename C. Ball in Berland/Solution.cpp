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
bool check(ll mid,ll n,ll m,ll l,vector<ll>& arr,vector<ll>& ph){
    for(int i=0;i<m;i++){
        ph[i]=0;
    }
    ll t=0;
    for(int i=0;i<n;i++){
        ll time=(arr[i]-1)-t;
        ll init=time/m;
        for(int j=0;j<m;j++){
            ph[j]+=init;
        }
        ll rest=time-(init*m);
        
    }
}
void solve(ll t,ll testcases){
    ll a,b,k;
    cin>>a>>b>>k;
    vector<ll> boys,girls;
    vector<ll>x(a+1,0),y(b+1,0);
    for(int i=0;i<k;i++){
        ll input;
        cin>>input;
        boys.push_back(input);
        x[input]++;
    }
    for(int i=0;i<k;i++){
        ll input;
        cin>>input;
        girls.push_back(input);
        y[input]++;
    }
    ll total=k;
    ll ans=0;
    for(int i=0;i<k;i++){
        ll bcontri=0;
        if(x[boys[i]]>=1){
            bcontri=x[boys[i]]-1;
        }
        ll gcontri=0;
        if(y[girls[i]]>=1){
            gcontri=y[girls[i]]-1;
        }
        ans+=(total-(bcontri+gcontri+1));
        if(x[boys[i]]>0){
            x[boys[i]]--;
        }
        if(y[girls[i]]>0){
            y[girls[i]]--;
        }
        if(total>0){
            total--;
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
