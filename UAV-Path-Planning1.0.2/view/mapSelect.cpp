#include "mapSelect.h"

mapSelect::mapSelect(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setFrameShape(QFrame::NoFrame);
	loadMapName();
	connect(ui.pushButton, &QPushButton::clicked, this, [=]() {
		ui.tableWidget->clear();
		mapName = ui.comboBox->currentText();
		selectMapInfo();
		/*this->close();*/
		showMap();
		});
	connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {
		this->close();
		return;
		});
}

void mapSelect::loadMapName()
{
	for (int i = 0; i < mapNames.size(); i++)
	{
		ui.comboBox->addItem(mapNames[i]);
	}
}

void mapSelect::selectMapInfo()
{
	QString str;
	QDomElement root = doc.documentElement();
	QDomNodeList list = root.elementsByTagName("map");
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
		if (element.attribute("name") == mapName) {
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
}

mapSelect::~mapSelect()
{
	ui.comboBox->clear();
}

void mapSelect::showMap()
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (startMap[i][j] == 1)
			{
				QTableWidgetItem* item_color1 = new QTableWidgetItem();
				item_color1->setBackground(QColor(Qt::yellow));
				ui.tableWidget->setItem(i, j, item_color1);
			}
		}
	}
}
