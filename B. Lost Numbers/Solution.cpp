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
void comp(vector<ll>& res,ll ind1,ll ind2,ll ind3,map<ll,pair<ll,ll>>& mp){
    cout<<"?"<<" "<<ind1<<" "<<ind2<<endl;
    fflush(stdout);
    ll prod1;
    cin>>prod1;
    cout<<"?"<<" "<<ind2<<" "<<ind3<<endl;
    fflush(stdout);
    ll prod2;
    cin>>prod2;
    pair<ll,ll> p1=mp[prod1];
    pair<ll,ll> p2=mp[prod2];
    // cout<<prod2<<":"<<p2.first<<" "<<p2.second<<'\n';
    // fflush(stdout);
    // cout<<prod1<<":"<<p1.first<<" "<<p1.second<<'\n';
    // fflush(stdout);
    if(p1.first==p2.first){
        //cout<<"hi\n";
        res[ind1]=p1.second;
        res[ind2]=p1.first;
        res[ind3]=p2.second;
    }
    if(p1.first==p2.second){
        //cout<<"hi\n";
        res[ind1]=p1.second;
        res[ind2]=p1.first;
        res[ind3]=p2.first;
    }
    if(p1.second==p2.first){
        //cout<<"hi\n";
        res[ind1]=p1.first;
        res[ind2]=p1.second;
        res[ind3]=p2.second;
    }
    if(p1.second==p2.second){
        //cout<<"hi\n";
        res[ind1]=p1.first;
        res[ind2]=p1.second;
        res[ind3]=p2.first;
    }
    // cout<<"! ";
    // for(int i=1;i<=6;i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    // fflush(stdout);
}
void solve(ll t,ll testcases){
    vector<ll> num={4,8,15,16,23,42};
    map<ll,pair<ll,ll>> mp;
    for(int i=0;i<num.size();i++){
        for(int j=i+1;j<num.size();j++){
            mp[(num[i]*num[j])]=make_pair(num[i],num[j]);
        }
    }
    // for(auto it:mp){
    //     ll prod=it.first;
    //     pair<ll,ll> p=it.second;
    //     cout<<prod<<":"<<p.first<<" "<<p.second<<'\n';
    // }
    vector<ll> res(7,0);
    comp(res,1,2,3,mp);
    comp(res,4,5,6,mp);
    cout<<"! ";
    for(int i=1;i<=6;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    fflush(stdout);
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
