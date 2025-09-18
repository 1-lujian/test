#include <iostream>
#include<algorithm>
using namespace std;
const int N=210;
int d[N][N];
int n,m,q,x,y,z,k;
void flold(){
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(i==j) d[i][j]=0;
      else d[i][j]=0x3f3f3f3f;
      
    while(m--){
        cin>>x>>y>>z;
        d[x][y]=min(d[x][y],z);
    }
    flold();
    while(q--){
        cin>>x>>y;
        if(d[x][y]>0x3f3f3f3f/2) cout<<"impossible"<<endl;
        else cout<<d[x][y]<<endl;
    }
    return 0;
}