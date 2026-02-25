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
    ll x,y;
    cin>>x>>y;
    if(y>=0){
        ll moves2=y;
        ll total=moves2*2;
        if(total>x){
            cout<<"NO\n";
        }
        else{
            x-=total;
            if(x%3==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    else{
        ll moves4=abs(y);
        ll total=moves4*4;
        if(total>x){
            cout<<"NO\n";
        }
        else{
            x-=total;
            if(x%3==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
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
