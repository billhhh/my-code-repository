#include <afx.h>

void findFilesName(CString path)
{
	CFileFind finder;
	bool bResult =finder.FindFile(path+"\\*.*");
	while(bResult ){
		bResult =finder.FindNextFile();//��ȡ��һ���ļ�
		cout<<(LPCTSTR)finder.GetFileName()<<"\n";
	}
	finder.Close();
}