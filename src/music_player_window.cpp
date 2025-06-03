// music_player_window.cpp
#include "../include/music_player_window.h"
#include <QCoreApplication>
#include <QIcon>

music_player_window::music_player_window(QWidget *parent)
	: QMainWindow(parent)
{
	setFixedSize(480, 630);
	ui.setupUi(this);

	QWidget *container = centralWidget();

	rot = new RotatingLabel(container);
	rot->setGeometry(ui.vinyl->geometry());
	rot->setFixedSize(ui.vinyl->size());
	rot->setPixmap(*ui.vinyl->pixmap());
	rot->setScaledContents(ui.vinyl->hasScaledContents());

	ui.vinyl->hide();
	ui.label->setText(QCoreApplication::translate("MainWindow", "Я hello", nullptr));
	rot->start();

	ui.pause->setCheckable(true);
	ui.pause->setIcon(QIcon(":/play/play.svg"));
	ui.pause->setIconSize(QSize(95, 95));

	const QIcon pauseIcon(":/pause/pause.svg");
	connect(ui.pause, &QPushButton::toggled, this, [=](bool checked) {
		ui.pause->setIcon(checked ? pauseIcon : QIcon(":/play/play.svg"));
		checked ? rot->pause() : rot->start();
	});
}
