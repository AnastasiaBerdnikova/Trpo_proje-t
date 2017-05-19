#ifndef TESTING_H
#define TESTING_H

#include <QObject>
#include <QWidget>
#include <QTest>
#include "../mainwindow.h"

class Testing : public QObject
{
	Q_OBJECT
private:
	MainWindow *wnd;

private slots:
	void create_obj();
	void ParsingTestFull();
	void ParsingTestEmpty();
	void HashMap_parse_correct_full();
	void HashMap_parse_correct_empty();
	void TableWidget_insertion_correct_full();
	void TableWidget_insertion_correct_empty();
	void clean();
};

#endif // TESTING_H
