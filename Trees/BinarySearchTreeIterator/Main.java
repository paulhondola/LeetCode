/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.ArrayList;

class BSTIterator extends TreeNode {

	private TreeNode root;

	private ArrayList<Integer> list;
	private Integer index;

	private void InitList(TreeNode root) {
		if (root == null) {
			return;
		}
		InitList(root.left);
		list.add(root.val);
		InitList(root.right);
	}

	public void PrintList() {
		for (var i : list) System.out.println(i);
	}

	public BSTIterator(TreeNode root) {
		list = new ArrayList<Integer>();
		index = 0;

		this.root = root;
		InitList(this.root);
	}

	public int next() {
		return list.get(index++);
	}

	public boolean hasNext() {
		return index < list.size();
	}
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */

class Main {

	public static void main(String args[]) {
		// [[[7, 3, 15, null, null, 9, 20]]

		TreeNode root = new TreeNode(7);
		root.left = new TreeNode(3);
		root.right = new TreeNode(15);
		root.right.left = new TreeNode(9);
		root.right.right = new TreeNode(20);

		BSTIterator obj = new BSTIterator(root);
		obj.PrintList();
	}
}
