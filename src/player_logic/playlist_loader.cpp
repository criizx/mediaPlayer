#include "../../include/player_logic/playlist_loader.h"
#include <QDir>
#include <QDebug>
#include <QUrl>
#include <QObject>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/QMediaPlayer>

std::pair<std::unique_ptr<QMediaPlaylist>, std::unique_ptr<QMediaPlayer>> playlist_loader::load_from_folder(const QString& path) {
	auto playlist = std::make_unique<QMediaPlaylist>();
	auto player = std::make_unique<QMediaPlayer>();

	const QDir dir(path);
	const QStringList filters = { "*.mp3", "*.wav", "*.flac", "*.aac", "*.ogg", "*.mp4" };

	for (const QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files); const QFileInfo &file : fileList) {
		playlist->addMedia(QUrl::fromLocalFile(file.absoluteFilePath()));
	}

	playlist->setCurrentIndex(0);
	playlist->setPlaybackMode(QMediaPlaylist::Loop);

	player->setPlaylist(playlist.get());

	return { std::move(playlist), std::move(player) };
}
