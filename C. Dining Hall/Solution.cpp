#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    set<vector<ll>> pq0,pq1;
    set<pair<ll,ll>> st;
    auto push=[&](ll X, ll Y){
        if(st.find({X,Y})!=st.end()){
            return;
        }
        pq0.insert({3*X+3*Y+2,X,Y});
        pq1.insert({3*X+3*Y+2,3*X+1,3*Y+1});
        pq1.insert({3*X+3*Y+3,3*X+1,3*Y+2});
        pq1.insert({3*X+3*Y+3,3*X+2,3*Y+1});
        pq1.insert({3*X+3*Y+6,3*X+2,3*Y+2});
        st.insert({X,Y});
    };
    push(0,0);
    push(0,1);
    push(1,0);
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            auto v=*pq0.begin();
            pq0.erase(v);
            ll X=v[1],Y=v[2];
            pq1.erase({3*X+3*Y+2,3*X+1,3*Y+1});
            cout<<3*X+1<<" "<<3*Y+1<<'\n';
            push(X,Y+1);
            push(X,Y+2);
            push(X+1,Y);
            push(X+2,Y);
            push(X+1,Y+1);
        }
        else{
            auto v=*pq1.begin();
            pq1.erase(v);
            ll X=v[1]/3,Y=v[2]/3;
            pq0.erase({3*X+3*Y+2,X,Y});
            push(X,Y+1);
            push(X,Y+2);
            push(X+1,Y);
            push(X+2,Y);
            push(X+1,Y+1);
            cout<<v[1]<<" "<<v[2]<<'\n';
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
