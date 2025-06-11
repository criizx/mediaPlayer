//
// Created by rr on 22.05.25.
//

#pragma once
#include <QByteArray>
#include <QImage>
#include <optional>

class music_metadata {
public:
	char * title{};
	char * artist{};

	struct ImageData {
		QByteArray rawData;
		QString mimeType;
		QString description;

		[[nodiscard]] QImage toImage() const {
			QImage img;
			img.loadFromData(rawData, mimeType.toUtf8().constData());
			return img;
		}
	};

	std::optional<ImageData> coverArt;
};

