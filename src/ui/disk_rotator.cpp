#include "../../include/ui/disc_rotator.h"

disc_rotator::disc_rotator(RotatingLabel *vinyl, RotatingLabel *cover, QObject *parent)
	: QObject(parent), vinyl(vinyl), cover(cover)
{
	anim = new QVariantAnimation(this);
	anim->setDuration(5000);
	anim->setLoopCount(-1);
	anim->setStartValue(0.0);
	anim->setEndValue(360.0);

	connect(anim, &QVariantAnimation::valueChanged, this,
			[this, vinyl, cover](const QVariant &value) {
				const qreal angle = value.toReal();
				vinyl->setAngle(angle);
				cover->setAngle(angle);
			});
}

void disc_rotator::start() const {
	if (anim->state() != QAbstractAnimation::Running)
		anim->start();
}

void disc_rotator::pause() const {
	if (anim->state() == QAbstractAnimation::Running)
		anim->pause();
}

void disc_rotator::resume() const {
	if (anim->state() == QAbstractAnimation::Paused)
		anim->resume();
}

void disc_rotator::stop() const {
	if (anim->state() != QAbstractAnimation::Stopped)
		anim->stop();
}
