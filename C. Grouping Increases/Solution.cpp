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
// ll rec(vector<ll>&arr,ll n,vector<vector<vector<ll>>>& dp){
//     for(int i=n-1;i>=0;i--){
//         for(int prev1=0;prev1<10;prev1++){
//             for(int prev2=0;prev2<10;prev2++){
//                 ll op1,op2;
//                 if(prev1!=0 && arr[i]>prev1){
//                     op1=1+dp[i+1][arr[i]][prev2]; 
//                 }
//                 else{
//                     op1=dp[i+1][arr[i]][prev2];
//                 }
//                 if(prev2!=0 && arr[i]>prev2){
//                     op2=1+dp[i+1][prev1][arr[i]];
//                 }
//                 else{
//                     op2=dp[i+1][prev1][arr[i]];
//                 }
//                 dp[i][prev1][prev2]=min(op1,op2);
//             }
//         }
//     }
//     return dp[0][0][0];
// }
struct ComparePairs {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b) {
        if(a.first!=b.first){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    }
};
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    // if(t==106){
    //     cout<<n<<'\n';
    //     for(int i=0;i<n;i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<'\n';
    // }
    //vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(10,vector<ll>(10,0)));
    ll prev1=1e6,prev2=1e6;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(prev1>prev2){
            swap(prev1,prev2);
        }
        if(arr[i]<=prev1){
            prev1=arr[i];
        }
        else if(arr[i]>prev1 && arr[i]<=prev2){
            prev2=arr[i];
        }
        else{
            ans++;
            prev1=arr[i];
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
