/********************************************************************************
** Form generated from reading UI file 'mediaPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYER_H
#define UI_MEDIAPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mainwindow;
    QLabel *vinyl;
    QLabel *albomCover;
    QPushButton *pause;
    QPushButton *next;
    QPushButton *prev;
    QSlider *sound;
    QPushButton *minus;
    QPushButton *plus;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 650);
        MainWindow->setIconSize(QSize(95, 95));
        mainwindow = new QWidget(MainWindow);
        mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
        mainwindow->setAutoFillBackground(false);
        mainwindow->setStyleSheet(QString::fromUtf8("QWidget#mainwindow {\n"
"    background-color: white;\n"
"}\n"
""));
        vinyl = new QLabel(mainwindow);
        vinyl->setObjectName(QString::fromUtf8("vinyl"));
        vinyl->setGeometry(QRect(-320, -300, 721, 711));
        vinyl->setPixmap(QPixmap(QString::fromUtf8(":/vinyl/vinyl.png")));
        vinyl->setScaledContents(true);
        albomCover = new QLabel(mainwindow);
        albomCover->setObjectName(QString::fromUtf8("albomCover"));
        albomCover->setGeometry(QRect(-40, -10, 151, 151));
        albomCover->setPixmap(QPixmap(QString::fromUtf8(":/albomCover/placeholder.jpg")));
        albomCover->setScaledContents(true);
        pause = new QPushButton(mainwindow);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(202, 440, 96, 96));
        pause->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pause/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pause->setIcon(icon);
        pause->setIconSize(QSize(95, 95));
        pause->setCheckable(false);
        pause->setAutoRepeat(false);
        pause->setAutoExclusive(false);
        next = new QPushButton(mainwindow);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(301, 460, 58, 58));
        next->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/next/next.svg"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon1);
        next->setIconSize(QSize(57, 57));
        next->setCheckable(false);
        next->setAutoRepeat(false);
        next->setAutoExclusive(false);
        prev = new QPushButton(mainwindow);
        prev->setObjectName(QString::fromUtf8("prev"));
        prev->setGeometry(QRect(140, 460, 58, 58));
        prev->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/previous/previous.svg"), QSize(), QIcon::Normal, QIcon::Off);
        prev->setIcon(icon2);
        prev->setIconSize(QSize(57, 57));
        prev->setCheckable(false);
        prev->setAutoRepeat(false);
        prev->setAutoExclusive(false);
        sound = new QSlider(mainwindow);
        sound->setObjectName(QString::fromUtf8("sound"));
        sound->setGeometry(QRect(410, 90, 61, 221));
        sound->setContextMenuPolicy(Qt::NoContextMenu);
        sound->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical {\n"
"    background: #D5D5D5;    \n"
"    width: 5px;                  \n"
"    border-radius: 8px;    \n"
"    margin: 0px 1px;         \n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: black;        \n"
" \n"
"    height: 16px;          \n"
"    width: 16px;              \n"
"    margin: -8px -6px;      \n"
"    border-radius: 8px;          \n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"    background: black;\n"
"	border-radius: 8px;         \n"
"}\n"
""));
        sound->setMaximum(100);
        sound->setValue(20);
        sound->setTracking(true);
        sound->setOrientation(Qt::Vertical);
        sound->setInvertedAppearance(false);
        sound->setInvertedControls(false);
        minus = new QPushButton(mainwindow);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setGeometry(QRect(426, 320, 31, 31));
        minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/minus/silenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        minus->setIcon(icon3);
        minus->setIconSize(QSize(24, 24));
        minus->setCheckable(false);
        minus->setAutoRepeat(false);
        minus->setAutoExclusive(false);
        plus = new QPushButton(mainwindow);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setGeometry(QRect(426, 50, 31, 31));
        plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
""));
    	QIcon icon4;
    	icon4.addFile(QString::fromUtf8(":/plus/louder.svg"), QSize(), QIcon::Normal, QIcon::Off);
        plus->setIcon(icon4);
        plus->setIconSize(QSize(24, 24));
        plus->setCheckable(false);
        plus->setAutoRepeat(false);
        plus->setAutoExclusive(false);
        label = new QLabel(mainwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 540, 500, 41));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: black;\n"
"    font: 14pt \"Arial\";\n"
"    font-weight: bold;\n"
"}\n"
""));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(mainwindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 570, 500, 41));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #888888;\n"
"    font: 12pt \"Arial\";\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(mainwindow);
        albomCover->raise();
        pause->raise();
        next->raise();
        vinyl->raise();
        prev->raise();
        sound->raise();
        minus->raise();
        plus->raise();
        label->raise();
        label_2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) const
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        vinyl->setText(QString());
        albomCover->setText(QString());
        pause->setText(QString());
        next->setText(QString());
        prev->setText(QString());
        minus->setText(QString());
        plus->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Я помню", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "artist", nullptr));
    }

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYER_H
