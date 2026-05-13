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
ll findReq(ll l,ll g){
    ll req=1;
    if(l>g){
        swap(l,g);
    }
    ll need=g-l;
    req+=need;
    return req;
}
bool check(ll l,ll e,ll g){
    if(e<1){
        return false;
    }
    ll remain=e-1;
    if(l<=g){
        ll need=g-l;
        if(need<=remain){
            l+=need;
            remain-=need;
        }
        else{
            return false;
        }
    }
    else{
        ll need=l-g;
        if(need<=remain){
            g+=need;
            remain-=need;
        }
        else{
            return false;
        }
    }
    if(l==g && remain%2==0){
        return true;
    }
    return false;
}
ll rec(vector<ll>& arr, ll ind, ll med, ll n){
    if(ind>=n){
        return 0;
    }
    vector<ll> dp(n+1,-1);
    dp[n]=0;
    for(int ind=n-1;ind>=0;ind--){
    ll l,e,g;
    l=e=g=0;
    ll ans=-1;
    for(int i=ind;i<n;i++){
        if(arr[i]==med){
            e++;
        }
        else if(arr[i]<med){
            l++;
        }
        else{
            g++;
        }
        ll len=i-ind+1;
        // if(ind==0 && i==0){
        //     cout<<l<<" "<<e<<" "<<g<<'\n';
        // }
        if(len%2==1 && check(l,e,g)){
            ll rest=dp[i+1];
            //cout<<ind<<" "<<i<<" "<<rest<<'\n';
            if(rest!=(-1)){
                //cout<<ind<<" "<<1+rest<<'\n';
                ans=max(ans,1+rest);
            }
        }
    }
    dp[ind]=ans;
    }
    return dp[0];
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<vector<ll>> arr;
    for(int i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        if(l>r){
            swap(l,r);
        }
        arr.push_back({l,r,i});
    }
    vector<vector<ll>> tp=arr;
    sort(arr.begin(),arr.end(),[](vector<ll>a,vector<ll>b){
        if(a[1]!=b[1]){
            return a[1]>b[1];
        }
        else{
            return a[0]>b[0];
        }
    });
    // for(int i=0;i<n;i++){
    //     cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<'\n';
    // }
    map<ll,bool> mark;
    ll mini=arr[0][0];
    mark[arr[0][2]]=true;
    ll cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i][1]>=mini){
            mark[arr[i][2]]=true;
            mini=min(mini,arr[i][0]);
            cnt++;
        }
    }
    if(cnt>=n){
        cout<<-1<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(mark[i]){
            cout<<1<<" ";
        }
        else{
            cout<<2<<" ";
        }
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
