#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N=110;
int g[N][N],d[N][N];
int n,m;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int BFS(){
    queue<PII>q;
     q.push({0,0});
    memset(d,-1,sizeof(d));
    d[0][0]=0;
    while(q.size()){
       auto t=q.front();
         q.pop();
        for(int i=0;i<4;i++){
            int x=t.first+dx[i];
            int y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1)
           {
               d[x][y]=d[t.first][t.second]+1;
               q.push({x,y});
           }
        }
    }
    return d[n-1][m-1];
 }
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
       cin>>g[i][j];
      cout<<BFS()<<endl;
}
        
    