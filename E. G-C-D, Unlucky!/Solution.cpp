#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>p,s;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        p.push_back(input);
    }
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        s.push_back(input);
    }
    vector<ll> res(n);
    for(int i=0;i<n;i++){
        ll g=__gcd(p[i],s[i]);
        ll lcm=(p[i]*s[i])/g;
        res[i]=lcm;
    }
    // for(int i=0;i<n;i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<'\n';
    ll g=0;
    for(int i=0;i<n;i++){
        g=__gcd(g,res[i]);
        if(g!=p[i]){
            cout<<"NO\n";
            return;
        }
    }
    g=0;
    for(int i=n-1;i>=0;i--){
        g=__gcd(g,res[i]);
        if(g!=s[i]){
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
