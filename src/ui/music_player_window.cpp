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

	uiManager = std::make_unique<player_ui>(ui);
	uiManager->setup(ui.mainwindow);

	rotator = std::make_unique<disc_rotator>(
		uiManager->vinylLabel(),
		uiManager->coverLabel()
	);

	const QIcon playIcon(":/play/play.svg");
	const QIcon pauseIcon(":/pause/pause.svg");

	ui.label->setText(QCoreApplication::translate("MainWindow", "Я помню", nullptr));
	ui.label_2->setText(QCoreApplication::translate("MainWindow", "artist", nullptr));

	auto *pauseBtn = uiManager->pauseButton();
	pauseBtn->setCheckable(true);
	pauseBtn->setIcon(playIcon);
	pauseBtn->setIconSize(QSize(95, 95));

	connect(pauseBtn, &QPushButton::toggled, this,
			[this, playIcon, pauseIcon, pauseBtn](const bool checked) {
				pauseBtn->setIcon(checked ? pauseIcon : playIcon);
				if (checked) rotator->pause();
				else         rotator->resume();
			});

	rotator->start();
}
