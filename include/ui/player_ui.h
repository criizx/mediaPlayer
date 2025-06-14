#pragma once

#include "ui_mediaPlayer.h"
#include "RotatingLabel.h"
#include "player_logic/music_metadata.h"

class player_ui {
public:
	explicit player_ui(Ui::MainWindow &ui);

	void setup(QWidget *container);

	[[nodiscard]] RotatingLabel *vinyl_label() const;
	[[nodiscard]] RotatingLabel *cover_label() const;
	[[nodiscard]] QPushButton *pause_button() const;
	[[nodiscard]] QPushButton *next_button() const;
	[[nodiscard]] QPushButton *prev_button() const;
	[[nodiscard]] QSlider *volume_slider() const;
	[[nodiscard]] QPushButton* add_volume() const;
	[[nodiscard]] QPushButton* reduce_volume() const;
	[[nodiscard]] QPushButton* change_path() const;
	void change_ui(const music_metadata& metadata) const;

private:
	Ui::MainWindow &ui;
	RotatingLabel *vinyl_rot = nullptr;
	RotatingLabel *cover_rot = nullptr;
};
