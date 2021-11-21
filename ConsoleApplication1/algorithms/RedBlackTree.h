#pragma once

enum RBTColor {
	RED,
	BLACK
};

template <class T> 
class RBNode {
public:
	RBTColor color;
	T key;
	RBNode * left;
	RBNode * right;
	RBNode * parent;

	RBNode(T value, RBTColor c, RBNode *l, RBNode *r, RBNode *parent):key(value),color(c),left(l),right(r),parent()
};

template <class T>
class RedBlackTree
{
private:
	RBNode<T> *nRoot;
public:
	RedBlackTree();

	// 前序遍历"红黑树"
	void preOrder();
	// 中序遍历"红黑树"
	void inOrder();
	// 后序遍历"红黑树"
	void postOrder();

	// (递归实现)查找"红黑树"中键值为key的节点
	RBNode<T>* search(T key);
	// (非递归实现)查找"红黑树"中键值为key的节点
	RBNode<T>* iterativeSearch(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();

	// 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
	RBNode<T>* successor(RBNode<T> *x);
	// 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
	RBNode<T>* predecessor(RBNode<T> *x);

	void leftRotate(T * n);
	void rightRotate(T * n);

	void insert(T n);
	void remove(T n);
	void destory();
	void show();

	~RedBlackTree();

private:
	// 前序遍历"红黑树"
	void preOrder(RBNode<T>* tree) const;
	// 中序遍历"红黑树"
	void inOrder(RBNode<T>* tree) const;
	// 后序遍历"红黑树"
	void postOrder(RBNode<T>* tree) const;

	// (递归实现)查找"红黑树x"中键值为key的节点
	RBNode<T>* search(RBNode<T>* x, T key) const;
	// (非递归实现)查找"红黑树x"中键值为key的节点
	RBNode<T>* iterativeSearch(RBNode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的红黑树的最小结点。
	RBNode<T>* minimum(RBNode<T>* tree);
	// 查找最大结点：返回tree为根结点的红黑树的最大结点。
	RBNode<T>* maximum(RBNode<T>* tree);

	// 左旋
	void leftRotate(RBNode<T>* &root, RBNode<T>* x);
	// 右旋
	void rightRotate(RBNode<T>* &root, RBNode<T>* y);
	// 插入函数
	void insert(RBNode<T>* &root, RBNode<T>* node);
	// 插入修正函数
	void insertFixUp(RBNode<T>* &root, RBNode<T>* node);
	// 删除函数
	void remove(RBNode<T>* &root, RBNode<T> *node);
	// 删除修正函数
	void removeFixUp(RBNode<T>* &root, RBNode<T> *node, RBNode<T> *parent);

	// 销毁红黑树
	void destroy(RBNode<T>* &tree);

	// 打印红黑树
	void print(RBNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};