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
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    vector<ll>six,two,three,other;
    for(int i=0;i<n;i++){
        if(arr[i]%6==0){
            six.push_back(arr[i]);
        }
        else if(arr[i]%2==0){
            two.push_back(arr[i]);
        }
        else if(arr[i]%3==0){
            three.push_back(arr[i]);
        }
        else{
            other.push_back(arr[i]);
        }
    }
    for(int i=0;i<six.size();i++){
        cout<<six[i]<<" ";
    }
    for(int i=0;i<two.size();i++){
        cout<<two[i]<<" ";
    }
    for(int i=0;i<other.size();i++){
        cout<<other[i]<<" ";
    }
    for(int i=0;i<three.size();i++){
        cout<<three[i]<<" ";
    }
    cout<<'\n';
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
