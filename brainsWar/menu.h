#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtWidgets/QPushButton>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
private slots:
    void on_ClassicGame_clicked();

    void on_BransWarGame_clicked();

    void on_LoadGame_clicked();

    void on_Quit_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H

