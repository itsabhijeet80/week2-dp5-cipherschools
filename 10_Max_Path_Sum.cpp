#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPath(TreeNode* node, int &maxi) {
    if(node == NULL) return 0;

    int leftSum = max(0, maxPath(node -> left, maxi));
    int rightSum = max(0, maxPath(node -> right, maxi));

    maxi = max(maxi, leftSum + rightSum + node->val);

    return node->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPath(root, maxi);
    return maxi;
}