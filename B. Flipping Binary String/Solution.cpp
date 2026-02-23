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
    string s;
    cin>>s;
    ll cnt1=count(s.begin(),s.end(),'1');
    ll cnt0=count(s.begin(),s.end(),'0');
    if(cnt1==0){
        cout<<0<<'\n';
        return;
    }
    if(cnt0%2==0 && cnt1%2!=0){
        cout<<-1<<'\n';
    }
    else if(cnt0%2!=0){
        cout<<cnt0<<'\n';
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cout<<i+1<<" ";
            }
        }
        cout<<'\n';
    }
    else if(cnt1%2==0){
        cout<<cnt1<<'\n';
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cout<<i+1<<" ";
            }
        }
        cout<<'\n';
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
