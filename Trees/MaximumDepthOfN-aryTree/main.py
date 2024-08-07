class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
	def maxDepth(self, root: 'Node') -> int:
		if not root:
			return 0

		if not root.children:
			return 1

		max_child_depth = max(self.maxDepth(child) for child in root.children)
		return max_child_depth + 1
