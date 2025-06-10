#pragma once

#include <memory>
#include <QString>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimedia/QMediaPlayer>

class media_playback
{
public:
	explicit media_playback(const QString& folderPath);

	void play() const;
	void pause() const;
	void next_track() const;
	void previous_track() const;
	void set_volume(int vol) const;
	int volume() const;

private:
	std::unique_ptr<QMediaPlaylist> playlist;
	std::unique_ptr<QMediaPlayer> player;
};
