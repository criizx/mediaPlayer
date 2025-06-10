#pragma once

#include "RotatingLabel.h"
#include <QVariantAnimation>

class disc_rotator final : public QObject {
	Q_OBJECT

public:
	disc_rotator(RotatingLabel *vinyl, RotatingLabel *cover, QObject *parent = nullptr);
	void start() const;
	void pause() const;
	void resume() const;
	void stop() const;

private:
	RotatingLabel *vinyl;
	RotatingLabel *cover;
	QVariantAnimation *anim;
};
