#include<bits/stdc++.h>
using namespace std;

class Arrays{
    public:

    // 1. https://leetcode.com/problems/two-sum 
    vector<int> twoSum(vector<int>& a, int n) {
        int i, j; map<int, int> m1; vector<int> ans;
        for(int i=0; i<a.size(); i++){
            if(m1.find(n-a[i]) != m1.end()){
                ans.push_back(i);
                ans.push_back(m1.find(n-a[i])->second);
                return ans;
            }
            else m1.insert({a[i], i});
        }
        return ans;
    }

    // 2. https://leetcode.com/problems/best-time-to-buy-and-sell-stock
    int maxProfit(vector<int>& prices) {      
        if(prices.empty()) return 0;
        int min_price = prices[0], ans = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i]<min_price) min_price = prices[i];
            else if(prices[i] - min_price > ans) ans = prices[i] - min_price;
        }
        return ans;
    }

    // 3. https://leetcode.com/problems/contains-duplicate
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m1;
        for(int i=0; i<nums.size(); i++){
            if(m1.find(nums[i])==m1.end()) m1.insert({nums[i],1});
            else return true;
        }
        return false;
    }

    // 4. https://leetcode.com/problems/product-of-array-except-self
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size(), prepd = 1, postpd = 1;
        vector<int> result(n,1);
        for(int i=0; i<n; i++){
            result[i] *= prepd;
            prepd *= nums[i];
            result[n-i-1] *= postpd;
            postpd *= nums[n-i-1];
        }
        return result;
    }

    // 5. https://leetcode.com/problems/maximum-subarray
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum>ans) ans = sum;
            if(sum<0) sum = 0;
        }
        return ans;
    }
};

int main(){
    return 0;
}