#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(){
    string s,t;
    cin>>s>>t;
    map<char,ll>mp;
    for(int i=0;i<t.size()-1;i++){
        mp[t[i]]=i;
    }
    pair<ll,ll>res={-1,-1};
    ll len=1e10;
    for(int i=1;i<s.size();i++){
        if(mp.find(s[i])!=mp.end()){
            ll ind=mp[s[i]];
            ll temp=i+(t.size()-ind-1)+1;
            if(temp<len){
                len=temp;
                res={i,ind};
            }
        }
    }
    if(res.first==-1){
        cout<<-1<<'\n';
        return;
    }
    //cout<<res.first<<" "<<res.second<<'\n';
    string ans="";
    for(int i=0;i<res.first;i++){
        ans+=s[i];
    }
    ans+=s[res.first];
    for(int i=res.second+1;i<t.size();i++){
        ans+=t[i];
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve();
  }
  return 0;
}
