#pragma once

#include <QLabel>
#include <QVariantAnimation>
#include <QPainter>
#include <cmath>
#include <QPaintEvent>

class RotatingLabel final : public QLabel {
    Q_OBJECT

public:
    explicit RotatingLabel(QWidget *parent = nullptr)
        : QLabel(parent),
          _anim(new QVariantAnimation(this))
    {
        _anim->setDuration(5000);
        _anim->setLoopCount(-1);
        _anim->setStartValue(0.0);
        _anim->setEndValue(360.0);

        connect(_anim, &QVariantAnimation::valueChanged,
                this, [this](const QVariant &value) {
                    _angle = value.toReal();
                    update();
                });

        connect(_anim, &QVariantAnimation::finished,
                this, [this]() {
                    _angle = std::fmod(_angle, 360.0);
                });
    }

    void start() const {
        if (_anim->state() == QAbstractAnimation::Paused) {
            _anim->resume();
        } else {
            _anim->stop();
            _anim->setStartValue(_angle);
            _anim->setEndValue(_angle + 360.0);
            _anim->start();
        }
    }

    void pause() const {
        if (_anim->state() == QAbstractAnimation::Running) {
            _anim->pause();
        }
    }

    void stop() {
        if (_anim->state() != QAbstractAnimation::Stopped) {
            _anim->stop();
            _angle = 0;
            update();
        }
    }

    bool isRunning() const {
        return _anim->state() == QAbstractAnimation::Running;
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        const QPixmap src = pixmap(Qt::ReturnByValue);
        if (src.isNull()) {
            QLabel::paintEvent(event);
            return;
        }

        QPainter p(this);
        p.setRenderHint(QPainter::SmoothPixmapTransform);

        p.translate(width() / 2.0, height() / 2.0);
        p.rotate(_angle);

        const QSizeF srcSize = src.size();
        const qreal scale = std::min(width() / srcSize.width(),
                                     height() / srcSize.height());
        p.scale(scale, scale);

        p.drawPixmap(QPointF(-srcSize.width() / 2, -srcSize.height() / 2), src);
    }

private:
    QVariantAnimation *_anim;
    qreal _angle = 0.0;
};
