#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int h[N],ne[N],w[N],e[N],backup[N],dist[N];
int n,m,k,x,y,z,idx;
void add(int x,int y,int z){
    e[idx]=y;
    w[idx]=z;
    ne[idx]=h[x];
    h[x]=idx++;
}
void bf(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof(dist));
        for(int j=1;j<=n;j++){
            for(int t=h[j];t!=-1;t=ne[t]){
                 int r=e[t];
                if(dist[r]>backup[j]+w[t])
                  dist[r]=backup[j]+w[t];
            }
            
        }
    }
}
int main(){
    cin>>n>>m>>k;
    memset(h,-1,sizeof(h));
    while(m--){
        cin>>x>>y>>z;
        add(x,y,z);
    }
    bf();
    if(dist[n]>0x3f3f3f3f/2) cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;
    return 0;
    
}