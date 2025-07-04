#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    string ans="";
    bool side=true;
    while(ans.size()<n){
        if(side){
        string temp=ans;
        temp+="0";
        cout<<"? "<<temp<<endl;
        cout.flush();
        ll res;
        cin>>res;
        if(res){
            ans=temp;
            continue;
        }
        temp=ans;
        temp+="1";
        cout<<"? "<<temp<<endl;
        cout.flush();
        cin>>res;
        if(res){
            ans=temp;
            continue;
        }
        side=!side;
        }
        else{
            string temp=ans;
            temp="0"+temp;
            cout<<"? "<<temp<<endl;
            cout.flush();
            ll res;
            cin>>res;
            if(res){
                ans=temp;
            }
            else{
                ans="1"+ans;
            }
        }
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
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
