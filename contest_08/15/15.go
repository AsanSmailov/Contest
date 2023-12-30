type BinaryTreeNode struct {
 Value       int
 Left, Right *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
 return &BinaryTreeNode{
  Value: value,
  Left:  nil,
  Right: nil,
 }
}

func (t *BinaryTreeNode) insertNode(value int) {
 if value < t.Value {
  if t.Left != nil {
   t.Left.insertNode(value)
  } else {
   t.Left = NewBinaryTreeNode(value)
  }
 } else if value > t.Value {
  if t.Right != nil {
   t.Right.insertNode(value)
  } else {
   t.Right = NewBinaryTreeNode(value)
  }
 }
}

func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
 if t == nil {
  return nil
 }

 if value < t.Value {
  t.Left = t.Left.removeNode(value)
 } else if value > t.Value {
  t.Right = t.Right.removeNode(value)
 } else {
  if t.Left == nil && t.Right == nil {
   t = nil
  } else if t.Left == nil {
   t = t.Right
  } else if t.Right == nil {
   t = t.Left
  } else {
   max := t.Left.findMax()
   t.Value = max.Value
   t.Left = t.Left.removeNode(max.Value)
  }
 }

 return t
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
 if t == nil || t.Value == value {
  return t
 }

 if value < t.Value {
  return t.Left.findNode(value)
 } else {
  return t.Right.findNode(value)
 }
}

func (t *BinaryTreeNode) findMax() *BinaryTreeNode {
 if t == nil {
  return nil
 }

 for t.Right != nil {
  t = t.Right
 }

 return t
}

func (t *BinaryTreeNode) String() string {
 if t == nil {
  return ""
 }

 queue := []*BinaryTreeNode{t}
 result := ""

 for len(queue) > 0 {
  node := queue[0]
  queue = queue[1:]
  result += fmt.Sprintf("%d ", node.Value)

  if node.Left != nil {
   queue = append(queue, node.Left)
  }

  if node.Right != nil {
   queue = append(queue, node.Right)
  }
 }

 return result
}