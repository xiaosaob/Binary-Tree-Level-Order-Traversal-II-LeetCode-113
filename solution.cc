// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> myQue;
        myQue.push(root);
        int lvl1 = 1, lvl2 = 0;
        while(!myQue.empty()) {
            vector<int> curRow;
            while(lvl1) {
                TreeNode *curNode = myQue.front();
                myQue.pop();
                --lvl1;
                curRow.push_back(curNode->val);
                if(curNode->left) {
                    myQue.push(curNode->left);
                    ++lvl2;
                }
                if(curNode->right) {
                    myQue.push(curNode->right);
                    ++lvl2;
                }
            }
            res.push_back(curRow);
            lvl1 = lvl2;
            lvl2 = 0;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
