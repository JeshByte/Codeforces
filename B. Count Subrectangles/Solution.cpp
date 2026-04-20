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
ll highestBit(ll n){
    ll bit=0;
    for(int i=0;i<64;i++){
        ll mask=1ll<<i;
        if(n&mask){
            bit=i;
        }
    }
    return bit;
}
void findContinous(vector<ll>& store, vector<ll> arr){
    ll len=arr.size();
    ll i=0;
    while(i<len){
        if(arr[i]==0){
            i++;
            continue;
        }
        ll cnt=0;
        ll tp=arr[i];
        while(i<len && arr[i]==tp){
            cnt++;
            i++;
        }
        store.push_back(cnt);
    }
}
void solve(ll t,ll testcases){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a,b;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        b.push_back(input);
    }
    vector<ll> rows,cols;
    findContinous(rows,a);
    // for(int i=0;i<rows.size();i++){
    //     cout<<rows[i]<<" ";
    // }
    // cout<<'\n';
    findContinous(cols,b);
    // for(int i=0;i<rows.size();i++){
    //     cout<<rows[i]<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<cols.size();i++){
    //     cout<<cols[i]<<" ";
    // }
    // cout<<'\n';

    sort(rows.begin(),rows.end());
    sort(cols.begin(),cols.end());
    ll csize=cols.size();
    vector<ll> csuff(csize+1,0);
    for(int i=csize-1;i>=0;i--){
        csuff[i]=csuff[i+1]+cols[i];
    }
    ll rsize=rows.size();
    vector<ll> rsuff(rsize+1,0);
    for(int i=rsize-1;i>=0;i--){
        rsuff[i]=rsuff[i+1]+rows[i];
    }
    // for(int i=0;i<=csize;i++){
    //     cout<<suff[i]<<" ";
    // }
    // cout<<'\n';
    vector<pair<ll,ll>> factors;
    for(int i=1;i<=sqrt(k);i++){
        if(k%i==0){
            ll other=k/i;
            factors.push_back({i,other});
            if(i!=other){
                factors.push_back({other,i});
            }
        }
    }
    ll ans=0;
    ll fsize=factors.size();
    // for(int i=0;i<fsize;i++){
    //     cout<<factors[i].first<<" "<<factors[i].second<<'\n';
    // }
    for(int i=0;i<fsize;i++){
        ll r=factors[i].first;
        ll c=factors[i].second;
        ll rind=lower_bound(rows.begin(),rows.end(),r)-rows.begin();
        ll rsum=rsuff[rind];
        ll rcnt=rsize-rind;
        ll t1=rsum-(r*rcnt)+rcnt;
        ll cind=lower_bound(cols.begin(),cols.end(),c)-cols.begin();
        ll csum=csuff[cind];
        ll ccnt=csize-cind;
        ll t2=csum-(c*ccnt)+ccnt;
        ans+=(t1*t2);
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
