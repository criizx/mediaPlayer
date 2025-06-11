#pragma once

#include "ui_mediaPlayer.h"
#include "RotatingLabel.h"
#include "player_logic/music_metadata.h"

class player_ui {
public:
	explicit player_ui(Ui::MainWindow &ui);

	void setup(QWidget *container);

	RotatingLabel *vinyl_label() const;
	RotatingLabel *cover_label() const;
	QPushButton *pause_button() const;
	QPushButton *next_button() const;
	QPushButton *prev_button() const;
	QSlider *volume_slider() const;
	QPushButton* add_volume() const;
	QPushButton* reduce_volume() const;
	void change_ui(const music_metadata& metadata) const;

private:
	Ui::MainWindow &ui;
	RotatingLabel *vinyl_rot = nullptr;
	RotatingLabel *cover_rot = nullptr;
};
