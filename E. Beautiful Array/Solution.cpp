#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll a,b;
    cin>>a>>b;
    ll x=(3*a)-b;
    //cout<<x<<'\n';
    vector<ll> arr(3);
    arr[0]=-1000;
    arr[1]=b;
    arr[2]=x+1000;
    cout<<3<<'\n';
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}    
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
