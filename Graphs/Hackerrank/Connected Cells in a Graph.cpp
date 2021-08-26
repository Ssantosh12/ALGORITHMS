#include <bits/stdc++.h>

using namespace std;

void dfs(int i,int j,int n, int m,vector<vector<int>> &arr,int &cnt){
    if(i<0||i>(n-1)||j<0||j>(m-1)||arr[i][j]!=1)
        return;
    arr[i][j]=0;
    cnt++;
    //now call dfs on its 8 neighbours
    dfs(i,j-1,n,m,arr,cnt);
    dfs(i,j+1,n,m,arr,cnt);
    dfs(i-1,j-1,n,m,arr,cnt);
    dfs(i+1,j-1,n,m,arr,cnt);
    dfs(i-1,j+1,n,m,arr,cnt);
    dfs(i+1,j+1,n,m,arr,cnt);
    dfs(i-1,j,n,m,arr,cnt);
    dfs(i+1,j,n,m,arr,cnt);
}

int main()
{
    int n,m,i,j,mx=0,cnt;  //we use given matrix as both the adjacency list and the visited array to run dfs to count no of nodes in each connected component
    scanf("%d%d",&n,&m);
    vector<vector<int>> arr(n,vector<int> (m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]==1){
                cnt=0;
                dfs(i,j,n,m,arr,cnt);
                if(cnt>mx)
                    mx=cnt;
            }
        }
    }
    printf("%d\n",mx);
}
