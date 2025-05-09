#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    if(n&1){
        map<char,ll>odd,even,preodd,preeven;
        for(int i=0;i<n;i++){
            if(!(i&1)){
                odd[s[i]]++;
            }
            else{
                even[s[i]]++;
            }
        }
        ll ans=1e10;
        map<char,ll>nodd,neven;
        for(int i=0;i<n;i++){
            ll emax=-1;
            ll omax=-1;
            nodd.clear();
            neven.clear();
            for(auto it:preodd){
                nodd[it.first]+=it.second;
            }
            for(auto it:preeven){
                neven[it.first]+=it.second;
            }
            if(!(i&1)){
                preodd[s[i]]++;
            }
            else{
                preeven[s[i]]++;
            }
            for(auto it:odd){
                if(preodd.find(it.first)==preodd.end()){
                    neven[it.first]+=it.second;
                }
                else{
                    neven[it.first]+=it.second-preodd[it.first];
                }
            }
            for(auto it:even){
                if(preeven.find(it.first)==preeven.end()){
                    nodd[it.first]+=it.second;
                }
                else{
                    nodd[it.first]+=it.second-preeven[it.first];
                }
            }
            for(auto it:nodd){
                omax=max(omax,it.second);
            }
            for(auto it:neven){
                emax=max(emax,it.second);
            }
            ll req=n/2;
            ll temp=(req-emax)+(req-omax);
            temp++;
            ans=min(temp,ans);
            //cout<<i<<" "<<temp<<'\n';
        }
        cout<<ans<<'\n';
    }
    else{
        map<char,ll>odd,even;
        for(int i=0;i<n;i++){
            if(!(i&1)){
                odd[s[i]]++;
            }
            else{
                even[s[i]]++;
            }
        }
        ll emaxi=-1,omaxi=-1;
        for(auto it:even){
            emaxi=max(emaxi,it.second);
        }
        for(auto it:odd){
            omaxi=max(omaxi,it.second);
        }
        ll req=n/2;
        ll ans=(req-emaxi)+(req-omaxi);
        cout<<ans<<'\n';
    }
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
