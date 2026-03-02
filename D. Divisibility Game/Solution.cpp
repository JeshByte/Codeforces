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
void toBinary(ll n,vector<ll>& bin){
    while(n){
        bin.push_back(n%2);
        n=n/2;
    }
    //reverse(bin.begin(),bin.end());
}
bool check(ll mid,vector<ll>&binm,vector<ll>&bins,ll ind,ll carry){
    ll pc=carry-mid;
    ll b=mid;
    for(int i=ind-1;i>=0;i--){
        ll total;
        if(bins[i]==0){
            total=pc*2;
        }
        else{
            total=pc*2+1;
        }
        if(binm[i]==0){
            pc=total;
            continue;
        }
        if(total<mid){
            return true;
        }
        else{
            pc=total-mid;
        }
    }
    if(pc==0){
        return true;
    }
    return false;
}
void solve(ll t){
    ll n,m;
    cin>>n>>m;
    vector<ll> a,b;
    vector<ll> freq(n+m+1,0);
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        a.push_back(input);
    }
    for(int i=0;i<m;i++){
        ll input;
        cin>>input;
        b.push_back(input);
        freq[input]++;
    }
    vector<bool> Alice(n+m+1,false),Bob(n+m+1,false),done(n+m+1,false),inter(n+m+1,false);
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        ll val=a[i];
        if(done[val]){
            continue;
        }
        for(;val<=(n+m);val+=a[i]){
            if(freq[val]>0){
                Alice[val]=true;
            }
            done[val]=true;
        }
    }
    ll lcm=1;
    for(int i=0;i<n;i++){
        ll gcd=__gcd(lcm,a[i]);
        ll prod=lcm*a[i];
        lcm=prod/gcd;
        if(lcm>(n+m)){
            //cout<<"lcm:"<<lcm<<'\n';
            lcm=(n+m)+1;
            break;
        }
    }
    //cout<<lcm<<'\n';
    for(int i=0;i<m;i++){
        if(b[i]%lcm!=0){
            Bob[b[i]]=true;
        }
    }
    for(int i=1;i<Alice.size();i++){
        if(Bob[i] && Alice[i]){
            inter[i]=true;
        }
    }
    bool turn=true;
    for(int i=1;i<inter.size();i++){
        if(inter[i]){
                    if(freq[i]%2!=0){
            turn=!turn;
        }
        freq[i]=0;
        }
    }
    // for(auto it:Alice){
    //     cout<<it<<" ";
    // }
    // cout<<'\n';
    // for(auto it:Bob){
    //     cout<<it<<" ";
    // }
    // cout<<'\n';
    // for(auto it:inter){
    //     cout<<it<<" ";
    // }
    // cout<<'\n';
    ll nAlice=0,nBob=0;
    for(int i=1;i<Alice.size();i++){
        if(Alice[i] && freq[i]>0){
            nAlice+=freq[i];
        }
    }
    for(int i=1;i<Bob.size();i++){
        if(Bob[i] && freq[i]>0){
            nBob+=freq[i];
        }
    }
    //cout<<nAlice<<" "<<nBob<<'\n';
    if(turn){
        //cout<<"hi"<<'\n';
        if(nAlice==0){
            cout<<"Bob\n";
        }
        else if(nAlice<=nBob){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
    }
    else{
        if(nBob==0){
            cout<<"Alice\n";
        }
        else if(nBob<=nAlice){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
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
