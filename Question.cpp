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