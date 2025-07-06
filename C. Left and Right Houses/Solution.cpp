#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    // if(t==34){
    //     cout<<n<<'\n';
    //     cout<<s<<'\n';
    // }
    ll total=count(s.begin(),s.end(),'1');
    ll ones=0,zeroes=0;
    ll pos=-1;
    double mini=1e6;
    if(total>=Ceil(n,2)){
        pos=-1;
        mini=(double)n/2.0;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ones++;
        }
        else{
            zeroes++;
        }
        ll left=i+1;
        ll right=n-i-1;
        if(zeroes>=Ceil(left,2) && (total-ones)>=Ceil(right,2)){
            double dist=abs(((double)n/2.0)-(i+1));
            if(dist<mini){
                mini=dist;
                pos=i;
            }
        }
    }
    // if(pos==n-1){
    //     if(total>=Ceil(n,2)){
    //         pos=-1;
    //     }
    // }
    cout<<pos+1<<'\n';
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
