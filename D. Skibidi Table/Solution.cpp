#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
pair<uint32_t, uint32_t> getCoordinates(uint64_t target, int n) {
    uint32_t x = 0, y = 0;
    uint64_t value = 1;
    uint32_t size = 1u << n;

    for (int level = 0; level < n; ++level) {
        size >>= 1;
        uint64_t block_size = uint64_t(size) * size;

        if (target < value + block_size) {

        } else if (target < value + 2 * block_size) {

            x += size;
            y += size;
            value += block_size;
        } else if (target < value + 3 * block_size) {

            x += size;
            value += 2 * block_size;
        } else {

            y += size;
            value += 3 * block_size;
        }
    }


    if (target == value) {

    } else if (target == value + 1) {
        x += 1;
        y += 1;
    } else if (target == value + 2) {
        x += 1;
    } else if (target == value + 3) {
        y += 1;
    } else {

        return {UINT32_MAX, UINT32_MAX};
    }

    return {x, y};
}
uint64_t getValueAt(uint32_t x, uint32_t y, int n) {
    uint64_t value = 1;
    uint32_t size = 1u << n;

    for (int level = 0; level < n; ++level) {
        size >>= 1; 
        uint64_t block_size = uint64_t(size) * size;

        if (x < size && y < size) {

        } else if (x >= size && y >= size) {

            value += block_size;
            x -= size;
            y -= size;
        } else if (x >= size && y < size) {

            value += 2 * block_size;
            x -= size;
        } else {

            value += 3 * block_size;
            y -= size;
        }
    }


    if (x == 0 && y == 0) return value;
    if (x == 1 && y == 1) return value + 1;
    if (x == 1 && y == 0) return value + 2;
    if (x == 0 && y == 1) return value + 3;

    return 0; 
}
void solve(ll t){
    ll n;
    cin>>n;
    ll q;
    cin>>q;
    map<pair<ll,ll>,ll>mp;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s=="->"){
            ll x,y;
            cin>>x>>y;
            cout<<getValueAt(x-1,y-1,n)<<'\n';
        }
        else{
            ll d;
            cin>>d;
            pair<ll,ll>ans=getCoordinates(d,n);
            cout<<ans.first+1<<" "<<ans.second+1<<'\n';
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
