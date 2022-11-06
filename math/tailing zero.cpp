trailing zero always present at right most end
ex: 12000--yes answer-3
    12010--not all zeros are trailing answer-1
  t.c-O(logn)
  ===============================================================================
  int trailingZeroes(int N)
    {
        
        int sum=0;
        for(int i=5;(N/i)>0;i*=5)
        {
            sum+=(N/i);
        }
        return sum;
    }
