#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:

    //// 2018-08-03 ////

    // https://leetcode.com/problems/generate-parentheses/
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "(";
        int open = 1, close = 0;
        
        ways(s, open, close, n);
        return ans;
    }
    
    void ways(string s, int open, int close, int n){
        if(s.size()==2*n){
            ans.push_back(s);
            // cout<<s<<endl;
            return;
        }
        
        if(open>close && open < n){
            ways(s+")", open, close+1, n);
            ways(s+"(", open+1, close, n);
        }
        else if(open < n)
        {
            ways(s+"(", open+1, close, n);
        }
        else if(close < n) ways(s+")", open, close+1, n);
        else return;
    }

    // https://leetcode.com/problems/valid-parentheses/
    bool isValid(string s) {
        stack<char> s1;
        for(auto i:s){
            switch(i){
                case '(':
                    s1.push(i);
                    break;
                case '{':
                    s1.push(i);
                    break;
                case '[':
                    s1.push(i);
                    break;
                case ')':
                    if(!s1.empty() && s1.top()=='(') s1.pop();
                    else return false;    
                    break;  
                case '}':
                    if(!s1.empty() && s1.top()=='{') s1.pop();
                    else return false;    
                    break;
                case ']':
                    if(!s1.empty() && s1.top()=='[') s1.pop();
                    else return false;    
                    break;   
            }
        }
        return s1.empty();
    }

    //https://leetcode.com/problems/binary-watch/

    int binary_count(int n) {
       int binaryNumber[6], num=n;
       int i = 0, count = 0;
       while (n > 0) {
          binaryNumber[i] = n % 2;
          n = n / 2;
          i++;
       }
       for (int j = i - 1; j >= 0; j--){
           if(binaryNumber[j]==1) count++;
       }    
       return count;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn>8) return ans;
        
        // cout<<binary_count(turnedOn);

        map<int, int> hours_bits;
        for(int i = 0; i<12; i++){
            hours_bits.insert(pair<int, int>(i, binary_count(i)));
        }
        map<int, int> minutes_bits;
        for(int i = 0; i<60; i++){
            minutes_bits.insert(pair<int, int>(i, binary_count(i)));
        }

        for(auto i = hours_bits.begin(); i!=hours_bits.end(); i++){
            for(auto j = minutes_bits.begin(); j!=minutes_bits.end(); j++){
                if(i->second + j->second == turnedOn)
                {
                    if(len_int(j->first) <= 1) ans.push_back(to_string(i->first)+":0"+to_string(j->first));
                    else ans.push_back(to_string(i->first)+":"+to_string(j->first));
                }
            }
        }
        return ans;
    }
    int len_int(int n){
        int i = 0;
        while(n>0)
        {
            n/=10;i++;
        }   
        return i;
    }

    //https://leetcode.com/problems/letter-combinations-of-a-phone-number/

    string keypad[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans2;

    void helperfunction(string output,string digits,int i){
        if(i==digits.size()){
            ans2.push_back(output);
            return;
        }

        int num= digits[i] - '0';

        for(int j=0;j<keypad[num].size();j++){
            helperfunction(output+keypad[num][j],digits,i+1);
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return ans2;
        }
        string output;
        helperfunction(output,digits,0);
        return ans2;
    }

    // https://leetcode.com/problems/maximum-binary-tree/

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = max_vec(nums);
        TreeNode* root = new TreeNode();
        root->val = nums[n];
        if(n!=nums.size()-1){
            vector<int> right(nums.begin()+n+1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        if(n!=0){
            vector<int> left(nums.begin(), nums.begin() +  n);
            root->left = constructMaximumBinaryTree(left);
        }
        return root;
    }
    
    int max_vec(vector<int> n){
        int val = INT_MIN, index = -1;
        for(int i = 0; i<n.size(); i++){
            if(n[i]>val){
                val = n[i];
                index = i;
            }
        }
        return index;
    }

    // https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    vector<int> twoSum_sorted(vector<int>& n, int target) {
        int i = 0, j = n.size() - 1;
        vector<int> nums;
        while(i<j){
            if((n[i]+n[j])>target) j--;
            else if((n[i]+n[j])<target) i++;
            else {
                nums.push_back(i+1);
                nums.push_back(j+1);
                break;
            }
        }
        return nums;
    }

    //// 2018-08-05 ////

    // https://leetcode.com/problems/balanced-binary-tree/
    bool isBalanced(TreeNode* root) {
        bool ans = false;
        if(!root) return true;
        else if(!(root->left)) return (height(root->right))<=1 ;
        else if(!(root->right)) return (height(root->left))<=1 ;
        else if(abs(height(root->left) - height(root->right))<=1) ans = true;
        return ans and isBalanced(root->left) and isBalanced(root->right);
    }
    int height(TreeNode *root)
    {
      int h = 0;
      if(root != NULL)
      {
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        int maxHeight = max(lHeight,rHeight);
        h = maxHeight + 1;
      }
      return h;
    }

    // https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
    int minAddToMakeValid(string s) {
        // stack<char> s1;
        int avail = 0, count = 0;
        for(auto a:s){
            if(a == '(') avail++;
            else if(a == ')' and avail==0){
                count++;
            }
            else avail--;
        }
        return count + avail;
    }

    // https://leetcode.com/problems/two-sum/
    vector<int> twoSum(vector<int>& a, int n) {
        int i,j;
        vector<int>answer;
         for(i=0;i<a.size();i++)
         {
             for(j=i+1;j<a.size();j++)
             {
                 if(n-a[i]==a[j])
                 {
                     answer.push_back(i);
                     answer.push_back(j);
                 }
             }
         }
             return answer;
    }
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
	   for(int i=0; i<n; i++){
	       int* j = find(arr, arr+n, x - arr[i]);
           cout<<j<<"\n";
           cout<<*j;
	       if(&arr[i]!=j && j != arr+n) return true;
	   }
	   return false;
	}

    // https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
    bool findTarget(TreeNode* root, int k) {
        return findTarget1(root, k, root);
    }
    bool findTarget1(TreeNode* root, int k, TreeNode* actual_root) {
        
        if(!root) return false;
        int rem = k - root->val;
        if(check(actual_root, root, rem)) return true;
        else{
            return findTarget1(root->right, k, actual_root)||findTarget1(root->left, k, actual_root);
            
        }
    }
    bool check(TreeNode* root, TreeNode* current, int rem){
        if(!root) return false;
        if(root->val == rem and root!=current) return true;
        else if(root->val > rem) return check(root->left, current, rem);
        else return check(root->right, current, rem);
    }

    //// 2021-08-06 ////

    // Input: 56 => Output: 78 (Concatenation of factors whose product is input and minimum of all such possibilities (like 144, 414, 228, 282))
    int mult_pair(int a){
        int i = 1, j, min = INT_MAX, num;
        while(i<(a/2)){
            if(a%i==0){
                j = a/i;
                num = concat(i, j);
                if(num<min) min = num;
            }
            i++;
        }
        return min;
    }
    int concat(int a, int b){ // returns concat of two numbers to get a single number. Eg. 144 when input is 14, 4
        int d2 = digits(b);
        return a * pow(10, d2) + b;
    }
    int digits(int a){ // returns number of digits in a number
        int i = 0;
        while(a>0){
            a/=10;
            i++;
        }
        return i;
    }

    //// 2021-08-07 ////

    // https://practice.geeksforgeeks.org/problems/level-order-traversal/
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> q;
        vector<int> v;
        q.push(node);
        Node* curr = NULL;
        while(q.size()){
            curr = q.front();
            q.pop();
            v.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return v;
    }

    // https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        queue <pair<TreeNode*,int>> q;
        map<int,int> mp;
        if(root==NULL) return ans;
        q.push({root,0});
        q.push({NULL,0});
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            if(temp.first==NULL){
                q.pop();
                if(!q.empty()) q.push({NULL,0});
            
            }
            else{
                q.pop();
                if(mp.find(temp.second)==mp.end()) mp[temp.second]=temp.first->val;
                if(temp.first->left){ q.push({temp.first->left,temp.second-1});
                if(temp.first->right) q.push({temp.first->right,temp.second+1});
            }
        }
         for(auto x:mp) ans.push_back(x.second);
        return ans;
    }

    // https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
    int sumOfTree(TreeNode* root){
        if(!root) return 0;
        else if(!root->left and !root->right) return root->val;
        else return root->val + sumOfTree(root->left) + sumOfTree(root->right);
        return 0;
    }

    int findLargestSubtreeSum(TreeNode* root){
        static int ans = INT_MIN;
        if(!root) return 0;
        ans = max(sumOfTree(root), max(findLargestSubtreeSum(root->left), findLargestSubtreeSum(root->right)));
        return ans;
    }

    // https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/
    void toSumTree(Node *root)
    {
        if(!root) return;
        if(!root->left and !root->right) root->data = 0;
        else root->data = sumOfTree(root->left) + sumOfTree(root->right);
        toSumTree(root->left);
        toSumTree(root->right);
        return;
    }
    int sumOfTree(Node* root){
        if(!root) return 0;
        else if(!root->left and !root->right) return root->data;
        else return root->data + sumOfTree(root->left) + sumOfTree(root->right);
        return 0;
    }

    // https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/
    int height(Node *root)
    {
    int h = 0;
    if(root != NULL)
    {
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        int maxHeight = max(lHeight,rHeight);
        h = maxHeight + 1;
    }
    return h;
    }
    bool isBalanced(Node *root)
    {
        bool ans = false;
        if(!root) return true;
        else if(!(root->left)) return (height(root->right))<=1 ;
        else if(!(root->right)) return (height(root->left))<=1 ;
        else if(abs(height(root->left) - height(root->right))<=1) ans = true;
        return ans and isBalanced(root->left) and isBalanced(root->right);
        
    }

    // https://leetcode.com/problems/climbing-stairs
    // https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int a[n];
        a[0] = 1;
        a[1] = 2;
        for(int i = 2; i<n; i++){
            a[i] = (a[i-1] + a[i-2])%1000000007;
        }
        return a[n-1];
    }

    //// 2021-08-15 ////

    
};

int main(){
    Solution s;
    // vector<string> ans = s.generateParenthesis(3);
    // for(auto i = ans.begin();i!=ans.end();i++){
    //     cout<<*i<<endl;
    // }
    // cout<<endl;
    // vector<string> s1 = s.readBinaryWatch(1);
    // for(auto i = s1.begin(); i != s1.end(); i++) cout<<*i<<" ";
    // cout<<endl;
    // vector<string> s2 = s.letterCombinations("23");
    // for(auto i = s2.begin(); i != s2.end(); i++) cout<<*i<<" ";
    // cout<<endl;

    return 0;
}