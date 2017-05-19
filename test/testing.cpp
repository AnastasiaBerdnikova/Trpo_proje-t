#include "testing.h"
#include <QTest>
#include <QApplication>
#include <QStringList>
#include <QString>
#include <QFile>
#include <QByteArray>
#include "../mainwindow.h"

QTEST_MAIN(Testing)

void Testing::create_obj()
{
	wnd = new MainWindow(0);
}

void Testing::ParsingTestFull() // тест для проверки работы функции разбиения текста на слова
{
	QString filename = QApplication::applicationDirPath() + "/input.txt";

	QStringList list = wnd->GetListOfWords(filename);
	QStringList list2;
	QString buff;
	QFile f("input.txt");
	f.open(QFile::ReadOnly);

	buff = f.readAll();
	buff.remove(QRegExp("[\\n\\t\\r!@#$%^&*()-=_+|;':\",.<>?']"));

	list2 = buff.split(QRegExp("\\s"));


	QCOMPARE(list.size(), list2.size());
}

