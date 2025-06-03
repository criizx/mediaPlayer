#pragma once

#include "ui_mediaPlayer.h"
#include "RotatingLabel.h"

class music_player_window final : public QMainWindow {
	Q_OBJECT

public:
	explicit music_player_window(QWidget *parent = nullptr);

private:
	Ui::MainWindow ui;

	RotatingLabel *vinylRot = nullptr;
	RotatingLabel *coverRot = nullptr;
	QVariantAnimation *anim  = nullptr;
};
