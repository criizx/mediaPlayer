#pragma once

#include <memory>
#include "ui_mediaPlayer.h"

#include "player_ui.h"
#include "disc_rotator.h"

class music_player_window final : public QMainWindow {
	Q_OBJECT

public:
	explicit music_player_window(QWidget *parent = nullptr);

	[[nodiscard]] player_ui* get_UI_manager() const { return uiManager.get(); }
	[[nodiscard]] disc_rotator* get_rotator() const { return rotator.get(); }

	void showWindow() { show(); }

private:
	void setup_UI();
	void setup_icons() const;
	Ui::MainWindow ui{};
	std::unique_ptr<player_ui> uiManager;
	std::unique_ptr<disc_rotator> rotator;
};
