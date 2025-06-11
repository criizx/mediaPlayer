#include <QDir>
#include "./include/controller/controller.h"

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	const QString music_folder = QDir::homePath() + "/CLionProjects/mediaPlayer/test_data/music";
	Controller controller(music_folder);

	controller.show();

	return QApplication::exec();
}
