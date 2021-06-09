/**
 * @file threadedBST.h
 * @brief header file for ThreadedBST class
 * @author Tristan Cortez and Braden Wolf
 */
#ifndef THREADEDBST_H
#define THREADEDBST_H

#include "treeNode.h"
#include <iostream>
#include <queue>

/**
 * ThreadedBST is a threaaded binary search tree that holds treeNodes
 *
 * variable *rootPtr points to root node of the tree
 */
template <class ItemType> class ThreadedBST {
  /**
   * prints tree from lowest node item to highest node item
   *
   * uses an in-order traversal by using the threads to print out the items
   * of the nodes in the tree from lowest value to highest value.
   *
   * @pre must have at least one node in tree
   * @post does not change tree
   * @param output is filled with items from the nodes from lowest to highest
   *        with a space seperating the values
   * @param theTree is the tree that is being traversed and holds the nodes
   *        the hold the items that are being put into output
   * @return output
   */
  template <class Item>
  friend std::ostream &operator<<(std::ostream &output,
                                  const ThreadedBST<Item> &theTree);

private:
  TreeNode<ItemType> *rootPtr;
  /**
   * returns a pointer to the left most node from the node passed in
   *
   * This function is used by remove, insert operator, and removeRoot. Uses
   * loop to change which node currNode is pointing to until the left child is
   * nullptr.
   *
   * @pre must have a pointer to a node that can be passed in as currNode
   * @post const
   * @param currNode is used as the start node of what you want to get the left
   *        most of. currNode points to a different node as it is moved down
   *        the tree.
   * @return currNode which ends on the left most node of the node that was
   *         passed in
   */
  TreeNode<ItemType> *getLeftMost(TreeNode<ItemType> *currNode) const;
  /**
   * removes the root of the tree
   *
   * This function is called by remove function when wanting to remove the
   * root. There are 3 main branches, if root has two children, if root has one
   * child and if root has no children.
   * For two children, the left most node of the root's right child is used to
   * replace the root. There are 2 branches within two children, if the node
   * being used to replace the root has zero or one child.
   * For the root having one child, the child becomes the new rootPtr. There
   * are two branches within one child, if the child is left or right.
   * For the root having zero children, the tree becomes empty.
   *
   * @pre must have at least one node in tree
   * @post The root of the tree is removed. If the root had two children then
   *       left most node of the root's right child is used to replace the
   *       root. If the root has one child, then the child of the root becomes
   *       the new root. If the root has no children, then the tree becomes
   *       emppty. Threads are adjusted as needed. Node's children pointers are
   *       nulled out as needed. Node's children pointers point to different
   *       nodes as needed.
   * @param remove points to the root of the tree.
   * @return true if able to remove the root or false otherwise
   */
  bool removeRoot(TreeNode<ItemType> *remove);
  /**
   * traverses tree in order and fills queue with pointers to nodes of the tree
   *
   * Threads are not used in this in oder traversal because this function is
   * used to thread the tree. This function is also used for get number of
   * nodes.
   *
   * @pre must have at least one node in tree with a pointer to that node.
   * @post const
   * @param currNode starts at the root of the tree and ends at the node that
   *        has the highest item
   * @param q is a queue of TreeNode pointers that is filled as the tree is
   *        traversed
   * @return void
   */
  void inOrderTraversal(TreeNode<ItemType> *currNode,
                        std::queue<TreeNode<ItemType> *> &q) const;
  /**
   * threads the tree
   *
   * This function is used by copy constructor, insert, and remove. Uses the
   * queue full of nullPointers from inOrderTraversal go through the queue and
   * check if the current node is a leaf, if it is, then set the right child
   * pointer to the next node in the queue and change the rightIsThread of the
   * leaf node to true.
   *
   *
   * @pre must have a tree
   * @post tree is threaded
   * @return void
   */
  void threadTree();
  /**
   * recursive function to help with deep copying
   *
   * Base case is if the treeNode, which is the current node of the tree being
   * copied, is at a leaf. Actions are done before both the left and right
   * child recursive calls. Actions include creating to nodes for the tree that
   * is copying, setting the parent of those new nodes to point to them,
   * setting the items of the new nodes, and setting the bool to indicate if
   * the right child is a thread or not.
   *
   * @pre must have two trees, one to copy and one copying
   * @post The tree you are creating will have the same values in the
   *       nodes of the tree you want to copy, and the nodes will be in the
   *       same order of the tree.
   * @param treeNode starts on rootPtr and goes along tree that is being copied
   * @param prevNode starts on rootPtr and goes along tree that is copying
   * @return void
   */
  void preOrderCopy(TreeNode<ItemType> *treeNode, TreeNode<ItemType> *prevNode);

public:
  /**
   * basic Constructor for ThreadedBST
   *
   * @pre nothing
   * @post ThreadedBST object initiallized
   */
  ThreadedBST();
  /**
   * constructor for ThreadedBST but also creates the root
   *
   * @pre nothing
   * @post ThreadedBST object created with rootPtr pointing to a created
   *       treeNode that has an item rootItem
   * @param rootItem is put into the treeNode that is created to be the root
   *        of the tree
   */
  ThreadedBST(const ItemType &rootItem);
  /**
   * uses preOrderCopy to make a deep copy of tree
   *
   * @pre must have tree
   * @post the tree you are creating will have the same values in the
   *       nodes of the tree you want to copy, and the nodes will be in the
   *       same order of the tree
   * @param tree is the tree you want to copy
   */
  ThreadedBST(const ThreadedBST<ItemType> &tree);
  /**
   * calls makeEmpty to empty the tree and delete the nodes
   *
   * @pre must have tree
   * @post nodes in tree are deleted and tree's rootPtr is set to nullptr
   */
  ~ThreadedBST();
  /**
   * if the rootPtr is nullptr then tree is empty
   *
   * @pre must have tree
   * @post const
   * @return tree if tree is empty or false otherwise
   */
  bool isEmpty() const;
  /**
   * recursive function to get the height of the tree
   *
   * Base case is if currNode is a leaf, and returns 1. Each recursive call to
   * left or right child will add 1 to the total of left or right,
   * respectively. Left and right are compared, the higher number of
   * recursive calls correlates to the higher number of nodes, and the higher
   * number is returned.
   *
   * @pre must have tree
   * @post const
   * @param currNode starts at root pointer and is used to traverse the tree
   * @return integer that is the height of the tree
   */
  int getHeight(TreeNode<ItemType> *currNode) const;
  /**
   * returns the number of nodes in the tree
   *
   * Uses the inOrderTraversal function to fill a queue with node pointers.
   * Then the size of the queue is returned.
   *
   * @pre must have tree
   * @post const
   * @return number of nodes in tree
   */
  int getNumberOfNodes() const;
  /**
   * creates a new node with item in it and inserts that node into the tree
   *
   * If the tree starts empty, then the node is added as the root. Otherwise
   * the node is added as added as a leaf. currNode will start at the root of
   * the tree and go to the left if the item of the node being inserted is less
   * than the item of the current node, otherwise it will go right. This will
   * continue until the new node has a place to be inserted that is not above
   * another node. Calls threadTree function at end if not just adding root.
   *
   * @pre must have tree
   * @post a new node is in the tree with that node holding item
   * @param item is put into the new node
   * @return true if able to insert, false otherwise
   */
  bool insert(ItemType item);
  /**
   * given an item will return a pointer to a node that has the same item
   *
   * If the given item is less than the item of the current node, the pointer
   * moves down one to the left, else if goes down to the right. Goes until it
   * finds the node or it reaches nullptr. If it is not in the tree than a
   * message is printed saying that the node could not be found and nullptr is
   * returned.
   *
   * @pre must have tree
   * @post const
   * @param find is the item in a node that you want to find
   * @return a pointer to a node if it holds the same item as find, or a
   *         nullptr if the tree does not have that node.
   */
  TreeNode<ItemType> *findNode(ItemType find) const;
  /**
   * finds the parent of the node that has the same item as find
   *
   * If the given item is less than the item of the current node, the pointer
   * moves down one to the left, else if goes down to the right. Goes until it
   * finds the node or it reaches nullptr. If it is not in the tree than a
   * message is printed saying that the node could not be found and nullptr is
   * returned. A pointer to the parent node also moves down the tree lagging
   * one node behind the current node.
   *
   * @pre must have tree
   * @post const
   * @param find is the item of the child node of the parent being looked for
   * @return a pointer to the parent node or nullptr if the tree does not have
   *         the child of the parent being looked for or if the child is the
   *         root.
   */
  TreeNode<ItemType> *findParent(ItemType find) const;
  /**
   * returns a pointer to the root of the tree
   *
   * @pre must have tree
   * @post const
   * @return pointer to root of tree, which may be nullptr if tree is empty
   */
  TreeNode<ItemType> *getRoot() const;
  /**
   * removes the node that holds the same item as passed in
   *
   * First the findNode and findParent functions are called and set to TreeNode
   * pointers, remove and parent. There are three main branches, of remove has
   * two children, one child, or no children.
   * For two children, the left most node of remove's right child is used to
   * replace the root. There are 2 branches within two children, if the node
   * being used to replace the root has zero or one child.
   * For remove having one child, the parent of remove now points to the child
   * of remove. There are two branches within one child, if the child is left
   * or right.
   * For the root having zero children, the node is  deleted.
   * If the node wanting to be removed is the root, then removeRoot function is
   * called.
   * call thread function at end
   *
   * @pre must have tree
   * @post node is removed, other nodes and threads may be adjusted as needed
   * @param toBeRemoved is used to find the node wanting to be removed. If a
   *        node has the same item as toBeRemoved, then it is removed.
   * @return true if able to remove item, false otherwise
   */
  bool remove(ItemType toBeRemoved);
  /**
   * makes the tree empty
   *
   * Uses a post order traversal to go through the tree and delete the nodes.
   * base case is if the node is a leaf.
   *
   * @pre must have tree
   * @post tree is empty and rootPtr is set to nullptr
   * @param currNode is a pointer that is used to traverse the tree.
   * @return void
   */
  void makeEmpty(TreeNode<ItemType> *currNode);
  /**
   * uses preOrderCopy to make a deep copy of right
   *
   * @pre must have tree
   * @post the tree on the left side of '=' will have the same values in the
   *       nodes of right tree, and the nodes will be in the same order of the
   *       tree
   * @param right is the tree you want to copy
   * @return a ThreadedBST that has same values in nodes of right tree
   */
  ThreadedBST<ItemType> &operator=(const ThreadedBST &right);
};

#include "threadedBST.cpp"

#endif
