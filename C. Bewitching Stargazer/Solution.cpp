#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    ll luck=0;
    ll s=0;
    if(n&1){
        s=Ceil(n,2);
    }
    else{
        s=n+1;
        n=n/2;
    }
    while(n>=k){
        if(n&1){
            luck+=s;
        }
        n=n/2;
        s=s*2;
    }
    cout<<luck<<'\n';
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
