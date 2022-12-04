The char data type is used to store a single character. 
The character must be surrounded by single quotes, like 'A' or 'c':
-----------------------------------------------------------------------------
A char array is just that - an array of characters:
ex:- char arr[10];
int main() {
   char arr[20];
   cin>>arr;
   cout<<arr;
    return 0;
}
-------------------------------------------------------------------------------
1.If allocated on the stack (like in your example), 
it will always occupy eg. 256 bytes no matter how long the text it contains is
2.If allocated on the heap (using malloc() or new char[]) you're responsible
for releasing the memory afterwards and you will always have the overhead of a heap allocation.
3.If you copy a text of more than 256 chars into the array,
it might crash, produce ugly assertion messages or cause unexplainable (mis-)behavior somewhere else in your program.
4.To determine the text's length, the array has to be scanned, 
character by character, for a \0 character.
-----------------------------------------------------
A string is a class that contains a char array, but automatically manages it for you. 
Most string implementations have a built-in array of 16 characters 
(so short strings don't fragment the heap) and use the heap for longer strings.
=====================================================
Reverse a String
===================================================
string reverseWord(string str){
    int i=0,j=str.size()-1;
    while(i<j)
    {
        swap(str[i++],str[j--]);
        
    }
    
  //Your code here
  return str;
}
=====================================
length of the string
=============================================
int getlength(char c[20])
{
    int count=0;
    for(int i=0;c[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
============================================================================
A sentence is palindrome
=============================================================================
bool isPalindrome(string s) {
        
     if (s.empty()) return true; 
        int z = s.size();
        int i = 0;
        while (i < z) {
            if (!isalnum(s[z])) { z--; continue; }
            if (!isalnum(s[i])) { i++; continue; }   
            if (tolower(s[i++]) != tolower(s[z--])) return false;
        }
        return true;
    }
    =================================
// no  characters to be added to make it a serach word
============================================================
#include <iostream>
using namespace std;

int solution(string search, string result){
    int n = search.size();
    int m = result.size();
    int i=0, j=0;
    while(i<n and j<m){
        if(search[i]==result[j]) j++;
        i++;
    }
    return m-j;
}
int main() {
    string a ="abcz";
    string b = "azdb";
    cout<<solution(a, b)<<endl;
    //n=10^5
}
===========================================================================================================================
reverse the words in the given sentence
---------------------------------------------------------------
ex:my name is something
output:- ym eman si gnihtemos
===========================================================================================================================
Maximum Occuring Character
=============================================================================================================================
 char getMaxOccuringChar(string str)
    {
        int alpha[26]={0};
        for(int i=0; i<str.size(); i++) {
            if(str[i]>='A' && str[i]<='Z')
            {
                str[i]=str[i]-'A'+'a';
            }
            alpha[str[i]-'a']++;
        }
        
        int maxValue=-1, ans=0;
        for(int i=0; i<26; i++) {
            if(maxValue<alpha[i])
            {
                maxValue=alpha[i], ans=i;
            }
        }
        
        return ans+'a';

    }
 =======================================================================================================
cin execution stops when compiler encounters space(" ") ,tab ("\t"),newline("\n")
 ===========================================================================================================
 string replaceSpaces(string &str){
	// Write your code here.
    string temp;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }else{
            temp.push_back(str[i]);
        }
    }
    return temp;
}
 =================================================================================================================
  Remove All Occurrences of a Substring
 ===============================================================================================================
     string removeOccurrences(string s, string part) {
        while(s.size()!=0 && s.find(part) < s.length())
        {
            s.erase(s.find(part),part.length());
        }
        return s;
    }
    ============================================================================================================
    permutation in a strinr
    ---------------
    bool checkEqual(int a[26],int b[26])
    {
        for(int i=0;i<26;i++)
           { //cout<<a[i]<<" "<<b[i];
            if(a[i]!=b[i])
                return 0;}
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        // charcter array counter
        if(s2.size() < s1.size()) return false;
        int count1[26]={0};
        for(int i=0;i< s1.length();i++)
        {
            count1[s1[i]-'a']++;
        }
        // traverse s2 string in window size s1 length and compare 
        int i=0;
        int windowsize=s1.length();
        int count2[26]={0};
        // running for first window
        while(i < windowsize)
        { 
            int index=s2[i]-'a';
            
            count2[index]++;
            
            i++;
        }
        if(checkEqual(count1,count2))
        {
            return 1;
        }
        // processing window front
    
         while(i< s2.length())
         {   
             char newchar=s2[i];

             count2[newchar-'a']++;

             char oldchar=s2[i-windowsize];

             count2[oldchar-'a']--;
              if(checkEqual(count1,count2))
        {
            return 1;
        }
        i++;

         }
        return 0;
    }




