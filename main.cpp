#include <QApplication>
#include <QMainWindow>
#include "./include/ui_mediaPlayer.h"
#include "./include/RotatingLabel.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QMainWindow w;

	w.setFixedSize(480, 630);

	Ui::MainWindow ui;
	ui.setupUi(&w);

	QWidget *container = w.centralWidget();

	auto *rot = new RotatingLabel(container);
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
	QObject::connect(ui.pause, &QPushButton::toggled, [&](const bool checked){
		ui.pause->setIcon( checked ? pauseIcon : QIcon(":/play/play.svg") );
		if (checked) rot->pause();
		else        rot->start();
	});

	w.show();
	return QApplication::exec();
}