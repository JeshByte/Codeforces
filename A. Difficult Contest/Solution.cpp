#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    string s;
    cin>>s;
    ll n=s.size();
    string ns="";
    vector<char>F,N,T,other;
    for(int i=0;i<n;i++){
        if(s[i]=='F'){
            F.push_back(s[i]);
        }
        else if(s[i]=='N'){
            N.push_back(s[i]);
        }
        else if(s[i]=='T'){
            T.push_back(s[i]);
        }
        else{
            other.push_back(s[i]);
        }
    }
    for(int i=0;i<T.size();i++){
        ns+=T[i];
    }
    for(int i=0;i<other.size();i++){
        ns+=other[i];
    }
    for(int i=0;i<F.size();i++){
        ns+=F[i];
    }
    for(int i=0;i<N.size();i++){
        ns+=N[i];
    }
    cout<<ns<<'\n';
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
