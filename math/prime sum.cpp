in prime numbers, 2 is one and only even number
========================================================
if the given number is odd(combination of even and odd i.e, 11+2=13)
  then subtracting 2 from other nuber checking whether it is a prime is enough
  time complexity=O(logn)
  =================================================================================================================================
  public:
bool checkprime(int n)
{
     if(n==1)
        {
           return 0;
        }
    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        {
           return 0;
        }
    }
    return 1;
}
    string isSumOfTwo(int N){
        // code here
        if(N==4)
        {
            return "Yes";
        }
        if(N%2!=0)
        {
            if(checkprime(N-2))
            {
                return "Yes";
            }
        }
        for(int i=3;i<=N/2;i+=2)
        {
           
                if(checkprime(N-i))
                {
                    return "Yes";
                }
            
        }
        return "No";
    }
