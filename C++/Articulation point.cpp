#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int tin[N],low[N];
bool vis[N];
int timer;

vector<int> ap;

void dfs(int v,int p = -1)
{
    vis[v] = 1;
    tin[v] = low[v] = timer;
    timer++;
    int child = 0;
    bool pos = 0;
    for(auto x : g[v])
    {
        if(x == p)
            continue;
        if(vis[x])
            low[v] = min(low[v],tin[x]);
        else
        {
            dfs(x,v);
            low[v] = min(low[v],low[x]);
            if(low[x] >= tin[v] && p != -1)
                pos = 1;
            child++;
        }
    }
    if(p==-1 && child > 1)
        pos = 1;
    if(pos)
        ap.push_back(v);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0,a,b;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(auto x : ap)
        cout << x << " ";
}