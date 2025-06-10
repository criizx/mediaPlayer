#include "../../include/ui/player_ui.h"

player_ui::player_ui(Ui::MainWindow &ui) : ui(ui) {}

void player_ui::setup(QWidget *container) {
	vinylRot = new RotatingLabel(container);
	vinylRot->setGeometry(ui.vinyl->geometry());
	vinylRot->setPixmap(ui.vinyl->pixmap(Qt::ReturnByValue));
	vinylRot->setScaledContents(ui.vinyl->hasScaledContents());
	ui.vinyl->hide();

	coverRot = new RotatingLabel(container);
	coverRot->setGeometry(ui.albomCover->geometry());
	coverRot->setPixmap(ui.albomCover->pixmap(Qt::ReturnByValue));
	coverRot->setScaledContents(ui.albomCover->hasScaledContents());
	ui.albomCover->hide();

	coverRot->stackUnder(vinylRot);
}

RotatingLabel *player_ui::vinylLabel() const {
	return vinylRot;
}

RotatingLabel *player_ui::coverLabel() const {
	return coverRot;
}

QPushButton *player_ui::pauseButton() const {
	return ui.pause;
}
