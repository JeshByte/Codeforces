#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    string a,b,c;
    cin>>a>>b>>c;
    vector<vector<ll>>dp(a.size()+1,vector<ll>(b.size()+1));
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            dp[i][j]=1e4;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=a.size();i++){
        dp[i][0]=dp[i-1][0]+(a[i-1]==c[i-1] ? 0:1);
    }
    for(int i=1;i<=b.size();i++){
        dp[0][i]=dp[0][i-1]+(b[i-1]==c[i-1] ? 0:1);
    }
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            dp[i][j]=min(dp[i-1][j]+(a[i-1]==c[i+j-1] ? 0:1),dp[i][j-1]+(b[j-1]==c[i+j-1] ? 0:1));
        }
    }
    cout<<dp[a.size()][b.size()]<<'\n';
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
