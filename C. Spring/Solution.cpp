#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
 
        exp = exp >> 1;
 
        base = (base * base) % mod;
    }
    return result;
}
ll findInverse(ll n,ll MOD){
    return modExpo(n,MOD-2,MOD);
}
ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}
void solve(ll t,ll testcases){
    ll a,b,c,m;
    cin>>a>>b>>c>>m;
    vector<ll> arr={a,b,c};
    ll lcmAB=(a*b)/(__gcd(a,b));
    ll lcmAC=(a*c)/(__gcd(a,c));
    ll lcmBC=(b*c)/(__gcd(b,c));
    ll lcmABC=(lcmAB*c)/(__gcd(lcmAB,c));
    ll ansA,ansB,ansC;
    ansA=ansB=ansC=0;
    ansA+=((m/a)-(m/lcmAB)-(m/lcmAC)+(m/lcmABC))*6;

    ansB+=((m/b)-(m/lcmAB)-(m/lcmBC)+(m/lcmABC))*6;

    ansC+=((m/c)-(m/lcmBC)-(m/lcmAC)+(m/lcmABC))*6;

    ansA+=((m/lcmAB)-(m/lcmABC))*3;
    ansB+=((m/lcmAB)-(m/lcmABC))*3;

    ansA+=((m/lcmAC)-(m/lcmABC))*3;
    ansC+=((m/lcmAC)-(m/lcmABC))*3;

    ansB+=((m/lcmBC)-(m/lcmABC))*3;
    ansC+=((m/lcmBC)-(m/lcmABC))*3;

    ansA+=(m/lcmABC)*2;
    ansB+=(m/lcmABC)*2;
    ansC+=(m/lcmABC)*2;

    cout<<ansA<<" "<<ansB<<" "<<ansC<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
