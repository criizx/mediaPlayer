//
// Created by rr on 22.05.25.
//

#pragma once
#include <QByteArray>
#include <QImage>
#include <optional>

class music_metadata {
public:
	QString title;
	QString artist;

	struct ImageData {
		QByteArray rawData;
		QString mimeType;
		QString description;

		QImage toImage() const {
			QImage img;
			img.loadFromData(rawData, mimeType.toUtf8().constData());
			return img;
		}
	};

	std::optional<ImageData> coverArt;

	void debugPrint() const;
};

