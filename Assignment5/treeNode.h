#ifndef TREENODE
#define TREENODE

template <class ItemType> class TreeNode {
private:
  ItemType item;
  TreeNode<ItemType> *leftChildPtr;
  TreeNode<ItemType> *rightChildPtr;
  bool rightIsThread;

public:
  TreeNode();
  ~TreeNode();
  TreeNode(const ItemType &anItem);
  TreeNode(const ItemType &anItem, TreeNode<ItemType> leftPtr,
           TreeNode<ItemType> rightPtr);

  void setItem(const ItemType &anItem);
  ItemType getItem() const;

  bool isLeaf() const;

  TreeNode<ItemType> *getLeftChildPtr() const;
  TreeNode<ItemType> *getRightChildPtr() const;

  void setLeftChildPtr(TreeNode<ItemType> *leftPtr);
  void setRightChildPtr(TreeNode<ItemType> *rightPtr);

  void setRightIsThread(bool thread);

  bool getRightIsThread();

  void operator=(const TreeNode<ItemType> &right);
  bool operator==(const TreeNode &right) const;
  bool operator<(const TreeNode &right) const;
  bool operator>(const TreeNode &right) const;
};

#include "treeNode.cpp"

#endif
