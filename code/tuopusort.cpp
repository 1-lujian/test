#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=100010*2;
int e[N],ne[N],h[N],idx;
int d[N];
int count;
queue<int>q;
queue<int>p;
int n,m;
void add(int a,int  b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void bfs(){
    for(int i=1;i<=n;i++){
        if(d[i]==0)
         q.push(i);
    }
        while(q.size()){
            int u=q.front();
             q.pop();
             count++;
             p.push(u);
             for(int i=h[u];i!=-1;i=ne[i]){
                int b=e[i];
                d[b]--;
                if(d[b]==0)
                    q.push(b);
            }
        }
    }
int main(){
    cin>>n>>m;
    memset(h, -1, sizeof h);
    for(int i=0;i<m;i++)
     {   int a,b;
         cin>>a>>b;
         add(a,b);
         d[b]++;
     }
       bfs();
      if(count!=n)
        cout<<"-1"<<endl;
        else{
            while(p.size())
            {
                cout<<p.front()<<" " ;
                p.pop();
            }
        } 
     return 0;
}
