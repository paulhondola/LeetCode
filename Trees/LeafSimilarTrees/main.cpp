#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getLeafs(vector<int> &leafs, TreeNode *root) {
  if (root == NULL) {
    return;
  }

  if (root->left == NULL && root->right == NULL) {
    leafs.push_back(root->val);
    return;
  }

  getLeafs(leafs, root->left);
  getLeafs(leafs, root->right);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
  vector<int> leafs1;
  vector<int> leafs2;
  getLeafs(leafs1, root1);
  getLeafs(leafs2, root2);

  if (leafs1.size() != leafs2.size()) {
    return false;
  }

  return leafs1 == leafs2;
}
