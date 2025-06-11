#include "../../include/controller/controller.h"
#include "../../include/player_logic/metadata_parser.h"
#include <algorithm>
#include <QMediaPlayer>

Controller::Controller(const QString& path, QObject *parent)
	: QObject(parent)
	, playback(path)
	, playIcon(":/play/play.svg")
	, pauseIcon(":/pause/pause.svg")
{
	playback.play();
	metadata = metadata_parser::parse(playback.get_current_file_path());
	change_disp_metadata();
	setup_connections();
	setup_rotator();
}

void Controller::setup_connections() {

	const auto* pause_btn = player.get_UI_manager()->pause_button();
	const auto* next_btn = player.get_UI_manager()->next_button();
	const auto* prev_btn = player.get_UI_manager()->prev_button();
	const auto* add_volume_btn = player.get_UI_manager()->add_volume();
	const auto* reduce_volume_btn = player.get_UI_manager()->reduce_volume();

	auto* volume_slider = player.get_UI_manager()->volume_slider();

	change_volume(volume_slider->value());

	connect(pause_btn, &QPushButton::toggled,
			this, &Controller::on_play_pause_toggled);

	connect(next_btn, &QPushButton::clicked, this, &Controller::next);

	connect(prev_btn, &QPushButton::clicked, this, &Controller::prev);

	connect(volume_slider, &QSlider::valueChanged, this, &Controller::change_volume);

	connect(add_volume_btn, &QPushButton::clicked, this, &Controller::add_volume);
	connect(reduce_volume_btn, &QPushButton::clicked, this, &Controller::reduce_volume);
	connect(playback.get_player(), &QMediaPlayer::mediaStatusChanged, this, &Controller::handle_media_status);
}

void Controller::on_play_pause_toggled(const bool checked) const {
	auto* pause_btn = player.get_UI_manager()->pause_button();
	const auto* rotator = player.get_rotator();

	pause_btn->setIcon(checked ? pauseIcon : playIcon);

	if (checked) {
		rotator->pause();
		playback.pause();
	} else {
		rotator->resume();
		playback.play();
	}
}

void Controller::next(){
	playback.next_track();
	change_disp_metadata();

}

void Controller::prev() {
	playback.previous_track();
	change_disp_metadata();
}

void Controller::setup_rotator() const {
	const auto* rotator = player.get_rotator();
	rotator->start();
}

void Controller::change_volume(const int volume) const {
	playback.set_volume(volume);
}

void Controller::add_volume() const {
	auto* slider = player.get_UI_manager()->volume_slider();
	const int current = slider->value();
	const int new_volume = std::min(current + 10, 100);
	playback.set_volume(new_volume);
	slider->setValue(new_volume);
}

void Controller::reduce_volume() const {
	auto* slider = player.get_UI_manager()->volume_slider();
	const int current = slider->value();
	const int new_volume = std::max(current - 10, 0);
	playback.set_volume(new_volume);
	slider->setValue(new_volume);
}

void Controller::change_disp_metadata() {
	metadata = metadata_parser::parse(playback.get_current_file_path());
	player.get_UI_manager()->change_ui(metadata);
}


void Controller::handle_media_status(const QMediaPlayer::MediaStatus status)  {
	if (status == QMediaPlayer::EndOfMedia) {
		change_disp_metadata();
	}
}