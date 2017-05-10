#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QLabel>
#include <QHash>
#include <QtGui>
#include <QTableWidget>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);

	QHash <QString, int> parseText(QStringList &list);
	static QStringList GetListOfWords(QString &file_name);
	void insertHashOnTable(QHash<QString, int> &map);
	int random();
	QTableWidget *tabWgt_ptr;


	~MainWindow();

private slots:
	void on_pushButton_choose_file_clicked();

private:
	Ui::MainWindow *ui;
	QString filename; // имя файла, по которому будем анализировать слова
	QHash <QString, int> map; //карта, в ней будем считать повторения слов
	QStatusBar *st_bar;
	QLabel *wordsAmountOnStatusBar;
};

#endif // MAINWINDOW_H
