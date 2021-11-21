#include "RedBlackTree.h"

RedBlackTree<int>::RedBlackTree() {

}

template <class T>
void RedBlackTree<T>::leftRotate(RBNode<T>* &root, RBNode<T>* x)
{
	// ����x���Һ���Ϊy
	RBNode<T> *y = x->right;

	// �� ��y�����ӡ� ��Ϊ ��x���Һ��ӡ���
	// ���y�����ӷǿգ��� ��x�� ��Ϊ ��y�����ӵĸ��ס�
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	// �� ��x�ĸ��ס� ��Ϊ ��y�ĸ��ס�
	y->parent = x->parent;

	if (x->parent == NULL)
	{
		root = y;            // ��� ��x�ĸ��ס� �ǿսڵ㣬��y��Ϊ���ڵ�
	}
	else
	{
		if (x->parent->left == x)
			x->parent->left = y;    // ��� x�������ڵ�����ӣ���y��Ϊ��x�ĸ��ڵ�����ӡ�
		else
			x->parent->right = y;    // ��� x�������ڵ�����ӣ���y��Ϊ��x�ĸ��ڵ�����ӡ�
	}

	// �� ��x�� ��Ϊ ��y�����ӡ�
	y->left = x;
	// �� ��x�ĸ��ڵ㡱 ��Ϊ ��y��
	x->parent = y;
}

template <class T>
void RedBlackTree<T>::rightRotate(RBNode<T>* &root, RBNode<T>* y)
{
	// ����x�ǵ�ǰ�ڵ�����ӡ�
	RBNode<T> *x = y->left;

	// �� ��x���Һ��ӡ� ��Ϊ ��y�����ӡ���
	// ���"x���Һ���"��Ϊ�յĻ����� ��y�� ��Ϊ ��x���Һ��ӵĸ��ס�
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	// �� ��y�ĸ��ס� ��Ϊ ��x�ĸ��ס�
	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;            // ��� ��y�ĸ��ס� �ǿսڵ㣬��x��Ϊ���ڵ�
	}
	else
	{
		if (y == y->parent->right)
			y->parent->right = x;    // ��� y�������ڵ���Һ��ӣ���x��Ϊ��y�ĸ��ڵ���Һ��ӡ�
		else
			y->parent->left = x;    // (y�������ڵ������) ��x��Ϊ��x�ĸ��ڵ�����ӡ�
	}

	// �� ��y�� ��Ϊ ��x���Һ��ӡ�
	x->right = y;

	// �� ��y�ĸ��ڵ㡱 ��Ϊ ��x��
	y->parent = x;
}

template <class T>
void RedBlackTree<T>::insert(RBNode<T>* &root, RBNode<T>* node)
{
	RBNode<T> *y = NULL;
	RBNode<T> *x = root;

	// 1. �����������һ�Ŷ�������������ڵ���ӵ�����������С�
	while (x != NULL)
	{
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;

	// 2. ���ýڵ����ɫΪ��ɫ
	node->color = RED;

	// 3. ������������Ϊһ�Ŷ��������
	insertFixUp(root, node);
}

/*
 * �����(keyΪ�ڵ��ֵ)���뵽�������
 *
 * ����˵����
 *     tree ������ĸ����
 *     key ������ļ�ֵ
 */
template <class T>
void RedBlackTree<T>::insert(T key)
{
	RBNode<T> *z = NULL;

	// ����½����ʧ�ܣ��򷵻ء�
	if ((z = new RBNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;

	insert(mRoot, z);
}

template <class T>
void RedBlackTree<T>::insertFixUp(RBNode<T>* &root, RBNode<T>* node)
{
	RBNode<T> *parent, *gparent;

	// �������ڵ���ڣ����Ҹ��ڵ����ɫ�Ǻ�ɫ��
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);

		//�������ڵ㡱�ǡ��游�ڵ�����ӡ�
		if (parent == gparent->left)
		{
			// Case 1����������ڵ��Ǻ�ɫ
			{
				RBNode<T> *uncle = gparent->right;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
			if (parent->right == node)
			{
				RBNode<T> *tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ������ӡ�
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else//����z�ĸ��ڵ㡱�ǡ�z���游�ڵ���Һ��ӡ�
		{
			// Case 1����������ڵ��Ǻ�ɫ
			{
				RBNode<T> *uncle = gparent->left;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ�������
			if (parent->left == node)
			{
				RBNode<T> *tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ��ӡ�
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, gparent);
		}
	}

	// �����ڵ���Ϊ��ɫ
	rb_set_black(root);
}

template <class T>
void RedBlackTree<T>::remove(RBNode<T>* &root, RBNode<T> *node)
{
	RBNode<T> *child, *parent;
	RBTColor color;

	// ��ɾ���ڵ��"���Һ��Ӷ���Ϊ��"�������
	if ((node->left != NULL) && (node->right != NULL))
	{
		// ��ɾ�ڵ�ĺ�̽ڵ㡣(��Ϊ"ȡ���ڵ�")
		// ������ȡ��"��ɾ�ڵ�"��λ�ã�Ȼ���ٽ�"��ɾ�ڵ�"ȥ����
		RBNode<T> *replace = node;

		// ��ȡ��̽ڵ�
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;

		// "node�ڵ�"���Ǹ��ڵ�(ֻ�и��ڵ㲻���ڸ��ڵ�)
		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else
			// "node�ڵ�"�Ǹ��ڵ㣬���¸��ڵ㡣
			root = replace;

		// child��"ȡ���ڵ�"���Һ��ӣ�Ҳ����Ҫ"�����Ľڵ�"��
		// "ȡ���ڵ�"�϶����������ӣ���Ϊ����һ����̽ڵ㡣
		child = replace->right;
		parent = rb_parent(replace);
		// ����"ȡ���ڵ�"����ɫ
		color = rb_color(replace);

		// "��ɾ���ڵ�"��"���ĺ�̽ڵ�ĸ��ڵ�"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child��Ϊ��
			if (child)
				rb_set_parent(child, parent);
			parent->left = child;

			replace->right = node->right;
			rb_set_parent(node->right, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK)
			removeFixUp(root, child, parent);

		delete node;
		return;
	}

	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	parent = node->parent;
	// ����"ȡ���ڵ�"����ɫ
	color = node->color;

	if (child)
		child->parent = parent;

	// "node�ڵ�"���Ǹ��ڵ�
	if (parent)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		root = child;

	if (color == BLACK)
		removeFixUp(root, child, parent);
	delete node;
}

/*
 * ɾ��������м�ֵΪkey�Ľڵ�
 *
 * ����˵����
 *     tree ������ĸ����
 */
template <class T>
void RedBlackTree<T>::remove(T key)
{
	RBNode<T> *node;

	// ����key��Ӧ�Ľڵ�(node)���ҵ��Ļ���ɾ���ýڵ�
	if ((node = search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

template <class T>
void RedBlackTree<T>::removeFixUp(RBNode<T>* &root, RBNode<T> *node, RBNode<T> *parent)
{
	RBNode<T> *other;

	while ((!node || rb_is_black(node)) && node != root)
	{
		if (parent->left == node)
		{
			other = parent->right;
			if (rb_is_red(other))
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��  
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->right || rb_is_black(other->right))
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			other = parent->left;
			if (rb_is_red(other))
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��  
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if ((!other->left || rb_is_black(other->left)) &&
				(!other->right || rb_is_black(other->right)))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->left || rb_is_black(other->left))
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}

RedBlackTree<int>::~RedBlackTree() {

}