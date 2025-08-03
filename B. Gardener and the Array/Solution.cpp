#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
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
void solve(ll t){
    ll n;
    cin>>n;
    vector<vector<ll>> arr;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        vector<ll> temp;
        for(int j=0;j<k;j++){
            ll input;
            cin>>input;
            mp[input]++;
            temp.push_back(input);
        }
        arr.push_back(temp);
    }
    for(int i=0;i<n;i++){
        bool poss=true;
        for(int j=0;j<arr[i].size();j++){
            if(mp[arr[i][j]]<=1){
                poss=false;
            }
        }
        if(poss){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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
