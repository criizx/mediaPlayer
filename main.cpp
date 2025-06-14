#include <QDir>
#include <QStandardPaths>

#include "./include/controller/controller.h"

int main(int argc, char *argv[]) {

	QApplication app(argc, argv);
	const QString music_folder = QDir::homePath() + QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
	Controller controller(music_folder);

	controller.show();

	return QApplication::exec();
}
