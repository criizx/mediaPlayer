//
// Created by rr on 02.06.25.
//
#include "../include/metadata_parser.h"
#include <QDebug>
#include <QCoreApplication>

int main(int argc, char* argv[]) {
	QCoreApplication app(argc, argv);

	metadata_parser parser;
	const music_metadata metadata = parser.parse("../source/tagmp3_test.mp3");

	qDebug() << "Title:" << metadata.title;
	qDebug() << "Artist:" << metadata.artist;

	if (metadata.coverArt) {
		qDebug() << "Cover art mime:" << metadata.coverArt->mimeType;
		metadata.coverArt->toImage().save("cover_output.jpg");
	} else {
		qDebug() << "No cover art found.";
	}

	return 0;
}
