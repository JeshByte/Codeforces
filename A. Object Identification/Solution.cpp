#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>x;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        x.push_back(input);
    }
    if(count(x.begin(),x.end(),x[0])==n){
        cout<<"? 1 2"<<endl;
        fflush(stdout);
        ll res1;
        cin>>res1;
        cout<<"? 1 3"<<endl;
        fflush(stdout);
        ll res2;
        cin>>res2;
        cout<<"! B"<<endl;
        fflush(stdout);
        return;
    }
    bool dup=false;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        mp[x[i]]++;
        if(mp[x[i]]>1){
            dup=true;
        }
    }
    if(dup){
        ll req;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                req=i;
            }
        }
        ll req2;
        for(int i=0;i<n;i++){
            if(x[i]!=x[req-1]){
                req2=i+1;
            }
        }
        cout<<"? "<<req<<" "<<req2<<endl;
        fflush(stdout);
        ll res1;
        cin>>res1;
        cout<<"? 1 2"<<endl;
        fflush(stdout);
        ll res2;
        cin>>res2;
        if(res1==0){
            cout<<"! A"<<endl;
            fflush(stdout);
        }
        else{
            cout<<"! B"<<endl;
            fflush(stdout);
        }
    }
    else{
        ll maxi=max_element(x.begin(),x.end())-x.begin();
        ll mini=min_element(x.begin(),x.end())-x.begin();
        cout<<"? "<<mini+1<<" "<<maxi+1<<endl;
        fflush(stdout);
        ll res1;
        cin>>res1;
        cout<<"? "<<maxi+1<<" "<<mini+1<<endl;
        fflush(stdout);
        ll res2;
        cin>>res2;
        ll req=n-1;
        if(res1>req){
            cout<<"! B"<<endl;
            fflush(stdout);
        }
        else if(res1<req){
            cout<<"! A"<<endl;
            fflush(stdout);
        }
        else if(res1==req && res2==req){
            cout<<"! B"<<endl;
            fflush(stdout);
        }
        else{
            cout<<"! A"<<endl;
            fflush(stdout);
        }
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
