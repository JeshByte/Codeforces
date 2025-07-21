#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll ans=0;
    ll i=0;
    while(i<n){
        if(arr[i]==0){
            bool isPoss=true;
            ll len=0;
            for(int j=i;j<i+k && j<n;j++){
                if(arr[j]==1){
                    isPoss=false;
                    i=j+1;
                    break;
                }
                len++;
            }
            if(isPoss && len>=k){
                ans++;
                i+=(k+1);
            }
            else if(isPoss && len<k){
                break;
            }
        }
        else{
            i++;
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
