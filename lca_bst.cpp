// Recursive
// Time Complexity : O(n) 
// Space Complexity : O(h); h is height of tree 
// Did this code succesfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// 1. If values of p and q are less than root, recurse for left subtree
// 2. If values of p and q are greater than root, recurse for right subtree
// 2. Else return value at root (case when both are on opposite side or root is same as p or q)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base
        if(root==nullptr)
            return root;
        // logic
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

// Iterative
// Time Complexity : O(n) 
// Space Complexity : O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=nullptr){
            if(p->val < root->val && q->val < root->val)
                root=root->left;
            else if(p->val > root->val && q->val > root->val)
                root=root->right;
            else
                return root;
        }
        return nullptr;
    }
};