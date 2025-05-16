#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    uint64_t x,y;
    cin>>x>>y;
    if(x==y){
        cout<<-1<<'\n';
        return;
    }
    if(x<y){
        swap(x,y);
    }
    ll p=0;
    while((1ll<<p)<max(x,y)){
        p++;
    }
    //cout<<p<<'\n';
    while((1ll<<p)<=1e18){
        ll req=1ll<<p;
        ll k=req-x;
        if((req&(y+k))==0){
            cout<<k<<'\n';
            return;
        }
        p++;
    }
    cout<<-1<<'\n';
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
