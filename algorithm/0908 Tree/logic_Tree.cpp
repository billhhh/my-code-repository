/* 
* 
* funtion: �߼�������֯�ṹ
* 
* Date:2015-09-03
* 
*    Author: Bill Wang
*/

#include <iostream>
#include <assert.h>
#include <climits>
#include "logic_Tree.h"

using namespace std;
typedef logic_TreeNode tree_node;

//logic_Tree ���졢��������
logic_Tree::logic_Tree() //Ĭ�Ϲ���һ��root IDΪ0�Ľڵ�
	:mvu_root(new logic_TreeNode(0))
{
	Init();
}

logic_Tree::logic_Tree(_IdDataType rootId)
{
	assert(rootId<INT_MAX);
	assert(rootId>INT_MIN);

	tree_node* node = new tree_node(rootId); //����root�ڵ�
	this->mvu_root = node;
	Init();
}

logic_Tree::logic_Tree(tree_node *node)
	:mvu_root(node)
{
	assert(node);
	assert(node->mvi_NodeID<INT_MAX);
	assert(node->mvi_NodeID>INT_MIN);

	Init();
}

logic_Tree::~logic_Tree()
{
	cout<<"����logic_Tree��������"<<endl;
	Destroy(mvu_root);
}

void logic_Tree::Init()
{
	this->mvi_TreeID = this->mvu_root->mvi_NodeID; //��ID��root ID��ʶ
}

void logic_Tree::Destroy(tree_node *some)
{
	//����ɾ��
	for (unsigned i = 0; i < some->mvvu_Children.size(); i++)
		Destroy(some->mvvu_Children[i]);
	SAFE_DELETE(some);
}

//������
logic_Tree::iterator::iterator()
	:_node(0) //NULL
{

}

logic_Tree::iterator::iterator(tree_node *node)
	:_node(node)
{

}

logic_Tree::iterator::~iterator()
{

}

tree_node* logic_Tree::iterator::get_cur_node()
{
	return _node;
}//������ END

tree_node* logic_Tree::getRoot()
{
	return this->mvu_root;
}

//����ɾ���鹦���ⲿ�ӿ�
bool logic_Tree::add_node(_IdDataType parent_ID,_IdDataType ID)
{
	iterator *temPos = search(ID);
	if ( NULL != temPos ) //����Ѿ����ڣ�����
	{
		SAFE_DELETE(temPos);
		return false;
	}

	tree_node *tmp = new tree_node(ID);
	iterator* position = search(parent_ID);

	if ( NULL == position)
	{
		SAFE_DELETE(position);
		return false;
	}

	position->_node->mvvu_Children.push_back(tmp);
	tmp->mvu_Parent = position->_node;
	SAFE_DELETE(position); //delete position;

	return true;
}

bool logic_Tree::insert_node(_IdDataType parent_ID,_IdDataType suc_ID,_IdDataType ID)
{
	iterator* positionA = search(parent_ID);
	iterator* positionB = search(suc_ID);

	if ( NULL == positionA || NULL == positionB)
	{
		//�����ڴ����ⱨ��
		SAFE_DELETE(positionA);
		SAFE_DELETE(positionB);
		return false;
	}

	//���suc_ID�ڵ㲻��parent_ID�ڵ�ֱ�Ӻ��ӣ�����
	int index = isChild(positionA,positionB);
	if (index == -1)
	{
		SAFE_DELETE(positionA);
		SAFE_DELETE(positionB);
		return false;
	}

	tree_node *tmp = new tree_node(ID);
	positionA->_node->mvvu_Children.erase(positionA->_node->mvvu_Children.begin()+index); //ɾ��parent_ID�ڵ��е�suc_ID�ڵ㺢��
	positionA->_node->mvvu_Children.push_back(tmp);
	tmp->mvvu_Children.push_back(positionB->_node);
	tmp->mvu_Parent = positionA->_node;
	positionB->_node->mvu_Parent = tmp;

	SAFE_DELETE(positionA);
	SAFE_DELETE(positionB);

	return true;
}

int logic_Tree::isChild(iterator* p, iterator* c) const
{
	int Search_ID = c->_node->mvi_NodeID;
	for (int i=0;i<p->_node->mvvu_Children.size();++i)
	{
		if (Search_ID == p->_node->mvvu_Children[i]->mvi_NodeID)
		{
			return i;
		}
	}

	return -1;
}

bool logic_Tree::del_node(_IdDataType ID)
{
	assert(ID != mvi_TreeID);

	iterator* position = search(ID);
	if (NULL == position)
	{
		SAFE_DELETE(position);
		return false;
	}

	tree_node *cur_node = position->_node;
	for (int i=0;i<cur_node->mvvu_Children.size();++i)
	{
		//����ɾ���ڵ�����ж��Ӵ�������
		cur_node->mvu_Parent->mvvu_Children.push_back(cur_node->mvvu_Children[i]);
		cur_node->mvvu_Children[i]->mvu_Parent = cur_node->mvu_Parent;
	}
	//���丸�׵Ĵ˶���ɾ��
	for (int i=0;i<cur_node->mvu_Parent->mvvu_Children.size();++i)
	{
		if(cur_node->mvu_Parent->mvvu_Children[i]->mvi_NodeID == ID)
			cur_node->mvu_Parent->mvvu_Children.erase(cur_node->mvu_Parent->mvvu_Children.begin()+i);
	}

	SAFE_DELETE(cur_node);
	SAFE_DELETE(position);

	return true;
}

logic_Tree::iterator* logic_Tree::search(_IdDataType ID)
{
	tree_node* some = mvu_root;
	tree_node* res = recurs_render(mvu_root,ID);

	if (res == NULL)
		return NULL;

	//���ڵ���search�����ĵط��ͷ�
	iterator* tmp = new iterator(res);
	return tmp;
}

tree_node* logic_Tree::recurs_render(tree_node* some,const _IdDataType ID)
{
	if (ID == some->mvi_NodeID)
		return some;

	for (unsigned i = 0; i < some->mvvu_Children.size(); i++)
	{
		tree_node* r = recurs_render(some->mvvu_Children[i],ID);

		if(NULL != r)
			return r;
	}

	return NULL;
}

void logic_Tree::recurs_print(tree_node* some,int floor) const
{
	std::cout << "floor " << floor << ": ";
	++floor;
	std::cout << some->mvi_NodeID << std::endl;
	for (unsigned i = 0; i < some->mvvu_Children.size(); i++)
		recurs_print(some->mvvu_Children[i],floor);
	--floor;
}