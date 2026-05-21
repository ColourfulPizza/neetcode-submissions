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

const int INF = 1e9;

struct AnsNode {
    int maxEndingToRoot = 0;
    int maxOverall = -INF;
    int maxContainingRoot = -INF;
};

AnsNode calc(TreeNode* root)
{
    if (root == nullptr)
        return {0, -INF, -INF};
    auto l = calc(root -> left);
    auto r = calc(root -> right);

    int mxWithRoot = max(l.maxEndingToRoot,0) + max(r.maxEndingToRoot,0) + root -> val;
    int maxEndingToRoot = max(r.maxEndingToRoot, 0);
    maxEndingToRoot = max(l.maxEndingToRoot, maxEndingToRoot);
    maxEndingToRoot += root -> val;

    int maxmax = max(l.maxOverall , r.maxOverall);

    maxmax = max(maxmax, mxWithRoot);

    return {maxEndingToRoot, maxmax, mxWithRoot};
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return calc(root).maxOverall;
    }
};






