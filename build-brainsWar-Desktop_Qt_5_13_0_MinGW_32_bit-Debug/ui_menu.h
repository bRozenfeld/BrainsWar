/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QLabel *label;
    QPushButton *ClassicGame;
    QPushButton *BransWarGame;
    QPushButton *LoadGame;
    QPushButton *Quit;
    QLabel *label_2;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(850, 750);
        Menu->setMinimumSize(QSize(850, 750));
        Menu->setMaximumSize(QSize(850, 750));
        Menu->setSizeIncrement(QSize(0, 0));
        Menu->setBaseSize(QSize(0, 0));
        Menu->setAutoFillBackground(true);
        label = new QLabel(Menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 850, 750));
        label->setMinimumSize(QSize(850, 750));
        label->setMaximumSize(QSize(850, 750));
        QFont font;
        font.setFamily(QString::fromUtf8("Old English Text MT"));
        font.setPointSize(24);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8("../build-brainsWar-Desktop_Qt_5_13_0_MinGW_32_bit-Debug/images/background3.jpeg")));
        label->setWordWrap(false);
        label->setOpenExternalLinks(false);
        ClassicGame = new QPushButton(Menu);
        ClassicGame->setObjectName(QString::fromUtf8("ClassicGame"));
        ClassicGame->setEnabled(true);
        ClassicGame->setGeometry(QRect(40, 110, 281, 41));
        QPalette palette;
        QBrush brush(QColor(85, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 85, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        ClassicGame->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Papyrus"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        ClassicGame->setFont(font1);
        ClassicGame->setMouseTracking(false);
        ClassicGame->setFocusPolicy(Qt::StrongFocus);
        ClassicGame->setAutoFillBackground(false);
        ClassicGame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-weight:bold;\n"
"	\n"
"	color: rgb(85, 0, 255);\n"
"}"));
        ClassicGame->setCheckable(false);
        ClassicGame->setAutoRepeat(false);
        ClassicGame->setAutoDefault(false);
        ClassicGame->setFlat(true);
        BransWarGame = new QPushButton(Menu);
        BransWarGame->setObjectName(QString::fromUtf8("BransWarGame"));
        BransWarGame->setGeometry(QRect(510, 110, 321, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Papyrus"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        BransWarGame->setFont(font2);
        BransWarGame->setMouseTracking(false);
        BransWarGame->setFocusPolicy(Qt::StrongFocus);
        BransWarGame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-weight:bold;\n"
"	color: rgb(255, 0, 0);\n"
"}"));
        BransWarGame->setCheckable(false);
        BransWarGame->setFlat(true);
        LoadGame = new QPushButton(Menu);
        LoadGame->setObjectName(QString::fromUtf8("LoadGame"));
        LoadGame->setGeometry(QRect(320, 580, 181, 51));
        LoadGame->setFont(font2);
        LoadGame->setMouseTracking(false);
        LoadGame->setFocusPolicy(Qt::StrongFocus);
        LoadGame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-weight:bold;\n"
"	\n"
"color:white;\n"
"}"));
        LoadGame->setCheckable(false);
        LoadGame->setFlat(true);
        Quit = new QPushButton(Menu);
        Quit->setObjectName(QString::fromUtf8("Quit"));
        Quit->setGeometry(QRect(350, 650, 131, 51));
        Quit->setFont(font2);
        Quit->setMouseTracking(false);
        Quit->setFocusPolicy(Qt::StrongFocus);
        Quit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font-weight:bold;\n"
"	\n"
"color:white;\n"
"}"));
        Quit->setCheckable(false);
        Quit->setChecked(false);
        Quit->setFlat(true);
        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 270, 241, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Papyrus"));
        font3.setPointSize(28);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	font:bold;\n"
"	color:white;\n"
"}"));
        label_2->setWordWrap(false);
        label_2->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable);

        retranslateUi(Menu);

        ClassicGame->setDefault(false);


        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "BrainsWar", nullptr));
        label->setText(QString());
        ClassicGame->setText(QCoreApplication::translate("Menu", "New Classic Game", nullptr));
        BransWarGame->setText(QCoreApplication::translate("Menu", "New BrainsWar Game", nullptr));
        LoadGame->setText(QCoreApplication::translate("Menu", "Load Game", nullptr));
        Quit->setText(QCoreApplication::translate("Menu", "Quit", nullptr));
        label_2->setText(QCoreApplication::translate("Menu", "BrainsWar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
