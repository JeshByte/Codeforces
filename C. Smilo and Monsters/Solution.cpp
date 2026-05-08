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
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    multiset<pair<ll,ll>> st;
    for(int i=0;i<n;i++){
        st.insert({arr[i],i});
    }
    ll ans=0;
    ll x=0;
    while(!st.empty()){
        pair<ll,ll> mini=*st.begin();
        auto it=st.end();
        it--;
        pair<ll,ll> maxi=*it;
        //cout<<"mini:"<<mini.first<<" "<<mini.second<<'\n';
        //cout<<"maxi:"<<maxi.first<<" "<<maxi.second<<'\n';
        if(mini==maxi){
            ll val=mini.first;
            ll need=(val-x)/2;
            x+=need;
            ans+=need;
            val-=need;
            val-=x;
            if(x>0){
                ans++;
            }
            ans+=val;
            st.erase(mini);
        }
        else{
            ll mx=maxi.first;
            ll mi=mini.first;
            ll need=mx-x;
            ll use=min(need,mi);
            x+=use;
            ans+=use;
            st.erase(mini);
            mi-=use;
            if(mi>0){
                st.insert({mi,mini.second});
            }
            if(x==mx){
                x=0;
                ans++;
                st.erase(maxi);
            }
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
