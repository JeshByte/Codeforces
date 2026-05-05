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
bool comp(pair<ll,ll> seg,ll val){
    return seg.first>=val;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        arr.push_back({l,r});
    }
    sort(arr.begin(),arr.end(),[](pair<ll,ll>& a,pair<ll,ll>& b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        else{
            return a.first<b.first;
        }
    });
    vector<ll> allot(2,-1);
    for(int i=0;i<n;i++){
        ll maxi=-1;
        bool found=false;
        if(allot[0]+1<=arr[i].first){
            maxi=max(maxi,allot[0]);
            found=true;
        }
        if(allot[1]+1<=arr[i].first){
            maxi=max(maxi,allot[1]);
            found=true;
        }
        if(maxi==-1 && !found){
            cout<<"NO\n";
            return;
        }
        else if(maxi==allot[0]){
            allot[0]=arr[i].second;
        }
        else{
            allot[1]=arr[i].second;
        }
    }
    cout<<"YES\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
