#include<iostream>
#include "cell.h"
#include "board.h"
#include "game.h"
#include "ggame.h"
#include "menu.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QPushButton>
#include <QtWidgets>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("images/brainwar.ico"));

    Menu menu;
    menu.show();

    return app.exec();

}
