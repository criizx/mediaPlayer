#include "../../include/player_logic/media_playback.h"
#include "../../include/player_logic/playlist_loader.h"

media_playback::media_playback(const QString& folderPath) {
	auto [loadedPlaylist, loadedPlayer] = playlist_loader::load_from_folder(folderPath);
	playlist = std::move(loadedPlaylist);
	player = std::move(loadedPlayer);
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

void media_playback::set_volume(int vol) const {
	player->setVolume(vol);
}

int media_playback::volume() const {
	return player->volume();
}
