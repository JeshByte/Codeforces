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
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    ll hodd=-1;
    priority_queue<ll>even_heap;
    ll olen=0,elen=0;
    for(int i=0;i<n;i++){
        if(arr[i]&1){
            hodd=max(hodd,arr[i]);
            olen++;
        }
        else{
            even_heap.push(arr[i]);
            elen++;
        }
    }
    if(elen==n){
        for(int i=1;i<=n;i++){
            cout<<0<<" ";
        }
        cout<<'\n';
        return;
    }
    if(olen==n){
        for(int i=1;i<=n;i++){
            if(i&1){
                cout<<hodd<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<'\n';
        return;
    }
    ll s=hodd;
    vector<ll> res(n+1);
    res[1]=s;
    ll prev=-1;
    for(int i=2;i<=n;i++){
        if(olen>=1 && elen>=(i-1)){
            s+=even_heap.top();
            prev=even_heap.top();
            even_heap.pop();
            res[i]=s;
        }
        else{
            ll remain=i-(1+elen);
            if(remain&1){
                remain++;
                if(remain<=(olen-1)){
                    res[i]=s-prev;
                }
                else{
                    res[i]=0;
                }
            }
            else{
                if(remain<=(olen-1)){
                    res[i]=s;
                }
                else{
                    res[i]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
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
