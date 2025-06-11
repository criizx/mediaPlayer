#include "../../include/ui/music_player_window.h"
#include "../../include/ui/player_ui.h"
#include "../../include/ui/disc_rotator.h"
#include <QCoreApplication>
#include <QIcon>
#include <QSize>

music_player_window::music_player_window(QWidget *parent)
	: QMainWindow(parent)
{
	setFixedSize(480, 650);
	ui.setupUi(this);

	setup_UI();
	setup_icons();

}


void music_player_window::setup_UI() {

	uiManager = std::make_unique<player_ui>(ui);
	uiManager->setup(ui.mainwindow);


	rotator = std::make_unique<disc_rotator>(
	   uiManager->vinyl_label(),
	   uiManager->cover_label()
	);

	ui.label->setText(QCoreApplication::translate("MainWindow", "Я помню", nullptr));
	ui.label_2->setText(QCoreApplication::translate("MainWindow", "artist", nullptr));
}

void music_player_window::setup_icons() const {
	const QIcon playIcon(":/play/play.svg");

	auto *pauseBtn = uiManager->pause_button();
	pauseBtn->setCheckable(true);
	pauseBtn->setIcon(playIcon);
	pauseBtn->setIconSize(QSize(95, 95));

}
