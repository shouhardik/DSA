int LongestCommonSubsequence(char *str1,char *str2){
   int m=strlen(str1),n=strlen(str2);
   int dp[m+1][n+1];
   for(int i=0;i<=m;i++){
      for(int j=0;j<=n;j++){
        if(i==0 || j==0)  dp[i][j]=0;
        else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
 }
