#pragma once
#include <QMainWindow>
#include "ui_mapSelect.h"
#include "../dao/ReParam/ReParam.h"

class mapSelect : public QMainWindow
{
	Q_OBJECT

public:
	mapSelect(QWidget *parent = nullptr);
	void loadMapName();
	void selectMapInfo();
	void showMap();
	QString mapName;
	~mapSelect();

private:
	Ui::mapSelectClass ui;
};
