#pragma once

#include "ui_mediaPlayer.h"
#include "RotatingLabel.h"

class player_ui {
public:
	explicit player_ui(Ui::MainWindow &ui);

	void setup(QWidget *container);

	RotatingLabel *vinylLabel() const;
	RotatingLabel *coverLabel() const;
	QPushButton *pauseButton() const;

private:
	Ui::MainWindow &ui;
	RotatingLabel *vinylRot = nullptr;
	RotatingLabel *coverRot = nullptr;
};
