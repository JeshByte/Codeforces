#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
vector<ll>nines;
void precompute(){
    ll num=9;
    while(num<=1e10){
        nines.push_back(num);
        num=num*10+9;
    }
}
bool check(ll n){
    ll temp=n;
    while(temp){
        if(temp%10==7){
            return true;
        }
        temp=temp/10;
    }
    return false;
}
void solve(ll t){
    ll n;
    cin>>n;
    ll mini=11;
    if(check(n)){
        cout<<0<<'\n';
        return;
    }
    for(ll i=0;i<nines.size();i++){
        ll add=nines[i];
        ll temp=n;
        for(ll i=1;i<=10;i++){
            temp+=add;
            if(check(temp)){
                mini=min(mini,i);
            }
        }
    }
    cout<<mini<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  precompute();
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
} 
