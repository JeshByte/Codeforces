#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    string s;
    cin>>s;
    ll n=s.size();
    //sort(s.begin(),s.end());
    for(int i=n-1;i>=0;i--){
        ll ind=i;
        while(ind!=n-1 && (s[ind]-'0')<((s[ind+1]-'0')-1)){
            ll num=s[ind+1]-'0';
            num--;
            s[ind+1]=num+'0';
            swap(s[ind],s[ind+1]);
            ind++;
        }
    }
    cout<<s<<'\n';
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
