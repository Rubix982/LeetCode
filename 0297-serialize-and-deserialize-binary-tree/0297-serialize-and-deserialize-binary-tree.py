# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        Optimized serialization using a more memory-efficient approach.
        Time Complexity: O(n)
        Space Complexity: O(n)
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        
        def dfs(node):
            if not node:
                return ["#"]
            return [str(node.val)] + dfs(node.left) + dfs(node.right)
        
        return ",".join(dfs(root))

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        Optimized deserialization using recursive approach.
        Time Complexity: O(n)
        Space Complexity: O(h) where h is the height of the tree
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        
        def dfs():
            if not values:
                return None
            
            val = values.pop(0)
            if val == "#":
                return None
            
            node = TreeNode(int(val))
            node.left = dfs()
            node.right = dfs()
            
            return node
        
        values = data.split(",")
        return dfs()

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))