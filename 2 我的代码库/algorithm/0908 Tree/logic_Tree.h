/* 
* 
* funtion: �߼�������֯�ṹ
* 
* Date:2015-09-03
* 
*    Author: Bill Wang
*/

#ifndef _LOGIC_TREE_H_
#define _LOGIC_TREE_H_

#include "logic_TreeNode.h"
#include "logic_Global.h"

class logic_Tree
{
protected:
	typedef logic_TreeNode tree_node;
public:
	_IdDataType mvi_TreeID; //TreeID��rootID

	explicit logic_Tree();
	explicit logic_Tree(_IdDataType rootId);
	explicit logic_Tree(tree_node *node);
	~logic_Tree();

	//������Ƕ����
	class iterator{
	public:
		//����������
		iterator();
		explicit iterator(tree_node *node);
		~iterator();

		tree_node *_node;

		tree_node* get_cur_node(); //��ȡ��ǰ�ڵ�
		// 		iterator begin() const; //��ʼλ��
		// 		iterator end() const; //����λ��

	protected:

	private:
		//tree_node* _find_end(tree_node* current) const;
	};

public:
	tree_node * getRoot();

	//����ɾ���鹦���ⲿ�ӿ�
	bool add_node(_IdDataType parent_ID,_IdDataType ID); //����parent��
	bool insert_node(_IdDataType parent_ID,_IdDataType suc_ID,_IdDataType ID); //���������ڵ��м�
	bool del_node(_IdDataType ID);
	iterator* search(_IdDataType ID); //��������
	void recurs_print(tree_node* some,int floor=0) const; //DFS��ӡ����

protected:

private:
	tree_node *mvu_root;

	void Init();
	void Destroy(tree_node *some); /////����some�ڵ㼰�����к��������������
	int isChild(iterator* p, iterator* c) const; //�ж�c�ǲ���p��ֱ�Ӻ��ӣ�����ҵ�����i��û�ҵ�-1
	tree_node* recurs_render(tree_node* some,const _IdDataType ID); //�ݹ�DFS

};

#endif
