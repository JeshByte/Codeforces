#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,c;
    cin>>n>>c;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    sort(arr.rbegin(),arr.rend());
    ll i=0,ans=0,mul=0;
    set<ll> st;
    while(i<n){
        if(arr[i]<=c){
            for(int j=0;j<n;j++){
                arr[j]*=2;
            }
            st.insert(i);
        }
        i++;
    }
    for(int i=0;i<n;i++){
        if(!st.count(i)){
            ans++;
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
  solve(i);
  }
  return 0;
}
