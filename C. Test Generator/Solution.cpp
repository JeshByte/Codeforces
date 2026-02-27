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
bool check(ll mid,vector<ll>&binm,vector<ll>&bins,ll ind,ll carry){
    ll pc=carry-mid;
    ll b=mid;
    for(int i=ind-1;i>=0;i--){
        ll total;
        if(bins[i]==0){
            total=pc*2;
        }
        else{
            total=pc*2+1;
        }
        if(binm[i]==0){
            pc=total;
            continue;
        }
        if(total<mid){
            return true;
        }
        else{
            pc=total-mid;
        }
    }
    if(pc==0){
        return true;
    }
    return false;
}
void solve(ll t){
    ll s,m;
    cin>>s>>m;
    if(s%(m&(-m))){
        cout<<-1<<'\n';
        return;
    }
    ll ans=-1;
    for(int i=0;i<64;i++){
        ll mask=(1ll<<i)-1;
        ll ss=s&mask;
        ll mm=m&mask;
        if(ss==0){
            continue;
        }
        ans=max(ans,Ceil(ss,mm));
    }
    cout<<ans<<'\n';
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
