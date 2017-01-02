#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <cassert>
#include <time.h>
#include <queue>
#include <map>
#include <stack>
#include <bitset>
#include <string>
#include <sstream>
#define INF 0x3f3f3f3f

#define PRINT(x) cout<<x<<endl;

using namespace std;

template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

//======================================================

enum Path{
	LEFT = 0,
	RIGHT
};

typedef struct {

	int ori; //ԭ����
	int dp;
	Path path;
}Node;

Node node[102][102];

int main()
{
	//freopen("input.txt", "r", stdin);

	int n; //�����εĲ���
	cin >> n;

	//1������ԭ����
	for (int i = 0; i < n; ++i) {

		for (int j = 0; j <= i; ++j) {

			cin >> node[i][j].dp;
			node[i][j].ori = node[i][j].dp;
		}
	}
	cout << endl;

	//2�����ɶ������
	for (int i = n - 2; i >= 0; --i) {

		for (int j = 0; j <= i; ++j) {

			//node[i][j].dp += max(node[i + 1][j].dp, node[i + 1][j + 1].dp);

			if (node[i + 1][j].dp > node[i + 1][j + 1].dp) { //��߸��󣬼���ȥ

				node[i][j].dp += node[i + 1][j].dp;
				node[i][j].path = LEFT;
			}

			else {

				node[i][j].dp += node[i + 1][j + 1 ].dp;
				node[i][j].path = RIGHT;
			}
		}
	}

	//3����ӡ���������
	for (int i = 0; i < n; ++i) {

		for (int j = 0; j <= i; ++j) {

			cout << node[i][j].dp << " ";
		}
		cout << endl;
	}

	//4����ӡ·��
	cout << endl << "The route is:" << endl;
	Node cur;
	int col = 0; //�к�
	for (int i = 0; i < n; ++i) {

		cur = node[i][col];

		cout << "(" << i << "," << col << ")" << " ";
		cout << cur.ori << endl;

		if (cur.path == RIGHT)
			++col;
	}

	return 0;
}