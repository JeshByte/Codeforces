#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Ceil(a,b) ((a+b-1)/b)

pair<int, int> findTwoMex(const vector<ll>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());

    int mex1 = 0;
    while (s.count(mex1)) {
        mex1++;
    }

    s.insert(mex1);

    int mex2 = 0;
    while (s.count(mex2)) {
        mex2++;
    }

    return {mex1, mex2};
}
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>arr;
    vector<ll>temp;
    for(int i=0;i<n;i++){
        ll l;
        cin>>l;
        temp.clear();
        for(int j=0;j<l;j++){
            ll input;
            cin>>input;
            temp.push_back(input);
        }
        arr.push_back(temp);
    }
    ll mx=-1;
    for(int i=0;i<n;i++){
        pair<ll,ll>tp=findTwoMex(arr[i]);
        //cout<<tp.first<<" "<<tp.second<<'\n';
        mx=max(mx,max(tp.first,tp.second));
    }
    if(m<=mx){
        //cout<<mx<<'\n';
        ll ans=(m+1)*(mx);
        cout<<ans<<'\n';
    }
    else{
        //cout<<mx<<'\n';
        ll ans=mx*(mx+1);
        ll a=mx+1;
        ll l=m;
        ll n=l-a+1;
        ll temp=(n*(a+l))/2;
        //cout<<ans<<" "<<temp<<'\n';
        ans+=temp;
        cout<<ans<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
    solve();
    }
    return 0;
  } 
