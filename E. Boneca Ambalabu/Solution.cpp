#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
string convert(ll num){
    string s="";
    while(num){
        ll bit=num&1;
        num=num>>1;
        if(bit==1){
            s+="1";
        }
        else{
            s+="0";
        }
    }
    while(s.size()<32){
        s+="0";
    }
    reverse(s.begin(),s.end());
    return s;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<string> mat;
    for(int i=0;i<n;i++){
        string s=convert(arr[i]);
        //cout<<s<<'\n';
        mat.push_back(s);
    }
    // for(int i=0;i<n;i++){
    //     cout<<mat[i]<<'\n';
    // }
    vector<ll> zeroes(32,0),ones(32,0);
    for(int i=0;i<32;i++){
        for(int j=0;j<n;j++){
            if(mat[j][i]=='1'){
                ones[i]++;
            }
            else{
                zeroes[i]++;
            }
        }
    }
    // for(int i=0;i<32;i++){
    //     cout<<ones[i]<<" ";
    // }
    // cout<<'\n';
    // for(int i=0;i<32;i++){
    //     cout<<zeroes[i]<<" ";
    // }
    // cout<<'\n';
    ll ans=-1;
    for(int i=0;i<n;i++){
        ll temp=0;
        for(int j=0;j<32;j++){
            if(mat[i][j]=='1'){
                temp+=(zeroes[j]*(1ll<<(31-j)));
            }
            else{
                temp+=(ones[j]*(1ll<<(31-j)));
            }
        }
        //cout<<temp<<'\n';
        ans=max(ans,temp);
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
