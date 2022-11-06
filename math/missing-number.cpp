o(n)*logn
================================================================
  int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        sort(array.begin(),array.end());
        for(int i=0;i<n;i++)
        {
            if(array[i]!=i+1)
            {
               return i+1; 
            }
        }
        
    }
    =====================================================================
     int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
       long long total=(n*(n+1))/2;
       long long sum=0;
       for(int i=0;i<n-1;i++)
       {
           sum+=array[i];
       }
     return total-sum;
        
    }
