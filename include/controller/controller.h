#pragma once
#include "../ui/music_player_window.h"
#include "../player_logic/media_playback.h"

class Controller final : public QObject {
	Q_OBJECT
	private:
		music_player_window player;
		media_playback playback;

		QIcon playIcon;
		QIcon pauseIcon;



		void setup_connections();
		void setup_rotator() const;

	public:

		explicit Controller(const QString& path, QObject *parent = nullptr);
		void show() { player.showWindow(); }

		void change_music_path();

	public slots:
		void on_play_pause_toggled(bool checked) const;
		void next() const;
		void prev() const;
		void change_volume(int volume) const;
		void add_volume() const;
		void reduce_volume() const;

};