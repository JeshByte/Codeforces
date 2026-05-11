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
    ll q;
    cin>>q;
    vector<pair<ll,ll>> queries;
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        queries.push_back({a,b});
    }
    ll plus,minus;
    plus=minus=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+'){
            plus++;
        }
        else{
            minus++;
        }
    }
    for(int i=0;i<q;i++){
        if(plus==minus){
            cout<<"YES\n";
            continue;
        }
        ll a=queries[i].first;
        ll b=queries[i].second;
        ll g=__gcd(a,b);
        ll lcm=(a*b)/g;
        ll k1=lcm/a;
        ll k2=lcm/b;
        ll diff=abs(k1-k2);
        ll req=abs(plus-minus);
        if(diff!=0 && req%diff==0){
            ll c=req/diff;
            k1*=c;
            k2*=c;
            if(plus>=k1 && minus>=k2){
                cout<<"YES\n";
                continue;
            }
            if(plus>=k2 && minus>=k1){
                cout<<"YES\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
