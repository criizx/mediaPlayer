#pragma once
#include "../ui/music_player_window.h"
#include "../player_logic/media_playback.h"
#include "../player_logic/music_metadata.h"

class Controller final : public QObject {
	Q_OBJECT
	private:
		music_player_window player;
		media_playback playback;
		music_metadata metadata;

		QIcon playIcon;
		QIcon pauseIcon;



		void setup_connections();
		void setup_rotator() const;

	public:

		explicit Controller(const QString& path, QObject *parent = nullptr);
		void show() { player.showWindow(); }

		void change_music_path();
		void change_disp_metadata();


public slots:
		void on_play_pause_toggled(bool checked) const;
		void next();
		void prev();
		void change_volume(int volume) const;
		void add_volume() const;
		void reduce_volume() const;
		void handle_media_status(QMediaPlayer::MediaStatus status);


};