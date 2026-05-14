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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        a[i]=input;
    }
    for(int i=1;i<=n;i++){
        ll input;
        cin>>input;
        b[i]=input;
    }
    vector<ll> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+b[i];
    }
    vector<ll> full(n+1,0),partial(n+1,0);
    for(int i=1;i<=n;i++){
        ll req=pre[i-1]+a[i];
        ll ind=upper_bound(pre.begin(),pre.end(),req)-pre.begin();
        //ind++;
        if(ind<=n){
            partial[ind]+=(a[i]-pre[ind-1]+pre[i-1]);
            full[ind]-=1;
        }
        full[i]+=1;
    }
    ll s=0;
    for(int i=1;i<=n;i++){
        s+=full[i];
        ll ans=b[i]*s+partial[i];
        cout<<ans<<" ";
    }
    cout<<'\n';
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
