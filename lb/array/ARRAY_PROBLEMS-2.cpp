Reverse an Array from certain position
==============================================================================================
void reverseArray(vector<int> &arr , int m)
{
    int start=m+1,end=arr.size()-1;
    while(start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
   
}
==============================================================================================================
  merge sorted array--LEETCODE-88
  ======================================================================
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
    
        while( i >= 0 && j >= 0 )
        {
            if( nums1[ i ] > nums2[ j ] )
                nums1[ k-- ] = nums1[ i-- ];
            else
                nums1[ k-- ] = nums2[ j-- ];
        }
    
        while( j >= 0 )
            nums1[ k-- ] = nums2[ j-- ];
    }
=========================================================================================
  LEETCODE-283-MOVE ZEROES
  ==========================================================================================
   void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i< nums.size();i++)
        {
            if(nums[i]!=0)
            {
              swap(nums[i],nums[j]);
                j++;
            }
            
            
        }
        
    }
============================================================================================
