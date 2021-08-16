#include<bits/stdc++.h>
using namespace std;

class Arrays{
    public:

    // https://leetcode.com/problems/two-sum 
    vector<int> twoSum(vector<int>& a, int n) {
        int i, j;
        map<int, int> m1;
        vector<int> ans;
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

    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock
    int maxProfit(vector<int>& prices) {      
        // int ans = 0, diff;
        // for(auto i = prices.begin(), j = prices.begin()+1;j!=prices.end();){
        //     diff = *j-*i;
        //     if(ans<diff) ans = diff;
        //     if(diff<0){
        //         if(i==j+1)
        //         {i++;j++;}
        //         else i++;
        //     }
        //     else j++;
        // }
        // return ans;
        // OR //
        if(prices.empty()) return 0;
        int min_price = prices[0], ans = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i]<min_price) min_price = prices[i];
            else if(prices[i] - min_price > ans) ans = prices[i] - min_price;
        }
        return ans;
    }

    // https://leetcode.com/problems/contains-duplicate
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m1;
        for(int i=0; i<nums.size(); i++){
            if(m1.find(nums[i])==m1.end()) m1.insert({nums[i],1});
            else return true;
        }
        return false;
    }
};

int main(){
    return 0;
}