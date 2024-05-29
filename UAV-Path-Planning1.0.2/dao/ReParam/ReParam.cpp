#include "ReParam.h"
int const next_position[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };// 定义方向
priority_queue<Node> open; // 优先队列，就相当于open表
bool close[N][N]; // 访问情况记录，close列表
int valueF[N][N]; // 记录每个节点对应的F值
int pre[N][N][2]; // 存储每个节点的父节点
int finishSelect = 0;
//int startMap[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//				 {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
//				 {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
//				 {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
//				 {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
//				 {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
//				 {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
//				 {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
//				 {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
//				 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
//int endMap[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//				 {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
//				 {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
//				 {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
//				 {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
//				 {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
//				 {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
//				 {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
//				 {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
//				 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
int startMap[N][N] = { 0 };
int endMap[N][N] = { 0 };
vector<QString> mapNames;//地图名
QDomDocument doc;//存地图信息
void InitIfoma()
{
	fill(close[0], close[0] + N * N, false);    // 将visit数组赋初值false
	fill(valueF[0], valueF[0] + N * N, 0);      // 初始化F全为0
	fill(pre[0][0], pre[0][0] + N * N * 2, -1); // 路径同样赋初值-1
}

void resetMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			endMap[i][j] = startMap[i][j];
		}
	}
	InitIfoma();
}
bool isValidNode(int x, int y, int xx, int yy)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false; // 判断边界
	if (startMap[x][y] == 1 || startMap[xx][yy] == 1)
		return false; // 判断障碍物
	// 两节点成对角型且它们的公共相邻节点存在障碍物，在8方向时用
	/*if (x != xx && y != yy && (startMap[x][yy] == 1 || startMap[xx][y] == 1))
		return false;*/
	return true;
}

void readXML()
{
		QString str;
		QFile file("map.xml");
		if (!file.open(QFileDevice::ReadOnly)) {
			qDebug() << file.errorString();
			return;
		}

		if (!doc.setContent(&file)) {
			file.close();
			return;
		}



		// 获得根节点
		QDomElement root = doc.documentElement();
		//qDebug() << "根节点：" << root.nodeName();

		// 获取所有map节点
		QDomNodeList list = root.elementsByTagName("map");
		for (int i = 0; i < list.count(); i++)
		{
			QDomElement element = list.at(i).toElement();
			mapNames.push_back(element.attribute("name"));
			qDebug() << "name" << element.attribute("name");
		}
		/* 获取尖括号间的值 */
		for (int i = 0; i < list.count(); i++)
		{
			// 获取链表中的值
			QDomElement element = list.at(i).toElement();

			// 找到需要读取的节点
			//if (element.attribute("name") == "地图1") {
			//	// 获得子节点
			//	QDomNode arr = element.namedItem("array");
			//	QString str = arr.firstChild().nodeValue();
			//	qDebug() << "arr" << str;
			// 也可以使用childNodes方法获取所有的子节点
			if (element.attribute("id") == "1") {
				QDomNodeList nodeList = element.childNodes();
				for (int j = 0; j < nodeList.count(); j++)
				{
					str = nodeList.at(j).firstChild().nodeValue();
					for (int k = 0; k < str.size(); k++)
					{
						if (str[k] == '0')
							startMap[j][k] = 0;
						else if (str[k] == '1')
							startMap[j][k] = 1;
					}
					qDebug() << "arr" << str;
				}
			}
		}
		file.close();
}

//void PrintPath(int x1, int y1)
//{
//	if (pre[x1][y1][0] == -1 || pre[x1][y1][1] == -1)
//	{
//		cout << "no path to get" << endl;
//		return;
//	}
//	int x = x1, y = y1;
//	int a, b;
//	while (x != -1 || y != -1)
//	{
//		map[x][y] = 2; // 将可行路径上的节点赋值为2
//		a = pre[x][y][0];
//		b = pre[x][y][1];
//		x = a;
//		y = b;
//	}
//	// ' '表示未经过的节点， '#'表示障碍物， '@'表示可行节点
//	string s[3] = { "  ", " #", " @" };
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			cout << s[map[i][j]];
//		cout << endl;
//	}
//}