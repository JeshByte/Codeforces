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
    string s;
    cin>>s;
    ll maxi=count(s.begin(),s.end(),'1');
    string tp=s;
    for(int i=1;i<n-1;i++){
        if(tp[i]=='0' && tp[i-1]=='1' && tp[i+1]=='1'){
            maxi++;
            tp[i]='1';
        }
    }
    ll mini=count(tp.begin(),tp.end(),'1');
    for(int i=1;i<n-1;i++){
        if(tp[i]=='1' && tp[i-1]=='1' && tp[i+1]=='1'){
            mini--;
            tp[i]='0';
        }
    }
    cout<<mini<<" "<<maxi<<'\n';
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
