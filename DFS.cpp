#include <bits/stdc++.h>
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back
#define ll long long
#define all(v) (v).begin(), (v).end()
#define Pair pair<long, long>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int const N=1e5+10;
vector<int>g[N];
ll const mod=1e9+7;

void dfs(int ver,int par){
    //take action before entering in vertex
        
        for(auto child:g[ver]){
            //take action before entering in child
            if(child==par)continue;
            dfs(child,ver);
    //take action after exiting child
            
        }
        //take action after exiting child
}

int main() {
    fast
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    
    dfs(1,0);
}
