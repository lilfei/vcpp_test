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

	// ǰ�����"�����"
	void preOrder();
	// �������"�����"
	void inOrder();
	// �������"�����"
	void postOrder();

	// (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
	RBNode<T>* search(T key);
	// (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
	RBNode<T>* iterativeSearch(T key);

	// ������С��㣺������С���ļ�ֵ��
	T minimum();
	// ��������㣺���������ļ�ֵ��
	T maximum();

	// �ҽ��(x)�ĺ�̽�㡣��������"�����������ֵ���ڸý��"��"��С���"��
	RBNode<T>* successor(RBNode<T> *x);
	// �ҽ��(x)��ǰ����㡣��������"�����������ֵС�ڸý��"��"�����"��
	RBNode<T>* predecessor(RBNode<T> *x);

	void leftRotate(T * n);
	void rightRotate(T * n);

	void insert(T n);
	void remove(T n);
	void destory();
	void show();

	~RedBlackTree();

private:
	// ǰ�����"�����"
	void preOrder(RBNode<T>* tree) const;
	// �������"�����"
	void inOrder(RBNode<T>* tree) const;
	// �������"�����"
	void postOrder(RBNode<T>* tree) const;

	// (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBNode<T>* search(RBNode<T>* x, T key) const;
	// (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBNode<T>* iterativeSearch(RBNode<T>* x, T key) const;

	// ������С��㣺����treeΪ�����ĺ��������С��㡣
	RBNode<T>* minimum(RBNode<T>* tree);
	// ��������㣺����treeΪ�����ĺ����������㡣
	RBNode<T>* maximum(RBNode<T>* tree);

	// ����
	void leftRotate(RBNode<T>* &root, RBNode<T>* x);
	// ����
	void rightRotate(RBNode<T>* &root, RBNode<T>* y);
	// ���뺯��
	void insert(RBNode<T>* &root, RBNode<T>* node);
	// ������������
	void insertFixUp(RBNode<T>* &root, RBNode<T>* node);
	// ɾ������
	void remove(RBNode<T>* &root, RBNode<T> *node);
	// ɾ����������
	void removeFixUp(RBNode<T>* &root, RBNode<T> *node, RBNode<T> *parent);

	// ���ٺ����
	void destroy(RBNode<T>* &tree);

	// ��ӡ�����
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