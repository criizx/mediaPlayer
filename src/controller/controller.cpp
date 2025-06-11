#include "../../include/controller/controller.h"
#include <algorithm>

Controller::Controller(const QString& path, QObject *parent)
	: QObject(parent)
	, playback(path)
	, playIcon(":/play/play.svg")
	, pauseIcon(":/pause/pause.svg")
{
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

	connect(pause_btn, &QPushButton::toggled,
			this, &Controller::on_play_pause_toggled);

	connect(next_btn, &QPushButton::clicked, this, &Controller::next);

	connect(prev_btn, &QPushButton::clicked, this, &Controller::prev);

	connect(volume_slider, &QSlider::valueChanged, this, &Controller::change_volume);

	connect(add_volume_btn, &QPushButton::clicked, this, &Controller::add_volume);
	connect(reduce_volume_btn, &QPushButton::clicked, this, &Controller::reduce_volume);
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

void Controller::next() const {
	playback.next_track();
}

void Controller::prev() const {
	playback.previous_track();
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