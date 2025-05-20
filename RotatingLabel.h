#pragma once
#include <QLabel>
#include <QVariantAnimation>
#include <QPainter>
#include <QPaintEvent>

class RotatingLabel : public QLabel {
	Q_OBJECT
public:
	explicit RotatingLabel(QWidget *parent = nullptr)
		: QLabel(parent),
		  _anim(new QVariantAnimation(this))
	{
		connect(_anim, &QVariantAnimation::valueChanged,
				this, [this](const QVariant &v){
					_angle = v.toReal();
					update();
				});
		_anim->setStartValue(0);
		_anim->setEndValue(360);
		_anim->setDuration(5000);
		_anim->setLoopCount(-1);
	}

	void start() { _anim->start(); }
	void stop()  { _anim->stop();  }
	bool isRunning() const { return _anim->state() == QAbstractAnimation::Running; }

protected:
	void paintEvent(QPaintEvent *ev) override {
		if (pixmap() && !pixmap()->isNull()) {
			QPainter p(this);
			p.setRenderHint(QPainter::SmoothPixmapTransform);
			p.translate(width()/2.0, height()/2.0);
			p.rotate(_angle);
			QSizeF s = pixmap()->size();
			p.drawPixmap(QPointF(-s.width()/2, -s.height()/2), *pixmap());
		} else {
			QLabel::paintEvent(ev);
		}
	}

private:
	QVariantAnimation *_anim;
	qreal _angle = 0;
};
