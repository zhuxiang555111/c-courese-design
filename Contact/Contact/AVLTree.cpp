#include "AVLTree.h"
#include<string>

AVLTree::AVLTree()
	:myRoot(NULL)
{
}

AVLTree::~AVLTree()
{
	destroy(myRoot);
}

bool AVLTree::empty() const
{
	return myRoot == NULL;
}

AVLNode * AVLTree::search(const int index)  //��������
{
	locptr = myRoot;
	bool found = false;
	while (!found && locptr != NULL)
	{
		if (index < locptr->Data.index)
			locptr = locptr->left;
		else if (index > locptr->Data.index)
			locptr = locptr->right;
		else
			found = true;
	}
	return locptr;
}

info AVLTree::search_result(AVLNode * ptr)
{
	info this_information;
	this_information.index = (*ptr).Data.index;
	this_information.name = (*ptr).Data.name;
	this_information.password = (*ptr).Data.password;
	return this_information;
}



void AVLTree::insert(const info & item)
{
	m_insert(myRoot, item);
}

void AVLTree::remove(const int index)  //ɾ��ĳ���ڵ�
{
	myRoot = m_remove(myRoot, index);
}

void AVLTree::inorder(ostream & out) const
{
	inorderAux(out, myRoot);
}

void AVLTree::graph(ostream & out) const
{
	graphAux(out, 0, myRoot);
}

AVLNode * AVLTree::rotateLL(AVLNode *parent)
{
	AVLNode *node;
	node = parent->left;
	parent->left = node->right;
	node->right = parent;
	parent->heigh = max(height(parent->left), height(parent->right)) + 1;
	node->heigh = max(height(node->right), height(node->left)) + 1;
	return node;
}
AVLNode * AVLTree::rotateLR(AVLNode * parent)
{
	parent->left = rotateRR(parent->left);
	return rotateLL(parent);
}

AVLNode *  AVLTree::rotateRL(AVLNode * parent)
{
	parent->right = rotateLL(parent->right);
	return rotateRR(parent);
}

AVLNode *  AVLTree::rotateRR(AVLNode * parent)
{
	AVLNode *node;
	node = parent->right;
	parent->right = node->left;
	node->left = parent;
	parent->heigh = max(height(parent->left), height(parent->right)) + 1;
	node->heigh = max(height(node->right), height(node->right)) + 1;
	return node;
}


void AVLTree::inorderAux(ostream & out, AVLNode * subtreeRoot) const
{
	if (subtreeRoot != NULL)
	{
		inorderAux(out, subtreeRoot->left);
		out << subtreeRoot->Data.index << " " << subtreeRoot->Data.name << " " << subtreeRoot->Data.password << endl;
		inorderAux(out, subtreeRoot->right);
	}
}

void AVLTree::graphAux(ostream & out, int indent, AVLNode * subtreeRoot) const
{
	if (subtreeRoot != NULL)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out << setw(indent) << " " << subtreeRoot->Data.index << endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}
}

int AVLTree::height(AVLNode * node)
{
	if (node != NULL)
		return node->heigh;
	return 0;
}

AVLNode *  AVLTree::m_insert(AVLNode * &node, info data)
{
	if (node == NULL)
	{
		node = new AVLNode(data);
	}

	/*if (node->Data.index = data.index)
	{
	node->Data = data;
	}*/

	else if (node->Data.index < data.index) //�����ұ�
	{
		node->right = m_insert(node->right, data);

		if (2 == height(node->right) - height(node->left))
			if (data.index > node->right->Data.index)//�������ҽڵ�
				node = rotateRR(node);
			else
				node = rotateRL(node);
	}
	else if (node->Data.index > data.index)//�������
	{
		node->left = m_insert(node->left, data);

		if (2 == height(node->left) - height(node->right))
			if (data.index < node->left->Data.index)//��������ڵ�
				node = rotateLL(node);
			else
				node = rotateLR(node);
	}

	node->heigh = max(height(node->left), height(node->right)) + 1;
	return node;
}

AVLNode * AVLTree::m_remove(AVLNode *& node, int index) //ɾ������Ϊindex�Ľڵ�
{
	if (node != NULL)
	{
		if (index == node->Data.index)  //�ҵ�Ҫɾ���Ľڵ�
		{
			if (node->left != NULL && node->right != NULL) //���ҽڵ�ǿ�
			{
				//����������������
				if (height(node->left) > height(node->right))
				{
					AVLNode *  temp = maxNode(node->left);  //ȡ���������ڵ�
					node->Data = temp->Data;  //���ǵ�ǰ�ڵ�
					node->left = m_remove(node->left, temp->Data.index);//�ݹ�ɾ�����ڵ㣬��Ϊ�Ѿ�����滻
				}
				else   //����������������
				{
					//ʹ����������С�ڵ��滻
					AVLNode * temp2 = minNode(node->right);
					node->Data = temp2->Data;
					node->right = m_remove(node->right, temp2->Data.index);//�ݹ�ɾ����С�ڵ�
				}
			}
			else  //������ҽڵ�Ϊ��
			{
				AVLNode * temp3 = node;  //�ҵ�Ҫɾ���Ľڵ㲢����temp3
				if (node->left != NULL)
					node = node->left;
				else if (node->right != NULL)
					node = node->right;
				//temp3->Data = node->Data;
				if (node != temp3)     //ɾ���ķ���ײ��Ҷ�ڵ㣬Ҫreturn node
				{
					delete temp3;
					temp3 = NULL;
					return node;
				}
				else    //ɾ����ײ�Ҷ�ڵ�,ֱ��return NULL
					return NULL;
			}
		}
		else if (index > node->Data.index)  //Ҫɾ���Ľڵ���ڵ�ǰ�ڵ�,��������ִ��ɾ��
		{
			node->right = m_remove(node->right, index);
			//ɾ���������ڵ㵼�²�ƽ�⣬��ҪLL����LR��ת
			if (height(node->left) - height(node->right) == 2)
			{
				//LR��
				if (height(node->left->right) > height(node->left->left))
				{
					node = rotateLR(node);
				}
				else //LL��
				{
					node = rotateLL(node);
				}
			}
		}
		else if (index < node->Data.index)  //Ҫɾ���Ľڵ�С�ڵ�ǰ�ڵ�,��������ִ��ɾ��
		{
			node->left = m_remove(node->left, index);
			//ɾ�����������½ڵ㲻ƽ�⣬��ҪRL��ת����RR��ת
			if (height(node->right) - height(node->left) == 2)
			{
				if (height(node->right->left) > height(node->right->right))  //RL
					node = rotateRL(node);
				else //LL
					node = rotateRR(node);
			}
		}
		return node;
	}
	return NULL;
}

void AVLTree::destroy(AVLNode *& node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
		node = NULL;
	}
}

AVLNode * AVLTree::maxNode(AVLNode * node) const
{
	if (node != NULL)
	{
		while (node->right != NULL)
		{
			node = node->right;
			return node;
		}
		return NULL;
	}
}

AVLNode * AVLTree::minNode(AVLNode * node) const
{
	if (node != NULL)
	{
		while (node->left)
		{
			node = node->left;
			return node;
		}
	}
	return NULL;
}



int AVLTree::max(int cmpa, int cmpb)
{
	return cmpa > cmpb ? cmpa : cmpb;
}


