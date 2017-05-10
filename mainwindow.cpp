#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QFileDialog>
#include <QStandardPaths>
#include <QStatusBar>
#include <QMessageBox>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// делаем настройки в таблице
	ui->tableWidget->setColumnCount(2);
	ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Слово")); // добавляем столбец
	ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Повторений")); // и здесь тоже
	ui->tableWidget->setColumnWidth(0,160); // устанавливаем ширину столбцов в таблице
	ui->tableWidget->setColumnWidth(1,120);

	st_bar = new QStatusBar();
	this->setStatusBar(st_bar);

	wordsAmountOnStatusBar = new QLabel(this);
	st_bar->insertWidget(0,wordsAmountOnStatusBar,100);

	tabWgt_ptr = ui->tableWidget;

	this->setFocus();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_choose_file_clicked()
{
	QString path = QStandardPaths::displayName(QStandardPaths::HomeLocation);
	QFileDialog dialog;
	dialog.setFileMode(QFileDialog::AnyFile);
	dialog.setNameFilter("Text Files (*.txt)"); // делаем так, чтобы можно было выбирать только текстовые файлы

	filename = QFileDialog::getOpenFileName(this, "Открыть файл", path, "Text Files (*.txt)"); // открываем диалог
	if (ui->lineEdit->text() == "" || filename != "")
	{
		ui->lineEdit->setText(filename); // прописываем путь файла в поле
		ui->tableWidget->setRowCount(0);


		QStringList list_of_words = GetListOfWords(filename); // получаем список слов
		if(list_of_words.isEmpty())
		{
			qDebug() << "Empty hashmap";
			wordsAmountOnStatusBar->clear();

			QMessageBox msg;
			msg.setStandardButtons(QMessageBox::Ok);
			msg.setText("Текстовый файл пуст!");
			msg.setIcon(QMessageBox::Critical);
			msg.exec();

			return;
		}
		else
		{
			map = parseText(list_of_words); // разбираем список, считаем количество слов
			insertHashOnTable(map);
		}
	}

}

QHash<QString, int> MainWindow::parseText(QStringList &list)
{
	QHash<QString, int> hashmap;
	for (int i = 0; i < list.size(); i++)
	{
		if (!hashmap.contains(list.at(i))) // если список не содержит слово
		{
			hashmap.insert(list.at(i),1); // создаем его
		}
		else
		{
			hashmap[list.at(i)]++; // иначе добавляем единицу к частоте повторений
		}
	}

	qDebug() << hashmap;

	return hashmap;
}

QStringList MainWindow::GetListOfWords(QString &file_name) //возвращает список слов или пустой список, если текстовый файл пуст
{
	QStringList list; // список строк

	QString buffer; // сюда будет записан текст
	QFile file(file_name); // открываем файл
	file.open(QFile::ReadOnly);

	QByteArray arr;
	arr.append(file.readAll()); // читаем данные

	file.close();
	buffer = arr;
	qDebug() << buffer;

	buffer.remove(QRegExp("[\\n\\t\\r!@#$%^&*()-=_+|;':\",.<>?']")); //удалить из текста пробелы, символы переноса строк и знаки пунктуации

	buffer = buffer.toLower(); //делаем все буквы строчными

	qDebug() << "Обработанный текст:";
	qDebug() << buffer;

	if (!buffer.isEmpty()) //если список не пуст
		list = buffer.split(QRegExp("\\s")); // в этом списке будем хранить слова

	qDebug() << "Список слов:";
	qDebug() << list;

	return list;
}

void MainWindow::insertHashOnTable(QHash<QString, int> &map)
{
	ui->tableWidget->setRowCount(map.keys().size()); // ставим в таблице число строк
	for(int i = 0; i < map.keys().size(); i++) {
		QTableWidgetItem *col_1 = new QTableWidgetItem(), *col_2 = new QTableWidgetItem();
		col_1->setText(map.keys().at(i));
		col_2->setData(2, map[map.keys().at(i)]);
		ui->tableWidget->setItem(i,0,col_1); // ставим в таблицу
		ui->tableWidget->setItem(i,1,col_2);
	}

	ui->tableWidget->sortByColumn(1,Qt::DescendingOrder); // сортируем по убыванию
	wordsAmountOnStatusBar->setText("Всего слов: " + QString::number(map.keys().size()));
}

int MainWindow::random()
{
	srand(time(0));
	return rand() % 50;
}
