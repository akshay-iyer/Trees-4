// Time Complexity : O(n) 
// Space Complexity : O(h); h is height of tree 
// Did this code succesfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// 1. Perform inorder traversal and keep decrementing k
// 2. When k reaches 0, return value of root 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal
        int result=-1;
        inorder_recur(root,k, result);
        return result;
        // return inorder_iter(root, k);
    }
    
    // iterative inorder
    int inorder_iter(TreeNode* root, int k){
        stack<TreeNode*> st;
        while(root!=nullptr || !st.empty()){
            while(root!=nullptr){
                st.push(root);
                root=root->left;
            }
            root = st.top(); st.pop();
            k--;
            if(k==0) return root->val;
            root=root->right;
        }
        return -1;
    }
    
    // recursive inorder
    void inorder_recur(TreeNode* root, int& k, int& result){
        // base
        if(root==nullptr)
            return;
        // logic
        inorder_recur(root->left, k, result);
        k--;
        if(k==0)
            result = root->val;
        inorder_recur(root->right,k, result);
    }
};