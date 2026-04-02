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
ll fact(ll n,ll MOD){
    ll ans=1;
    for(int i=n;i>=1;i--){
        ans=(ans*i)%MOD;
    }
    return ans;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<ll> pos;
    for(int i=0;i<32;i++){
        ll mask=(1ll<<i);
        ll cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]&mask){
                cnt++;
            }
        }
        if(cnt<n){
            pos.push_back(i);
        }
    }
    ll req=0;
    for(int i=0;i<n;i++){
        bool valid=true;
        for(int j=0;j<pos.size();j++){
            ll mask=(1ll<<pos[j]);
            if(arr[i]&mask){
                valid=false;
            }
        }
        if(valid){
            req++;
        }
    }
    if(req<2){
        //cout<<"hi\n";
        cout<<0<<'\n';
        return;
    }
    //cout<<req<<'\n';
    ll MOD=1000000007;
    ll term=fact(n-2,MOD);
    ll ans=(req*(req-1))%MOD;
    ans=(ans*term)%MOD;
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
