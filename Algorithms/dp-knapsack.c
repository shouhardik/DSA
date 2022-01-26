struct object{
  int wt;
  int cost;
};
int main()
{
   int n,k;
   scanf("%d %d",&n,&k);
   struct object item[n];
   int dp[n+1][k+1];
   for(int i=0;i<n;i++)
      scanf("%d %d",&item[i].cost,&item[i].wt);
   for(int i=0;i<=n;i++)
       dp[i][0]=0;
   for(int i=0;i<=k;i++)
       dp[0][i]=0;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=k;j++){
           dp[i][j]=max(dp[i-1][j],item[i-1].cost+dp[i-1][j-item[i-1].wt]);
       }
   }
   printf("%d ",dp[n][k]);
   return 0;
}

// instead of struct

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int a,int b){
    return a>b?a:b;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        int wt[n],p[n];
        for(int i=0;i<n;i++){
            scanf("%d%d",&wt[i],&p[i]);
        }
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(wt[i-1]<=j){
                    dp[i][j]=max(p[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        } printf("%d\n",dp[n][k]);
    }
   
    return 0;
}

