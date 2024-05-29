#include "arrShow.h"
#include "mapSelect.h"
#include "dao/ReParam/ReParam.h"
arrShow::arrShow(QWidget *parent)
    : QMainWindow(parent)
{


    ui.setupUi(this);
	InitIfoma();
    ui.tableWidget->setFrameShape(QFrame::NoFrame);
	ui.label2->setStyleSheet("QLabel{background-color:blue;}");
	ui.label2_6->setStyleSheet("QLabel{background-color:yellow;}");
	ui.label2_2->setStyleSheet("QLabel{background-color:red;}");
    //ui.tableWidget->setShowGrid(false);
    //ui.tableWidget->item(0,1)->setBackground(QColor(Qt::red));
	//ui.tableWidget->setStyleSheet("QTableWidget::item{border:0.5px solid black; }");//设置边框颜色
	ui.lineEdit->setValidator(new QIntValidator(ui.lineEdit));
	ui.lineEdit_2->setValidator(new QIntValidator(ui.lineEdit_2));//设置仅输入整数
	ui.lineEdit_3->setValidator(new QIntValidator(ui.lineEdit_3));
	ui.lineEdit_4->setValidator(new QIntValidator(ui.lineEdit_4));
	showMap();
	connect(ui.pushButton, &QPushButton::clicked, this, [=]() {
		resetMap();
		ui.tableWidget->clear();
		getNumsgetNums(ui.lineEdit, ui.lineEdit_2, ui.lineEdit_3, ui.lineEdit_4, x0, y0, x1, y1);
		bool a = isValidNode(x0, y0, x1, y1);
		//if (!isValidNode(x0, y0, x1, y1))
		if (!a)
		{
			QMessageBox::warning(NULL, "提示", "请输入正确的坐标点!", QMessageBox::Ok);
			showMap();
		}
		else
		{
			aStar->setNum(x0, y0, x1, y1);
			aStar->Astar();
			showPath();
		}
		});
	connect(ui.pushButton_2, &QPushButton::clicked, this, [=]() {
		mapSe->show();
		});
	connect(ui.pushButton_3, &QPushButton::clicked, this, [=]() {
		showMap();
		});
}

void arrShow::showMap()
{
	resetMap();
	ui.tableWidget->clear();
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
void arrShow::showPath()
{
	int x = x1, y = y1;
	int a, b;
	if (pre[x1][y1][0] == -1 || pre[x1][y1][1] == -1)
	{
		QMessageBox::information(NULL, "提示", "起点到终点无可达路径！" , QMessageBox::Ok);
		return;
	}
	while (x != -1 || y != -1)
	{
		endMap[x][y] = 2; // 将可行路径上的节点赋值为2
		a = pre[x][y][0];
		b = pre[x][y][1];
		x = a;
		y = b;
	}
	endMap[x0][y0] = 3;
	endMap[x1][y1] = 3;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (endMap[i][j] == 1)
			{
				QTableWidgetItem* item_color1 = new QTableWidgetItem();
				item_color1->setBackground(QColor(Qt::yellow));
				ui.tableWidget->setItem(i, j, item_color1);
			}
			else if (endMap[i][j] == 2)
			{
				QTableWidgetItem* item_color2 = new QTableWidgetItem();
				item_color2->setBackground(QColor(Qt::red));
				ui.tableWidget->setItem(i, j, item_color2);
			}
			else if (endMap[i][j] == 3)
			{
				QTableWidgetItem* item_color3 = new QTableWidgetItem();
				item_color3->setBackground(QColor(Qt::blue));
				ui.tableWidget->setItem(i, j, item_color3);
			}
		}
	}
}
void arrShow::getNumsgetNums(QLineEdit* l1, QLineEdit* l2, QLineEdit* l3, QLineEdit* l4, int& x1, int& y1, int& x2, int& y2)
{
	QString lsnum1, lsnum12, lsnuml3, lsnum14;
	lsnum1 = l1->text();
	y1 = lsnum1.toInt() - 1;
	lsnum12 = l2->text();
	x1 = lsnum12.toInt() - 1;
	lsnuml3 = l3->text();
	y2 = lsnuml3.toInt() - 1;
	lsnum14 = l4->text();
	x2 = lsnum14.toInt() - 1;
}

arrShow::~arrShow()
{
	ui.tableWidget->clear();
	delete aStar;
	delete mapSe;
}

