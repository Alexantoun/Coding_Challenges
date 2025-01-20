/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
#include <tuple>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(NULL == root)
            return 0;

        queue<tuple<TreeNode*, int> > q;
        q.push(tuple<TreeNode*, int>(root, 1));
        
        tuple<TreeNode*, int> node;
        TreeNode* child; 

        while(!q.empty())
        {
            node = q.front();
            child = get<0>(node);

            if(child->left == NULL && child->right == NULL)
            {
                return get<1>(node);
            }
            if(child->left != NULL)
            {
                q.push(tuple<TreeNode*, int>(child->left, get<1>(node) + 1));
            }
            if(child->right != NULL)
            {
                q.push(tuple<TreeNode*, int>(child->right, get<1>(node) + 1));
            }

            q.pop();
        }
        return 0;
    }
};