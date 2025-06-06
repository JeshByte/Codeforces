#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll len=Ceil(n,2);
    vector<vector<ll>> dp(len,vector<ll>(2,0));
    for(int i=1;i<len;i++){
        dp[i][0]=min((dp[i-1][0]+(arr[i-1]==arr[i])+(arr[n-i-1]==arr[n-i])),(dp[i-1][1]+(arr[i]==arr[n-i])+(arr[n-i-1]==arr[i-1])));
        dp[i][1]=min((dp[i-1][1]+(arr[i-1]==arr[i])+(arr[n-i-1]==arr[n-i])),(dp[i-1][0]+(arr[i]==arr[n-i])+(arr[n-i-1]==arr[i-1])));
    }
    ll ans=min(dp[len-1][0],dp[len-1][1]);
    if(!(n&1)){
        ans+=(arr[len-1]==arr[len]);
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
