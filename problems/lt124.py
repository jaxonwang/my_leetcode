class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def path(root):
            maxpathtoroot = root.val
            maxPathleft, pathleft, maxPathright, pathright = -sys.maxsize, -sys.maxsize, -sys.maxsize, -sys.maxsize
            if root.left:
                maxPathleft, pathleft = path(root.left)
            if root.right:
                maxPathright, pathright = path(root.right)
            maxpathtoroot = max(root.val, pathright+root.val, pathleft+root.val)
            maxPath = max(maxPathleft, maxPathright, maxpathtoroot, pathright+pathleft+root.val)
            return maxPath, maxpathtoroot
        return path(root)[0]
