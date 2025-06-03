#include <QApplication>
#include "include/music_player_window.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	music_player_window w;
	w.show();

	return app.exec();
}
