#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
int e[N],w[N],ne[N],h[N],dist[N];
bool st[N];
int n,m,a,b,c,idx;
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[j]<dist[t]))
               t=j;
        }
        st[t]=true;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            dist[j]=min(dist[j],dist[t]+w[i]);
        }
    }
    
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--){
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dijkstra();
    if(dist[n]!=0x3f3f3f3f) cout<<dist[n]<<endl;
    else cout<<"-1"<<endl;
}