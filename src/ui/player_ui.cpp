#include "../../include/ui/player_ui.h"

#include "player_logic/music_metadata.h"

player_ui::player_ui(Ui::MainWindow &ui) : ui(ui) {}

void player_ui::setup(QWidget *container) {
	vinyl_rot = new RotatingLabel(container);
	vinyl_rot->setGeometry(ui.vinyl->geometry());
	vinyl_rot->setPixmap(ui.vinyl->pixmap(Qt::ReturnByValue));
	vinyl_rot->setScaledContents(ui.vinyl->hasScaledContents());
	ui.vinyl->hide();

	cover_rot = new RotatingLabel(container);
	cover_rot->setGeometry(ui.albomCover->geometry());
	cover_rot->setPixmap(ui.albomCover->pixmap(Qt::ReturnByValue));
	cover_rot->setScaledContents(ui.albomCover->hasScaledContents());
	ui.albomCover->hide();

	cover_rot->stackUnder(vinyl_rot);
}

RotatingLabel *player_ui::vinyl_label() const {
	return vinyl_rot;
}

RotatingLabel *player_ui::cover_label() const {
	return cover_rot;
}

QPushButton *player_ui::pause_button() const {
	return ui.pause;
}

QPushButton* player_ui::next_button() const {
	return ui.next;
}

QPushButton* player_ui::prev_button() const {
	return ui.prev;
}

QSlider* player_ui::volume_slider() const {
	return ui.sound;
}

QPushButton* player_ui::add_volume() const {
	return ui.plus;
}

QPushButton* player_ui::reduce_volume() const {
	return ui.minus;
}

QPushButton* player_ui::change_path() const {
	return ui.change_path;
}


void player_ui::change_ui(const music_metadata& metadata) const {
	ui.label->setText(QCoreApplication::translate("MainWindow", strlen(metadata.title) == 0 ? "name" : metadata.title, nullptr));
	ui.label_2->setText(QCoreApplication::translate("MainWindow", strlen(metadata.artist) == 0 ? "artist" : metadata.artist, nullptr));
	if (metadata.coverArt) {
		const auto& imageData = *metadata.coverArt;

		if (const QImage img = imageData.toImage(); !img.isNull()) {
			cover_rot->setPixmap(QPixmap::fromImage(img));
		}
	} else {
		cover_rot->setPixmap(QPixmap(QString::fromUtf8(":/albomCover/placeholder.jpg")));
	}
}
