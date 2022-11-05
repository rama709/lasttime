a prime number is only divisible by one and it self;
brute force---o(n);
============================================
int isPrime(int N){
        // code here
        if(N==1)
        {
           return 0;
        }
    for(int i=2;i<=N;i++)
    {
        if(N%i == 0)
        {
           return 0;
        }
    }
    return 1;
           
    }
    
optimized solution---sqrt(n)
===============================
int isPrime(int N){
        // code here
        if(N==1)
        {
           return 0;
        }
    for(int i=2;i*i<=N;i++)
    {
        if(N%i == 0)
        {
           return 0;
        }
    }
    return 1;
           
    }
