#include "../include/music_player_window.h"
#include <QCoreApplication>
#include <QIcon>
#include <QSize>

music_player_window::music_player_window(QWidget *parent)
    : QMainWindow(parent),
      vinylRot(nullptr),
      coverRot(nullptr),
      anim(nullptr)
{
    setFixedSize(480, 650);
    ui.setupUi(this);
    
    QWidget *container = ui.mainwindow;
    
    vinylRot = new RotatingLabel(container);
    vinylRot->setGeometry(ui.vinyl->geometry());
    vinylRot->setPixmap(ui.vinyl->pixmap(Qt::ReturnByValue));
    vinylRot->setScaledContents(ui.vinyl->hasScaledContents());
    ui.vinyl->hide();
    
    coverRot = new RotatingLabel(container);
    coverRot->setGeometry(ui.albomCover->geometry());
    coverRot->setPixmap(ui.albomCover->pixmap(Qt::ReturnByValue));
    coverRot->setScaledContents(ui.albomCover->hasScaledContents());
    ui.albomCover->hide();
    
    coverRot->stackUnder(vinylRot);
    
    anim = new QVariantAnimation(this);
    anim->setDuration(5000);
    anim->setLoopCount(-1);
    anim->setStartValue(0.0);
    anim->setEndValue(360.0);

    connect(anim, &QVariantAnimation::valueChanged, this,
            [this](const QVariant &value) {
                const qreal angle = value.toReal();
                vinylRot->setAngle(angle);
                coverRot->setAngle(angle);
            });
    anim->start();

    ui.label->setText(QCoreApplication::translate("MainWindow", "Я помню", nullptr));
    ui.label_2->setText(QCoreApplication::translate("MainWindow", "artist", nullptr));

    ui.pause->setCheckable(true);
    const QIcon playIcon(":/play/play.svg");
    const QIcon pauseIcon(":/pause/pause.svg");
    ui.pause->setIcon(playIcon);
    ui.pause->setIconSize(QSize(95, 95));

    connect(ui.pause, &QPushButton::toggled, this,
            [this, playIcon, pauseIcon](const bool checked) {
                ui.pause->setIcon(checked ? pauseIcon : playIcon);
                if (checked) anim->pause();
                else         anim->resume();
            });
}
