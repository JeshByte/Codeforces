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
bool check(ll mid,ll& ans,ll s,ll e,vector<ll>& arr,ll n,ll ind){
    ll cnt=0;
    for(int i=s;i<=e;i++){
        ll t1=abs(arr[ind]-mid);
        ll t2=abs(arr[i]-mid);
        if(t1>t2){
            cnt++;
        }
    }
    if(cnt>=ans){
        ans=cnt;
        return true;
    }
    return false;
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        mp[input]++;
    }
    vector<pair<ll,ll>> res;
    for(auto it:mp){
        res.push_back({it.second,it.first});
    }
    sort(res.rbegin(),res.rend());
    ll ans=0;
    ans+=res[0].first;
    ll need=res[0].first-1;
    for(int i=1;i<res.size();i++){
        if(need<=0){
            break;
        }
        if(res[i].first>=need){
            ans+=need;
            need--;
        }
        else{
            ans+=res[i].first;
            need=res[i].first-1;
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
