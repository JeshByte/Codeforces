#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    string row1,row2;
    cin>>row1;
    cin>>row2;
    vector<vector<ll>> alloted(2,vector<ll>(n,-1));
    ll val=1;
        for(int j=0;j<n;j++){
            if(row1[j]==row2[j]){
                alloted[0][j]=alloted[1][j]=val;
                val++;
            }
        }
    for(int j=0;j<=n-2;j++){
        if(alloted[0][j]==-1){
            if(row1[j]==row1[j+1] && alloted[0][j+1]==-1){
                alloted[0][j]=alloted[0][j+1]=val;
                val++;
            }
        }
    }
    for(int j=0;j<=n-2;j++){
        if(alloted[1][j]==-1){
            if(row2[j]==row2[j+1] && alloted[1][j+1]==-1){
                alloted[1][j]=alloted[1][j+1]=val;
                val++;
            }
        }
    }
    ll ans=n-val+1;
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
