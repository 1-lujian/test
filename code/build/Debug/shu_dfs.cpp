#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010*2;
int h[N],e[N],ne[N];
bool st[N];
int n,a,b,idx;
int ans=N;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dfs(int u){
    st[u]=true;
    int sum=1,res=0;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j])
         {
             int x=dfs(j);
             res=max(res,x);
             sum+=x;
         }
    }
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}