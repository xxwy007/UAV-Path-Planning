#include "view.h"
void PrintPath(int x1, int y1)
{
	if (pre[x1][y1][0] == -1 || pre[x1][y1][1] == -1)
	{
		cout << "no path to get" << endl;
		return;
	}
	int x = x1, y = y1;
	int a, b;
	while (x != -1 || y != -1)
	{
		map[x][y] = 2; // ������·���ϵĽڵ㸳ֵΪ2
		a = pre[x][y][0];
		b = pre[x][y][1];
		x = a;
		y = b;
	}
	// ' '��ʾδ�����Ľڵ㣬 '#'��ʾ�ϰ�� '@'��ʾ���нڵ�
	string s[3] = { "  ", " #", " @" };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << s[map[i][j]];
		cout << endl;
	}
}