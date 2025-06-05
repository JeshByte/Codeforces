#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<vector<ll>> b(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            b[i][j]=s[j]-'0';
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]!=b[i][j]){
                ll poss1=(a[i][j]+1)%3;
                ll poss2=(a[i][j]+2)%3;
                if(poss1==b[i][j]){
                    a[i][j]=(a[i][j]+1)%3;
                    a[i+1][j+1]=(a[i+1][j+1]+1)%3;
                    a[i][j+1]=(a[i][j+1]+2)%3;
                    a[i+1][j]=(a[i+1][j]+2)%3;
                }
                else{
                    a[i][j]=(a[i][j]+2)%3;
                    a[i+1][j+1]=(a[i+1][j+1]+2)%3;
                    a[i][j+1]=(a[i][j+1]+1)%3;
                    a[i+1][j]=(a[i+1][j]+1)%3;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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
