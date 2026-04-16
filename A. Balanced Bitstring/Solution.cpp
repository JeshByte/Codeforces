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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<bool> visited(n,false);
    for(int i=0;i<=n-k;i++){
        if(visited[i]){
            continue;
        }
        vector<ll> cnt(3,0);
        for(int j=i;j<n;j+=k){
            if(s[j]=='?'){
                cnt[2]++;
            }
            else{
                cnt[s[j]-'0']++;
            }
            visited[j]=true;
        }
        if(cnt[0]>0 && cnt[1]>0){
            cout<<"NO\n";
            return;
        }
        if(cnt[0]>0){
        for(int j=i;j<n;j+=k){
            s[j]='0';
        }
        }
        else if(cnt[1]>0){
        for(int j=i;j<n;j+=k){
            s[j]='1';
        }
        }
    }
    vector<ll> cnt(3,0);
    for(int i=0;i<k;i++){
        if(s[i]=='?'){
            cnt[2]++;
        }
        else{
            cnt[s[i]-'0']++;
        }
    }
    if(cnt[2]>0){
        if(cnt[0]>cnt[1]){
            swap(cnt[0],cnt[1]);
        }
        ll less=cnt[1]-cnt[0];
        ll use=min(less,cnt[2]);
        cnt[0]+=use;
        cnt[2]-=use;
        cnt[0]+=(cnt[2]/2);
        cnt[1]+=(cnt[2]/2);
    }
    if(cnt[0]==cnt[1]){
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
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
