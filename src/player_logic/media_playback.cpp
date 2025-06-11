#include "../../include/player_logic/media_playback.h"
#include "../../include/player_logic/playlist_loader.h"
#include <QStandardPaths>


media_playback::media_playback(const QString& folderPath) {
	QString actualPath = folderPath;

	if (actualPath.isEmpty()) {
		actualPath = QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
	}
	try {
		auto [loadedPlaylist, loadedPlayer] = playlist_loader::load_from_folder(actualPath);
		playlist = std::move(loadedPlaylist);
		player = std::move(loadedPlayer);
	} catch (const std::exception& e) {
		qCritical() << "error loading media" << e.what();
		throw;
	}
}

void media_playback::play() const {
	player->play();
}

void media_playback::pause() const {
	player->pause();
}

void media_playback::next_track() const {
	playlist->next();
}

void media_playback::previous_track() const {
	playlist->previous();
}

void media_playback::set_volume(const int vol) const {
	player->setVolume(vol);
}

int media_playback::volume() const {
	return player->volume();
}

QString media_playback::get_current_file_path() const {
	return player->currentMedia().request().url().toLocalFile();
}

QMediaPlayer* media_playback::get_player() const {
	return player.get();
}
