 next_permutation(arr.begin(),arr.end());
=============================================================================
  without taking any extra space it dynamically changes the array to the next permutation
  =======================================================================================================================================================
  in next permuatation, if we are writing all the letters combination lexiographically ,just find the given number and return the next one to it.
  ====================================================================================================================================================================================
    
    the algorithm to find the next permutation
    -----------------------------------------------------------------
 1.  Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously traversed digit. For example, if the input number is "534976", we stop at 4 because 4 is smaller than next digit 9. If we do not find such a digit, then output is "Not Possible".
2. Now search the right side of above found digit 'd' for the smallest digit greater than 'd'. For "534976", the right side of 4 contains "976". The smallest digit greater than 4 is 6.
Swap the above found two digits, we get 536974 in above example.
Now revrse all digits from position next to 'd' to the end of number. The number that we get after sorting is the output. For above example, we sort digits in bold 536974. We get "536479" which is the next greater number for input 534976.
  =================================================================================================================================================================
  int ans = INT_MIN;
        for(int i = N- 2; i >= 0; i--){
            if(arr[i] < arr[i + 1]){
                ans = i;
                break;
            }
        }
        if(ans == INT_MIN){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        int k = arr[ans + 1];
        for(int i = N - 1; i > ans; i--){
            if(arr[i] > arr[ans]){
                k = i;
                break;
            }
        }
        swap(arr[k], arr[ans]);
        reverse(arr.begin() + ans + 1, arr.end());
        return arr;
      
