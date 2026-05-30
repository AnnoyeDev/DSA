#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]) ans.push_back(arr[i]);
        else ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    return ans;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int>left(n);
        left[0]=1;
        int sum =0;

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) left[i] = left[i-1]+1;
            else left[i]=1;
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) left[i] = max(left[i],left[i+1]+1);
        }

        for(int i=0;i<n;i++){
            sum =sum +(left[i]);
        }
        return sum;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int maxlen =0;        

        // for(int i =0;i<n;i++){
        //     vector<int>hash(256,0);// the hash would be declared inside the i loop and not global because then it would store values of all the substrings 
        //     for(int j =i;j<n;j++){
        //         hash[s[j]]++;
        //         if (hash[s[j]]>1) break;
        //         int len = j-i+1;
        //         maxlen = max (maxlen , len);                               
        //     }
        // }
        // return maxlen;


        /// vector - check if element exist , move left and right pointers
        int left=0;
        int right=0;
        vector<int>hash(256,-1);

        while(right<n){
            char ch = s[right];
            if(hash[ch] != -1 // if that char already exists? 
               && hash[ch] >= left // AND it lies inside current window
               ) {
                left = hash[ch] + 1;
            }
            hash[ch] = right;
            maxlen = max(maxlen, right - left + 1);        
            right++;
        }
        return maxlen;               

        
    }
};
class Solution {
public:
    int minElement(vector<int>& nums) {
        int  mini=INT_MAX;
        int n =nums.size();

        for(int i=0;i<n;i++){
            int a=0;
            while(nums[i]>0){
                a+=nums[i]%10;
                nums[i]=nums[i]/10;                
            }
            mini=min (mini,a);
        }
        return mini;
        
    }

};
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        map<char,int>mpp;
        
        int left=0;
        int right =0;
        int n = s.size();
        int maxlen=-1;
        
        while(right<n){
            mpp[s[right]]++;
            
            if(mpp.size()>k){
                mpp[s[left]]--;
                
                if(mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                
                left++;
                
            }
            if(mpp.size()==k){
                maxlen=max(maxlen,right-left+1);
            }
            
            right++;
        }
        return maxlen;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left=0;
        int right=0;
        int cnt=0;
        vector<int>lastseen(3,-1);

        for(int i =0;i<n;i++){
            char ch = s[i];
            lastseen[s[i]-'a']=i;

            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt+=(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
        }
        return cnt;        
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left =0;
        int right =0;
        int maxlen=0;
        
        // for(int i=0;i<n;i++){
        //     vector<int>hash(26,0);
        //     int maxf=0;
        //     int changes =0;
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'A']++;
        //         maxf = max(maxf, hash[s[j]-'A']);
        //         changes = (j-i+1) - maxf;
        //         if (changes <=k){
        //             maxlen = max(maxlen,j-i+1);
        //         }
        //         else break;
        //     }
        // }
        // return maxlen;  
        vector<int>hash(26,0);
        int maxf=0;
        int changes =0;
        while(right<n){
            hash[s[right]-'A']++;
            maxf = max(maxf, hash[s[right]-'A']);
            changes = (right-left+1) - maxf;
            if (changes <=k){
                maxlen = max(maxlen,right-left+1);
            }
            else {
                hash[s[left]-'A']--;
                left++;
            }            
            right++;
        }
        return maxlen;      
    }
};
class Solution {
    public:
    int subarraySum(vector<int>& nums, int k) {
    map<int,int>mpp;
    int n =nums.size();
    int presum=0;
    int rem =0;
    int cnt=0;
    
    mpp[0]=1;
    for(int i =0;i<n;i++){
        presum+=nums[i];
        
        rem = presum -k;
        if (mpp.find(rem) != mpp.end()) cnt+=mpp[rem];
        mpp[presum]++;

    }
    return cnt;
    }            
};