logic_Tree.h //����ͷ�ļ�
logic_Tree.cpp //����ʵ���ļ�
logic_TreeNode.h //���ڵ�ͷ�ļ�
logic_TreeNode.cpp //���ڵ�ʵ���ļ�

������Է����������´��룺

void logic_Test::testTree()
{
	typedef logic_TreeNode node_type;
	typedef logic_Tree tree_type;

	tree_type tree1(5);
	
 	tree1.add_node(5,7);
 	tree1.add_node(5,8);
 	tree1.add_node(5,10);
 	tree1.insert_node(5,10,6);
 	tree1.add_node(6,11);
 	tree1.recurs_print(tree1.getRoot());

 	cout<<"\nɾ����"<<endl;
 	tree1.del_node(6);
	tree1.recurs_print(tree1.getRoot());

	delete tree1;
}


ע��
1. recurs_print() ����������д�����ã����Բ��ù�floor����
2. �ϴβ������д����ѽ��ж��Լ��
3. ��Ҫ������tree��delete
4. destroy() ������˽�к����������ⲿ����