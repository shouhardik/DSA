int LongestIncreasingSubsequence(int a[],int n){
   int dp[n],max=INT_MIN;
   for(int i=0;i<n;i++){
      dp[i]=1;
      for(int j=0;j<i;j++){
        if(a[i]>a[j] && dp[i]<dp[j]+1)
             dp[i]=dp[j]+1;
       }
       if(max<dp[i])
          max=dp[i];
    }
    return max;
}
