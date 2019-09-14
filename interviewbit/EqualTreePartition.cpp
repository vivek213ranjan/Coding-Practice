// Given a binary tree with N nodes.
// Check whether it is possible to partition the tree to two trees which
// have equal sum of values after removing exactly one edge on the original tree.
//
// Return 1 if the tree can be partitioned into two trees of equal sum else return 0.
//
// Constraints
// 2 <= N <= 100000
// -10^9 <= Node values <= 10^9
//
// Created by Vivek Ranjan on 14/09/19.
//

bool ans;
TreeNode* node;

int subTreeWithSumExist(TreeNode* root, int val) {
    if(!root) {
        return 0;
    }
    if (ans) {
        return 0;
    }
    int left = subTreeWithSumExist(root->left, val);
    int right = subTreeWithSumExist(root->right, val);
    int sum = left + right + root->val;
    if(sum == val) {
        node = root;
        ans = true;
    }
    return sum;
}

int getSum(TreeNode* root) {
    if(!root) { return 0; }
    return root->val + getSum(root->left) + getSum(root->right);
}

int Solution::solve(TreeNode* root){
    if(!root) return 0;
    ans = false;
    node = NULL;
    int rootSum = getSum(root);
    if(abs(rootSum)&1)
        return 0;
    subTreeWithSumExist(root, rootSum/2);
    if(ans && node!=root)
        return 1;
    return 0;
}

