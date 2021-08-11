#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Functions{
    public:
    vector<int> LevelOrderTraversal(TreeNode* root){
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        TreeNode* curr = NULL;
        while(q.size()){
            curr = q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return v;
    }
 
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

};
int main()
{
    Functions fn;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
 
    vector<int> v = fn.LevelOrderTraversal(root);
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
    cout<<fn.findLargestSubtreeSum(root);
 
    return 0;
}
