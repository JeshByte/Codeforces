#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll>arr(n,0);
    ll tx=min(x,y);
    ll ty=max(x,y);
    x=tx;
    y=ty;
    if(n&1){
        x--;
        y--;
        ll num=y-x-1;
        if(num&1){
            ll mid=(x+y)/2;
            arr[mid]=2;
            for(int i=mid-2;i>=0;i-=2){
                arr[i]=1;
            }
            for(int i=mid+1;i<n;i+=2){
                arr[i]=1;
            }
        }
        else{
            if(x!=0){
                arr[0]=2;
                for(int i=1;i<n;i+=2){
                    arr[i]=1;
                }
            }
            else{
                for(int i=0;i<n-1;i+=2){
                    arr[i]=1;
                }
                arr[n-1]=2;
            }
        }
    }
    else{
        for(int i=1;i<n;i+=2){
            arr[i]=1;
        }
        x--;
        y--;
        if(arr[x]==arr[y]){
            arr[y]=2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
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
