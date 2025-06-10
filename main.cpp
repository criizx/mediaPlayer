#include <QDir>
#include "ui/music_player_window.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	QString musicFolder = QDir::homePath() + "/CLionProjects/mediaPlayer/test_data/music";

	music_player_window w;
	w.show();

	return QApplication::exec();
}
