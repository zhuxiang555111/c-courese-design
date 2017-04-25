#pragma once
#include<iomanip>
#include"AVLNode.h"

class AVLTree
{

public:

	AVLTree();  //���캯��
	~AVLTree(); //��������
	bool empty()const;
	AVLNode * search(const int index);
	info search_result(AVLNode * ptr);
	void insert(const info& item);
	void remove(const int index);
	void inorder(ostream &out)const;
	void graph(ostream &out)const;
	AVLNode * rotateLL(AVLNode *parent);
	AVLNode * rotateLR(AVLNode *node);
	AVLNode * rotateRL(AVLNode *node);
	AVLNode * rotateRR(AVLNode *node);

private:

	AVLNode *myRoot;  //ָ����ڵ�
	AVLNode *locptr;

	//................�������..........................................................//
	void inorderAux(ostream &out, AVLNode *subtreeRoot)const;
	void graphAux(ostream &out, int indent, AVLNode *subtreeRoot)const;
	//..................................................................................//

	int height(AVLNode *node);

	AVLNode *  m_insert(AVLNode * &node, info data);
	AVLNode * m_remove(AVLNode * &node, int index);
	void destroy(AVLNode * &node);

	AVLNode * maxNode(AVLNode * node)const;  //���ڵ�
	AVLNode * minNode(AVLNode * node)const; //��С�ڵ�

	int max(int cmpa, int cmpb);
};
