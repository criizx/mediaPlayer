#pragma once

#include <memory>
#include <QString>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/QMediaPlayer>

class playlist_loader {
public:
	static std::pair<std::unique_ptr<QMediaPlaylist>, std::unique_ptr<QMediaPlayer>>
	load_from_folder(const QString& path);
};
