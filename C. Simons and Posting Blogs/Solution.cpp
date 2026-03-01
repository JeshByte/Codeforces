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
ll Expo(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base);
        }
 
        exp = exp >> 1;
 
        base = (base * base);
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
void getPrimeFactorPowers(ll n,map<ll,ll>&factors) {
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    for (int i = 3; i <= sqrtl(n); i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        factors[n]++;
    }
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<vector<ll>> arr;
    vector<ll> temp;
    set<ll> unique;
    set<ll> track;
    for(int i=0;i<n;i++){
        ll l;
        cin>>l;
        temp.clear();
        track.clear();
        for(int j=0;j<l;j++){
            ll input;
            cin>>input;
            if(!unique.count(input)){
                unique.insert(input);
            }
            temp.push_back(input);
        }
        reverse(temp.begin(),temp.end());
        arr.push_back(temp);
    }
    for(int i=0;i<n;i++){
        track.clear();
        temp.clear();
        for(int j=0;j<arr[i].size();j++){
            if(!track.count(arr[i][j])){
                temp.push_back(arr[i][j]);
                track.insert(arr[i][j]);
            }
        }
        arr[i]=temp;
    }
    ll cnt=unique.size();
    set<ll> st;
    vector<ll> small;
    vector<ll> res;
    set<ll> pushed;
    vector<vector<ll>> narr;
    vector<ll> tp;
    for(int i=0;i<n;i++){
        sort(arr.begin(),arr.end());
        small=arr[0];
        ll len=small.size();
        bool done=false;
        pushed.clear();
        for(int j=0;j<len;j++){
            if(!st.count(small[j])){
                res.push_back(small[j]);
                st.insert(small[j]);
                pushed.insert(small[j]);
                if(st.size()==cnt){
                    done=true;
                    break;
                }
            }
        }
        if(done){
            break;
        }
        if(arr.empty()){
            break;
        }
        narr.clear();
        for(int j=1;j<arr.size();j++){
            tp.clear();
            for(int k=0;k<arr[j].size();k++){
                if(!pushed.count(arr[j][k])){
                    tp.push_back(arr[j][k]);
                }
            }
            narr.push_back(tp);
        }
        arr=narr;
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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
