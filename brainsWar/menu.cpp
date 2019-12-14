#include "menu.h"
#include "ui_menu.h"
#include "cell.h"
#include "piece.h"
#include "game.h"
#include "ggame.h"
#include "menu.h"
#include <QtWidgets>
#include <QApplication>
#include <QPushButton>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_ClassicGame_clicked()
{
    Game *g = new Game(1);
    g->displayBoard();
    GGame *gg = new GGame(g);
    gg->show();

    //SendMessage(, WM_CLOSE, 0, NULL);
}

void Menu::on_BransWarGame_clicked()
{
    Game *g = new Game(2);
    g->displayBoard();
    GGame *gg = new GGame(g);
    gg->show();
}

void Menu::on_LoadGame_clicked()
{

}

void Menu::on_Quit_clicked()
{
    exit(0);
}
