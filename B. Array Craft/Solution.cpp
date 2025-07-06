#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> res(n,1);
    x--;
    y--;
    bool alt=true;
    for(int i=y-1;i>=0;i--){
        if(alt){
            res[i]=-1;
        }
        alt=!alt;
    }
    alt=true;
    for(int i=x+1;i<n;i++){
        if(alt){
            res[i]=-1;
        }
        alt=!alt;
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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
