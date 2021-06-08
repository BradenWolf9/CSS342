/**
 * @file treeNode.h
 * @author Tristan, Braden
 * @brief The TreeNode header file declares functions for the TreeNode class which
 * stores an item, two child pointers, and a boolean. The nodes are used for a
 * Threaded Binary Search Tree and has functions to representative of a BST.
 * @version 0.1
 * @date 2021-06-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef TREENODE
#define TREENODE

/**
 * @brief Template class of ItemType - main will be using of type Int for testing purposes
 *
 * @tparam ItemType
 */
template <class ItemType>
class TreeNode
{
  /**
   * @brief Private variable declarations
   *
   */
  private:
  ItemType item;
  TreeNode<ItemType> *leftChildPtr;
  TreeNode<ItemType> *rightChildPtr;
  bool rightIsThread;


  /**
   * @brief Public function declarations
   *
   */
  public:

  /**
   * @brief Construct a new Tree Node object
   * Default constructor
   * @pre When you want to create a TreeNode without a root
   * @post TreeNode object constructed with item to a default value, and nullptrs
   */
  TreeNode();

  /**
   * @brief Destroy the Tree Node object
   * @pre Called on every TreeNode object after the program executes
   * @post Empty TreeNode object
   */
  ~TreeNode();

  /**
   * @brief Construct a new Tree Node object
   * Constructor that takes an ItemType parameter
   * @pre When you want to create a TreeNode with an item
   * @post TreeNode object created with an item, null child ptrs
   * @param anItem
   */
  TreeNode(const ItemType& anItem);

  /**
   * @brief Construct a new Tree Node object
   * with an item, left child ptr, and a right child ptr
   * @pre Able to create a root item & the decision to link the child ptrs to another TreeNode
   * @post A TreeNode object is constructed with an Item, and possibly two root ptrs (if not nullptr)
   * @param anItem
   * @param leftPtr
   * @param rightPtr
   */
  TreeNode(const ItemType& anItem, TreeNode<ItemType> leftPtr,
           TreeNode<ItemType> rightPtr);

  /**
   * @brief Set the Item object of ItemType (template)
   * @pre The item should be a value that can be compared (int, double)
   * @post The item is set to however the user specified
   * @param anItem
   */
  void setItem(const ItemType& anItem);

  /**
   * @brief Get the Item object
   * @pre Gets the item as long as their is a value already set
   * @post Returns ItemType item
   * @return ItemType
   */
  ItemType getItem() const;

  /**
   * @brief Checks if the TreeNode is a leaf of the BST
   * @pre This function is used to check our iterations in threadedBST if we reached a leaf
   * @post Returns a boolean to threadedBST functions for threading, traversal, etc
   * @return true
   * @return false
   */
  bool isLeaf() const;

  /**
   * @brief Get the Left Child Ptr object
   * @pre As long as current node is not nullptr, able to get the child ptr
   * @post Returns left child pointer to a TreeNode
   * @return TreeNode<ItemType>*
   */
  TreeNode<ItemType>* getLeftChildPtr() const;

  /**
   * @brief Get the Right Child Ptr object
   * @pre As long as current node is not nullptr, able to get the child ptr
   * @post Returns right child pointer to a TreeNode
   * @return TreeNode<ItemType>*
   */
  TreeNode<ItemType>* getRightChildPtr() const;

  /**
   * @brief Set the Left Child Ptr object
   * @pre Requires valid TreeNode object to set
   * @post Sets left Child Pointer of a TreeNode object
   * @param leftPtr
   */
  void setLeftChildPtr(TreeNode<ItemType>* leftPtr);

  /**
   * @brief Set the Right Child Ptr object
   * @pre Requires valid TreeNode object to set
   * @post Sets right Child Pointer of a TreeNode object
   * @param rightPtr
   */
  void setRightChildPtr(TreeNode<ItemType>* rightPtr);

  /**
   * @brief Set the Right Is Thread object
   * @pre Used for threading the tree, (true)valid if right child ptr is not nullptr
   * @post Sets right thread to true or false depending on use-case
   * @param thread
   */
  void setRightIsThread(bool thread);

  /**
   * @brief Get the Right Is Thread object
   * @pre As long as its called on a TreeNode object
   * @post Returns true of false
   * @return true
   * @return false
   */
  bool getRightIsThread();

  /**
   * @brief Copy Operator
   * @pre Valid TreeNode object is passed in, same ItemType in both sides
   * @post Deep Copy of TreeNode object
   * @param right
   */
  void operator=(const TreeNode<ItemType> &right);

  /**
   * @brief Comparison Operators that check equals, less than, and greater than
   * @pre TreeNode passed in on right are not nullptr values
   * @post Returns true or false depending on given operator
   * @param right
   * @return bool
   */
  bool operator==(const TreeNode& right) const;
  bool operator<(const TreeNode& right) const;
  bool operator>(const TreeNode& right) const;

};

#include "treeNode.cpp"

#endif
