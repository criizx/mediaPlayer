#include <QApplication>
#include <QMainWindow>
#include "ui_mediaPlayer.h"
#include "RotatingLabel.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QMainWindow w;
	Ui::MainWindow ui;
	ui.setupUi(&w);

	QWidget *container = w.centralWidget();

	RotatingLabel *rot = new RotatingLabel(container);
	rot->setGeometry(ui.vinyl->geometry());
	rot->setFixedSize(ui.vinyl->size());
	rot->setPixmap(*ui.vinyl->pixmap());
	rot->setScaledContents(ui.vinyl->hasScaledContents());


	ui.vinyl->hide();


	rot->start();

	ui.pause->setCheckable(true);
	ui.pause->setIcon(QIcon(":/play/play.svg"));
	ui.pause->setIconSize(QSize(95,95));
	const QIcon pauseIcon(":/pause/pause.svg");
	QObject::connect(ui.pause, &QPushButton::toggled, [&](bool checked){
		ui.pause->setIcon( checked ? pauseIcon : QIcon(":/play/play.svg") );
		if (checked) rot->stop();
		else        rot->start();
	});

	w.show();
	return app.exec();
}
