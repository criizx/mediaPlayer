#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/mpegfile.h>
#include <taglib/id3v2tag.h>
#include <taglib/id3v2frame.h>
#include <taglib/attachedpictureframe.h>

#include "../../include/player_logic/music_metadata.h"
#include "../../include/player_logic/metadata_parser.h"

#include <qfileinfo.h>

music_metadata metadata_parser::parse(const QString& filepath) {

	music_metadata metadata;

	if (const QFileInfo fileInfo(filepath); !fileInfo.isFile()) {
		metadata.flag = false;
		return metadata;
	}

	if (const TagLib::FileRef ref(filepath.toUtf8().constData()); !ref.isNull() && ref.tag()) {
		const auto* tag = ref.tag();
		metadata.flag = true;
		metadata.title = strdup(tag->title().toCString(true));
		metadata.artist = strdup(tag->artist().toCString(true));
	}

	if (TagLib::MPEG::File file(filepath.toUtf8().constData()); file.isValid()) {
		if (const auto* id3v2 = file.ID3v2Tag()) {
			if (auto frames = id3v2->frameListMap()["APIC"]; !frames.isEmpty()) {
				if (const auto* apic = dynamic_cast<TagLib::ID3v2::AttachedPictureFrame*>(frames.front())) {
					music_metadata::ImageData img;
					img.rawData = QByteArray(apic->picture().data(), apic->picture().size());
					img.mimeType = QString::fromStdString(apic->mimeType().to8Bit(true));
					img.description = QString::fromStdWString(apic->description().toWString());
					metadata.coverArt = img;
				}
			}
		}
	}

	return metadata;
}