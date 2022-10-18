class treeNode:
  def __Init__(self,val = None):
    self.val = val
    self.left = None
    self.right = None
    
root = treeNode(1)
root.left = treeNode(2)
root.right = treeNode(3)
root.left.left = treeNode(4)
root.left.right = treeNode(5)
