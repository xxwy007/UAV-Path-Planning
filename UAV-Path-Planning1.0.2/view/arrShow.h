#pragma once
#include <QtWidgets/QMainWindow>
#include <QMessageBox.h>
#include "ui_arrShow.h"
#include "mapSelect.h"
#include "service/aStarAlgorithm/AStar.h"
#include "service/aStarAlgorithm/Node.h"
class arrShow : public QMainWindow
{
    Q_OBJECT

public:
    arrShow(QWidget *parent = nullptr);
    void showMap();
    void showPath();//展示路径
	void getNumsgetNums(QLineEdit* l1, QLineEdit* l2, QLineEdit* l3, QLineEdit* l4, int& x1, int& y1, int& x2, int& y2);//获取x，y
	int x0, y0, x1, y1;
    AStar* aStar = new AStar();
    mapSelect* mapSe = new mapSelect();
    ~arrShow();

private:
    Ui::arrShowClass ui;
};
