//�Ƴ���ҳ�����صĴ��룬���к�ǰ����к�����
#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("removeRowNum_out.txt","w",stdout);
	string s,tmp;
	//����
	getline(cin,s);
	while(1)
	{
		getline(cin,tmp);
		if (tmp.size()==0) //�������������س�����
			break;

		s.append("\n");
		s.append(tmp);
	}

	for (int i=0;i<s.length();i++)
	{
		if (s.at(i) == '\n')//���ĳһλ�ǻس��������λȥ��
			s.erase(i+1,2);
	}

	cout<<"�����Ľ��Ϊ��\n";
	cout<<s<<"\n";

	system("pause");
	return 0;
}
