# Binary Search Tree Analysis

## Core operations

Students should analyze the following BST operations:

1. insertion
insertin finds the correct empty position based on the BST ordering rules: smaller value go to the left, and larger values go to teh right. It's balanced BST has O(log n) as its aerage time and O(n) as it's worst case time.

2. Search
Search compares the target value with the current node and follows the left or right child until the value is found or an empty position is reached. It's balanced BST is O(log n) as average time and O(n) in it's worst case time.

3. Deletion
Deletion searches for the value and handles three cases: a node with no children, a node with one child, or a node with two children. For two children, this implementation replaces the node's value with its inorder successor. It's balanced BST is O(log n) as average time and O(n) in it's worst case time.

4. Traversal
inorder, preorder, and postorder traversal visit every node in the tree.Each node is processed once, regardless of the tree's shape.

Inorder traversal: O(n).
Preorder traversal: O(n).
Postorder traversal: O(n).

5. Minimum and Maximum Lookup
The minimum value is found by following left-child pointers, while the maximum value is found by following right-child pointers. It's balanced BST is O(log n) in average time and O(n) in it's worst case time.

6. Subtree Height
The height function recursively calculates the heights of the left and right subtrees and returns one plus the larger height. In this implementation, an empty tree has height 0. It's time complexity is O(n) because every node is visited and it's auxiliary recursion space is O(h), where h is the tree height.

## Required discussion

- Best-case vs. Worst-case behavior
The performance of BST operations depends on the tree's height. When the tree is balanced, its height is approximately logarithmic in the number of nodes, making insertion, search, and deletion efficient. In a skewed tree, the height can grow linearly with the number of nodes, making these operations slower.

- Average-Case Behavior for a Balanced BST
For a reasonably balanced BST, insertion, search, deletion, and minimum/maximum lookup take O(log n) time. This is because each comparison moves the operation closer to the correct position through the tree's levels.

- Worst-Case Behavior for a Skewed Tree
A skewed BST can resemble a linked list. For example, inserting values in sorted order can create a chain-like structure. In this case, insertion, search, and deletion can take O(n) time.

- Recursive vs. Iterative Implementations
Recursive implementations use helper functions that call themselves to process smaller subtrees. They often make tree algorithms easier to understand, but use additional call-stack space proportional to the tree height. But, Iterative implementations use loops instead of recursive calls. They can avoid recursion-stack usage for operations such as search and minimum/maximum lookup. However, the time complexity still depends on the tree's height.

- How Tree Height Affects Search Cost
Search follows one path from the root toward a possible matching node. Its time complexity is O(h), where h is the height of the tree. A shorter tree generally requires fewer comparisons, while a taller tree may require visiting many more nodes.

## Expected Big-O summary

- `insert`
   Balanced BST: O(log n) 
   Worst-case BST: O(n)
- `search`
   Balanced BST: O(log n) 
   Worst-case BST: O(n)
- `remove`
   Balanced BST: O(log n) 
   Worst-case BST: O(n)
- `inorderTraversal`
   Balanced BST: O(n) 
   Worst-case BST: O(n)
- `height`
   Balanced BST: O(n) 
   Worst-case BST: O(n)

The height calculation takes O(n) time in both cases becasue it visits every node.

A BST is efficient when its height remains small relative to its number of nodes. Balanced trees generally support insertion, search, and deletion in O(log n) time, while skewed trees can require O(n) time. For a balanced binary search tree, expected operations are near O(log n), while a degenerate tree can degrade to O(n). Traversal and height calculations take O(n) time because they examine all nodes. Therefore, tree shapes are an important factor in BST operations. 
