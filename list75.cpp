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

    // 6. https://leetcode.com/problems/maximum-product-subarray/
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int max_tot = nums[0], max_curr = nums[0], min_curr = nums[0];
        for(int i=1;i<n;i++){
            int temp = max_curr;
            max_curr = max({nums[i], max_curr*nums[i], min_curr*nums[i]});
            min_curr = min({nums[i], temp*nums[i], min_curr*nums[i]});
            max_tot = max(max_curr, max_tot);
        }
        return max_tot;
    }

    // 7. https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.empty()) return 0;
        return nums[0];
    }
    // OR //
    int bsearch(vector<int> nums, int left, int right)
    {
         if(left < right)
         {
             if(nums[left] < nums[right])             
                 return nums[left];
             int mid = left + (right - left)/2;
             if(nums[mid] > nums[right])
                 return bsearch(nums, mid + 1, right); 
             else 
                 return bsearch(nums, left, mid); 
         }
        return nums[left];
    }
    int findMin(vector<int> nums) 
    {
        int n = nums.size();
        return bsearch(nums, 0, n - 1);
    }

    // 8. https://leetcode.com/problems/search-in-rotated-sorted-array/
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if(it==nums.end()) return -1;
        else return it - nums.begin();
    }

    // 9. https://leetcode.com/problems/3sum/
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if(nums.size()<3) return answer;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, k = nums.size()-1;
        for(i=0;i<nums.size();i++){
            j=i+1;
            k = nums.size()-1;
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            while(j<k){
                if (k < nums.size() - 1 and nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                if(nums[i]+nums[j]+nums[k] == 0){
                    vector<int> ans = {nums[i],nums[j],nums[k]};
                    answer.push_back(ans);
                    j++; k--;
                }               
                else if((nums[i]+nums[j]+nums[k] < 0)) j++;
                else k--;
            }   
        }
        return answer;
    }

    // 10. https://leetcode.com/problems/container-with-most-water/
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, max_area = INT_MIN;
        while(i<j){
            max_area = max((j-i) * min(height[i], height[j]), max_area);
            if(height[i]<=height[j]) i++;
            else j--;
        }
        return max_area;
    }
};

class DynamicProgramming{
    public:

    // 1. https://leetcode.com/problems/climbing-stairs/
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int a[n];
        a[0] = 1;
        a[1] = 2;
        for(int i = 2; i<n; i++){
            a[i] = a[i-1] + a[i-2];
        }
        return a[n-1];
    }

    // 7. https://leetcode.com/problems/house-robber/
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int dp[nums.size()+1];
        dp[0]=0;dp[1]=nums[0];dp[2] = max(nums[0],nums[1]);
        int i = 3;
        while(i<nums.size()+1){
            dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
            cout<<dp[i]<<"\n";
            i++;
        }
        return dp[nums.size()];  
    }

    // 9. https://leetcode.com/problems/decode-ways/
    int numDecodings(string s) {
        int n = s.size(), arr[n+1];
        arr[0] = 1;
        arr[1] = (s[0]=='0')? 0:1;
        for(int i = 2; i<=n; i++) arr[i]=0;
        for(int i = 2; i<=n; i++){
            int n_curr = int(s[i-1]) - '0', n_prev = int(s[i-2]) - '0', n_comb = n_prev * 10 + n_curr;
            if(n_curr >= 1) arr[i]+=arr[i-1];
            if(n_comb >=10 and n_comb <=26) arr[i]+=arr[i-2];
        }
        return arr[n];
    }

    // 10. https://leetcode.com/problems/unique-paths/
    int uniquePaths(int m, int n) {
        if(m==1 or n==1) return 1;
        int arr[m][n];
        for(int i=0; i<m; i++) arr[i][0] = 1;
        for(int i=0; i<n; i++) arr[0][i] = 1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        return arr[m-1][n-1];
    }
};

int main(){
    return 0;
}