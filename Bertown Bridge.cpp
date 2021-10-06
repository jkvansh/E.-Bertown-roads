#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int vis[1000003]={0};
int low[1000003],in[1000003];
vector<int>adj[1000003];
int timer=0;
vector<pair<int,int>>ans;
//comment pushback
int l=0;
void dfs(int v,int par){
    vis[v]=1;
    in[v]=low[v]=timer++;
    for(int child:adj[v]){
        if(child==par){
            continue;
        }
        if(vis[child]==1){
            low[v]=min(low[v],in[child]);
            if(in[v]>in[child]){
                ans.pb({v,child});
            }
        }
        else{
            dfs(child,v);
            if(low[child]>in[v]){
                l=1;
                return;
            }
            ans.pb({v,child});
            low[v]=min(low[v],low[child]);
        }
        
    }
    return;
}
int main() {    
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,-1);
    /*cout<<"sfjj;
	    //sapm*/
    if(l==1){
        cout<<"0";
    }
    else if(l==0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }
	return 0;
}

