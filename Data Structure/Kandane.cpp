class Solution{
  public:
  int max_so_far=INT_MIN;
        int max_end=0;
        for(int i=0;i<n;i++){
            max_end+=arr[i];
            if(max_so_far<max_end){
                max_so_far=max_end;
            }
            if(max_end<0) max_end=0;
        }
        return max_so_far;
  
};

