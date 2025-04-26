#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll k,vector<ll>&comp){
    if(k<=0){
        return;
    }
    ll val=sqrtl(1+8*k);
    val++;
    val=val/2;
    comp.push_back(val);
    ll total=(val*(val-1))/2;
    k-=total;
    return solve(k,comp);
}
void solve(ll t){
    ll k;
    cin>>k;
    if(k==0){
        cout<<1<<'\n';
        cout<<1<<" "<<1<<'\n';
        return;
    }
    vector<ll>comp;
    solve(k,comp);
    ll total=accumulate(comp.begin(),comp.end(),0ll);
    cout<<total<<'\n';
    ll x=1,y=1;
    for(int i=0;i<comp.size();i++){
        for(int j=0;j<comp[i];j++){
            cout<<x<<" "<<y<<'\n';
            x++;
        }
        y++;
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
