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
    ll n,m;
    cin>>n>>m;
    vector<ll> a,op;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        op.push_back(input);
    }
    vector<ll> odd,even;
    for(int i=0;i<n;i++){
        if((i+1)&1){
            odd.push_back(a[i]);
        }
        else{
            even.push_back(a[i]);
        }
    }
    ll ocnt=0,ecnt=0;
    for(int i=0;i<m;i++){
        if(op[i]&1){
            ocnt++;
        }
        else{
            ecnt++;
        }
    }
    sort(odd.rbegin(),odd.rend());
    sort(even.rbegin(),even.rend());
    ll odel=0,edel=0;
    ll i=0;
    while(i<odd.size()){
        if((odd[i]>0) && ocnt){
            ocnt--;
            odel++;
            i++;
        }
        else{
            break;
        }
    }
    i=0;
    while(i<even.size()){
        if(even[i]>0 && ecnt){
            ecnt--;
            edel++;
            i++;
        }
        else{
            break;
        }
    }
    ll s=0;
    for(int i=odel;i<odd.size();i++){
        s+=odd[i];
    }
    for(int i=edel;i<even.size();i++){
        s+=even[i];
    }
    if(odel==0 && ocnt>0){
        s-=odd[0];
    }
    if(edel==0 && ecnt>0){
        s-=even[0];
    }
    cout<<s<<'\n';
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
