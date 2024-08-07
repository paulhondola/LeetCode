# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

def preorder(root: 'Node') -> List[int]:
    def traverse(node: 'Node', result: List[int]):
        if node:
            result.append(node.val)  # Visit the root node
            for child in node.children:
                traverse(child, result)  # Recursively visit each child

    result = []
    traverse(root, result)
    return result
