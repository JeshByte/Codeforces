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
bool check(ll mid,ll n,ll m,ll l,vector<ll>& arr,vector<ll>& ph){
    for(int i=0;i<m;i++){
        ph[i]=0;
    }
    ll t=0;
    for(int i=0;i<n;i++){
        ll time=(arr[i]-1)-t;
        ll init=time/m;
        for(int j=0;j<m;j++){
            ph[j]+=init;
        }
        ll rest=time-(init*m);
        
    }
}
void solve(ll t,ll testcases){
    ll n,h;
    cin>>n>>h;
    vector<ll> heights;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        heights.push_back(input);
    }
    // if(testcases==419){
    //     if(t==212){
    //         cout<<n<<" "<<h<<'\n';
    //         for(int i=0;i<n;i++){
    //             cout<<heights[i]<<" ";
    //         }
    //         cout<<'\n';
    //     }
    //     else{
    //         return;
    //     }
    // }
    ll maxi=*max_element(heights.begin(),heights.end());
    ll ans=n*(h-maxi);
    // cout<<ans<<'\n';
    // for(int i=0;i<bounds.size();i++){
    //     cout<<bounds[i]<<" ";
    // }
    // cout<<'\n';
    vector<ll> contri(n);
        for(int j=0;j<n;j++){
            ll curr=j-1;
            ll total=maxi-heights[j];
            ll val=heights[j];
            while(curr>=0){
                val=max(val,heights[curr]);
                if(val==maxi){
                    break;
                }
                total+=(maxi-val);
                curr--;
            }
            curr=j+1;
            val=heights[j];
            while(curr<n){
                val=max(val,heights[curr]);
                if(val==maxi){
                    break;
                }
                total+=(maxi-val);
                curr++;
            }
            contri[j]=total;
        }
    vector<vector<ll>> mx(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        ll maxi=-1;
        ll ind=-1;
        for(int j=i;j<n;j++){
            if(heights[j]>maxi){
                maxi=heights[j];
                ind=j;
            }
            mx[i][j]=ind;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<contri[i]<<" ";
    // }
    // cout<<'\n';
    ll rest=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll m=mx[i][j];
            ll tp=contri[i]+contri[j]-contri[m];
            //cout<<tp<<" "<<i<<" "<<j<<m<<'\n';
            rest=max(rest,tp);
        }
    }
    cout<<ans+rest<<'\n';
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
