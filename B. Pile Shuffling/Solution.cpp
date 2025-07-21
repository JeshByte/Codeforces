#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<vector<ll>> arr(n,vector<ll>(4));
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(arr[i][0]<=arr[i][2] && arr[i][1]>arr[i][3]){
            ans+=((arr[i][1]-arr[i][3])+arr[i][0]);
        }
        else if(arr[i][0]>arr[i][2] && arr[i][1]<=arr[i][3]){
            ans+=(arr[i][0]-arr[i][2]);
        }
        else if(arr[i][0]>arr[i][2] && arr[i][1]>arr[i][3]){
            ans+=((arr[i][0]-arr[i][2])+(arr[i][1]-arr[i][3])+arr[i][2]);
        }
    }
    cout<<ans<<'\n';
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
