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
void toBinary(ll n,vector<ll>& bin){
    while(n){
        bin.push_back(n%2);
        n=n/2;
    }
    //reverse(bin.begin(),bin.end());
}
bool check(ll mid,ll n,map<ll,ll>& mp){
    ll incomplete=0;
    ll carry=0;
    for(int i=1;i<=n;i++){
        ll complete=min(mp[i],mid);
        incomplete=incomplete+(mp[i]-complete);
        ll remain=mid-complete;
        carry=carry+(remain/2);
    }
    if(carry>=incomplete){
        return true;
    }
    return false;
}
void solve(ll t,ll testcases){
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll i=0,j=0;
    ll ans=0;
    while(j<n){
        if(j-1>=0){
            ll prev=arr[j-1];
            ll curr=arr[j];
            bool poss=false;
            if(curr>=prev){
                poss=true;
            }
            else if(curr>=(abs(curr-prev)+1)){
                poss=true;
            }
            if(!poss){
                i=j;
            }
        }
        ll len=(j-i)+1;
        if(len==(k+1)){
            //cout<<"hi\n";
            ans++;
            i++;
        }
        j++;
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
