#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=100010;
typedef pair<int,int>PII;
int n,m,x,y,z,idx;
int h[N],w[N],ne[N],dist[N],e[N];
bool st[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
void spfa(){
    queue<PII>q;
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    st[1]=true;
    q.push({0,1});
    while(q.size()){
        auto t=q.front();
        q.pop();
        int b=t.second;
        st[b]=false;
        for(int i=h[b];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[b]+w[i]){
                dist[j]=dist[b]+w[i];
                if(!st[j]){
                    st[j]=true;
                    q.push({dist[j],j});
                }
            }
        }
        
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--){
        cin>>x>>y>>z;
        add(x,y,z);
    }
    spfa();
    if(dist[n]>0x3f3f3f3f/2) cout<<"impossible";
    else cout<<dist[n]<<endl;
}

