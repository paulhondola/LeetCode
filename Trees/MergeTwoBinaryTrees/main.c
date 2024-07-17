typedef struct TreeNode *tree;

void merge(tree main, tree sum) {
  if (main == NULL && sum == NULL)
    return;

  if (main == NULL) {
    main = sum;
    return;
  }

  if (sum == NULL)
    return;

  main->val += sum->val;

  merge(main->left, sum->left);
  merge(main->right, sum->right);
}

tree mergeTrees(tree root1, tree root2) {
  merge(root1, root2);
  return root1;
}
