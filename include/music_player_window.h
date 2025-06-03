#pragma once

#include <QMainWindow>
#include "ui_mediaPlayer.h"
#include "RotatingLabel.h"

class music_player_window : public QMainWindow {
	Q_OBJECT

public:
	explicit music_player_window(QWidget *parent = nullptr);

private:
	Ui::MainWindow ui;
	RotatingLabel* rot = nullptr;
};
