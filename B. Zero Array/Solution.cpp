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
ll highestBit(ll n){
    ll bit=0;
    for(int i=0;i<64;i++){
        ll mask=1ll<<i;
        if(n&mask){
            bit=i;
        }
    }
    return bit;
}
void findContinous(vector<ll>& store, vector<ll> arr){
    ll len=arr.size();
    ll i=0;
    while(i<len){
        if(arr[i]==0){
            i++;
            continue;
        }
        ll cnt=0;
        ll tp=arr[i];
        while(i<len && arr[i]==tp){
            cnt++;
            i++;
        }
        store.push_back(cnt);
    }
}
bool rec(vector<ll>& arr, ll i, ll s, ll total, ll n, vector<ll> path){
    if(i>=n){
        if(s==(total/2)){
            //cout<<s<<'\n';
            return true;
        }
        else{
            return false;
        }
    }
    bool op1=rec(arr,i+1,s,total,n,path);
    path.push_back(i);
    bool op2=rec(arr,i+1,s+arr[i],total,n,path);
    return op1&&op2;
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
    ll total=accumulate(arr.begin(),arr.end(),0ll);
    ll maxi=*max_element(arr.begin(),arr.end());
    ll remain=total-maxi;
    if(total%2==0 && maxi<=remain){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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
