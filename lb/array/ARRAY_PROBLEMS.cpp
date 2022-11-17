1.//////////////////////////////////////////////////////////////////////////////////
  --------------------------------------------------------------------------------------------------
  int swapalt(int array[] ,int size())
{
  for(int i=0;i<size;i+=2)
  {
    if(i+1<size)//edge case
    {
      swap(array[i],array[i+1]);
    }
  }
}
 =========================================================================================================
   2.FIND UNIQUE
   ===========================
  ---- using xor
   xor same elements gives 0 so the unique element will be stored.
   ----------------------------------------------------------------
   3. find the number of unique no of  ocuurences(LEETCODE- 1207)
   ==============================================================================================================
     bool uniqueOccurrences(vector<int>& arr) {
        // Store the frequency of elements in the unordered map.
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Store the frequency count of elements in the unordered set.
        unordered_set<int> freqSet;
        for (auto [key, value] : freq) {
            freqSet.insert(value);
        }
        
        // If the set size is equal to the map size, 
        // It implies frequency counts are unique.
        return freqSet.size() == freq.size();
    }
};
==================================================================================================================================
  4.find duplicates-------------
  ================================================================================================================================
  1. use hashmap and index-value.
  ----------------------------------------------
  2.
  ---first find the xor of given array
  2.then using xor value and again perform xor operation from(1,n-1)
  ===================================================================================
  442. Find All Duplicates in an Array
  =================================================================================================
   vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> freq;
        for(int k:nums)
        {
            freq[k]++;
        }
        for(auto [key, value]:freq)
        {
            if(value>1)
            {
                   result.push_back(key);
            }
        }
        return result;
    }
    ============================================================================================================================================
    INTERSECTION OF TWO ARRAYS
    ===============================================================================================================================================
    vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( arr1[i]==arr2[j])
            {
                ans.push_back(arr1[i]); 
                arr2[j]=INT_MIN;// important=============
              1 2 2 2 3 4
              2 2 3 3
                output
                =============================
                2 2 3
                =============================================
                break;
            }   
        }
    }
        return ans;
    
}
--------------------------------------------------------------------------------------------------
  2-pointer approach
  -------------------------------------------------
  #include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    int i=0,j=0;
    vector<int> result;
    while(i<n && j<m)
    {
        if(arr1[i]==arr2[j])
        {
            result.push_back(arr1[i]);
            i++;
            j++;
        }else if(arr1[i]>arr2[j])
        {
            j++;
        }else
        {
            i++;
        }
    }
    return result;
}
--------------------------------------------------------------------------------------------------------
  PAIR SUM 
===========================================================================================================
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>>  result;
    for(int i=0;i< arr.size();i++)
    {
        for(int j=i+1;j< arr.size();j++)
        {
            if(arr[i]+arr[j]==s)
            {
                vector<int> res;
                res.push_back(min(arr[i],arr[j]));
                res.push_back(max(arr[i],arr[j]));
                result.push_back(res);
            }
        }
    }
    sort(result.begin(),result.end());
    return result;
}
=======================================================================================================
3 sum
===========================================================================================================================
Two Pointer Approach:
The basic thinking logic for this is: Fix any one number in sorted array and find the other two numbers after it. The other two numbers can be easily found using two pointers (as array is sorted) and two numbers should have sum = -1*(fixed number).

Traverse the array and fix a number at every iteration.
If number fixed is +ve, break there because we can't make it zero by searching after it.
If number is getting repeated, ignore the lower loop and continue. This is for unique triplets. We want the last instance of the fixed number, if it is repeated.
Make two pointers high and low, and initialize sum as 0.
Search between two pointers, just similiar to binary search. Sum = num[i] + num[low] + num[high].
If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
If sum is 0, that means we have found the required triplet, push it in answer vector.
Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively. Update the low and high with last occurences of low and high.
My Two Pointer Submission:

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());    //Sorted Array
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int low = i + 1 , high = nums.size() - 1;   //Make two pointers high and low, and initialize sum as 0.
            int sum = 0;
            while(low < high){                          //Search between two pointers, just similiar to binary search.
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0){   //If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
                    high--;
                } else if(sum < 0){ //If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
                    low++;
                } else {
                    answer.push_back({nums[i] , nums[low] , nums[high]});  //we have found the required triplet, push it in answer vector
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(low < high && nums[low] == last_low_occurence){   // Update the low and high with last occurences of low and high.
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return answer;      //Return the answer vector.
    }
};
==================================================================================================================================
  sort (0,1)
  ================================================================================================================================
  void segregate0and1(int arr[], int size)
{
    /* Initialize left and right indexes */
    int left = 0, right = size-1;
 
    while (left < right)
    {
        /* Increment left index while we see 0 at left */
        while (arr[left] == 0 && left < right)
            left++;
 
        /* Decrement right index while we see 1 at right */
        while (arr[right] == 1 && left < right)
            right--;
 
        /* If left is smaller than right then there is a 1 at left
        and a 0 at right. Exchange arr[left] and arr[right]*/
        if (left < right)
        {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}
============================================================================================================================
  sort (0,1,2)
  ========================================================================
  void sortColors(vector<int>& a) {
        int left=0,right=a.size()-1,current=0;
        while(current<=right)
        {
            if(a[current]==0)
            {
                int temp=a[left];
                a[left]=a[current];
                a[current]=temp;
                left++;
                current++;
               
            }else if(a[current]==2)
            {
                 int temp=a[right];
                a[right]=a[current];
                a[current]=temp;
                right--;
               
            }else
            {
                current++;
            }
        }
     
        
    }
======================================================================
  end
 ==================================================================================

  
