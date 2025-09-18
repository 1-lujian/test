#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=510;
int g[N][N],dist[N];
bool st[N];
int n,m,u,v,w,res;
int prim(){
    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
         if(!st[j]&&(t==-1||dist[j]<dist[t]))
            t=j;
           if(i&&dist[t]==0x3f3f3f3f) return 0x3f3f3f3f;
           if(i) res+=dist[t];
           for(int j=1;j<=n;j++)
             dist[j]=min(dist[j],g[t][j]);
             st[t]=true;
    }
    return res;
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    while(m--){
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    int t=prim();
    if(t==0x3f3f3f3f) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
    
}