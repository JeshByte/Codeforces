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
bool check(ll mid,vector<ll>& arr,ll n){
    set<ll> got;
    vector<ll> extra;
    for(int i=0;i<n;i++){
        if(arr[i]>=0 && arr[i]<=(mid-1) && got.count(arr[i])==0){
            got.insert(arr[i]);
        }
        else{
            extra.push_back(arr[i]);
        }
    }
    vector<ll> req;
    for(int i=0;i<=(mid-1);i++){
        if(got.count(i)==0){
            req.push_back(i);
        }
    }
    sort(extra.begin(),extra.end());
    ll ind=0;
    for(int i=0;i<extra.size();i++){
        ll lim=Ceil(extra[i],2)-1;
        if(extra[i]<=1){
            lim=extra[i];
        }
        if(ind<req.size() && (req[ind]<=lim || req[ind]==extra[i])){
            ind++;
        }
    }
    if(ind<req.size()){
        return false;
    }
    return true;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    sort(arr.begin(),arr.end());
    ll l=1;
    ll h=n;
    ll ans=0;
    while(l<=h){
        ll mid=l+(h-l)/2;
        if(check(mid,arr,n)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            h=mid-1;
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
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
