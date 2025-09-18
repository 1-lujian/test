#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200010;
int n,m;
int p[N];
struct Edge {
    int u,v,w;
    bool operator<(const Edge &W)const{
        return w<W.w;
    }
}edge[N];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
int kruskal(){
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=edge[i].u,b=edge[i].v,c=edge[i].w;
        if(find(a)!=find(b)){
            p[find(a)]=find(b);
            cnt++;
            res+=c;
        }
    }
    if(cnt==n-1) return res;
    else return 0x3f3f3f3f;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        p[i]=i;
    }
     for(int i=0;i<m;i++){
         int u,v,w;
         cin>>u>>v>>w;
         edge[i]={u,v,w};         
     }
     sort(edge,edge+m);
     int t=kruskal();
     if(t==0x3f3f3f3f) cout<<"impossible"<<endl;
     else cout<<t<<endl;
     return 0;
}
