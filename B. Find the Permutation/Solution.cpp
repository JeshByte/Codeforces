#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void dfs(vector<vector<ll>>&adj,ll n,ll v,stack<ll>&st,vector<bool>&visited){
    visited[v]=true;
    for(int i=1;i<=n;i++){
        if(adj[v][i]==1 && !visited[i]){
            dfs(adj,n,i,st,visited);
        }
    }
    st.push(v);
}
vector<ll> topologicalSort(vector<vector<ll>>&adj,ll n){
    vector<bool>visited(n+1,false);
    stack<ll>st;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,n,i,st,visited);
        }
    }
    vector<ll>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
void solve(ll t){
    ll n;
    cin>>n;
    vector<vector<ll>>adj(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            if(i<j && s[j-1]=='1'){
                adj[i][j]=1;
            }
            else if(i<j && s[j-1]=='0'){
                adj[j][i]=1;
            }
            else if(i>j && s[j-1]=='1'){
                adj[j][i]=1;
            }
            else if(i>j && s[j-1]=='0'){
                adj[i][j]=1;
            }
        }
    }
    //dfs(adj,visited,perm,1,n);
    vector<ll>ans=topologicalSort(adj,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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
