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
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr(n+1,0);
    map<ll,ll> mp;
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        arr[i]=input;
        mp[arr[i]]=i;
    }
    for(int i=1;i<=n;i++){
        bool got=false;
        if(mp[i]==i){
            continue;
        }
        ll j=i;
        while(j<=(n/2)){
            j*=2;
            if(arr[j]==i){
                got=true;
                break;
            }
        }
        j=i;
        while(j%2==0 && (j/2)<=(n/2) && (j/2)>=1){
            j=j/2;
            if(arr[j]==i){
                got=true;
                break;
            }
        }
        if(!got){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
