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
    vector<ll> nextSmallest(vector<ll>& heights, ll n){
        stack<pair<ll,ll>>st;
        vector<ll>ans(n);
        for(ll i=n-1;i>=0;i--){
            ll tp=n;
            while(!st.empty()){
                if(st.top().first<heights[i]){
                    tp=st.top().second;
                    break;
                }
                st.pop();
            }
            ans[i]=tp;
            st.push({heights[i],i});
        }
        return ans;
    }
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    ll total=0;
    map<ll,ll> s,f;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    reverse(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        s[arr[i]]+=i;
        f[arr[i]]++;
        total+=i;
    }
    s[0]=0;
    f[0]=0;
    ll maxi=*max_element(arr.begin(),arr.end());
    ll ans=0;
    ll cnt=n;
    vector<ll> cnt_store(maxi+1,0);
    for(int i=0;i<=maxi;i++){
        total-=s[i];
        cnt-=f[i];
        cnt_store[i]=cnt;
        ll val=(cnt*(cnt-1))/2;
        ll tp=total-val;
        //cout<<total<<" "<<val<<'\n';
        //cout<<tp<<'\n';
        ans+=tp;
    }
    //cout<<ans<<'\n';
    ll initial=ans;
    for(int i=0;i<n;i++){
        ll ele=arr[i];
        ll freq=cnt_store[ele-1];
        ll val1=(freq*(freq-1))/2;
        freq--;
        ll val2=(freq*(freq-1))/2;
        ll temp=initial+val1-val2-i;
        //cout<<val1<<" "<<val2<<'\n';
        //cout<<i<<" "<<temp<<'\n';
        ans=max(ans,temp);
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
