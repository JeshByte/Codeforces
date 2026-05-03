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
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    reverse(arr.begin(),arr.end());
    vector<ll> contri(n,0);
    ll mini=1e6;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
        contri[i]=arr[i]-mini;
    }
    vector<ll> suffix(n+1,0);
    for(int i=n-1;i>=0;i--){
        suffix[i]=suffix[i+1]+contri[i];
    }
    vector<ll> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    ll ans=suffix[0];
    vector<ll> next=nextSmallest(arr,n);
    ll back=0;
    mini=1e6;
    // for(int i=0;i<n;i++){
    //     cout<<contri[i]<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<=n;i++){
    //     cout<<suffix[i]<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<=n;i++){
    //     cout<<prefix[i]<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<n;i++){
    //     cout<<next[i]<<" ";
    // }
    // cout<<'\n';
    for(int i=0;i<n;i++){
        ll after=next[i];
        ll afterContri=0;                                    
        if(after<n){
            afterContri=suffix[after];
        }
        ll s=prefix[after]-prefix[i+1];
        s+=(arr[i]-1);
        ll tp=min(mini,arr[i]-1);
        ll val=s-((tp)*(after-i));
        ans=max(ans,val+afterContri+back);
        mini=min(mini,arr[i]);
        back+=(arr[i]-mini);
        //cout<<val<<" "<<afterContri<<" "<<back<<'\n';
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
