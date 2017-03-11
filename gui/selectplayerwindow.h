#ifndef SelectPlayerWindow_H
#define SelectPlayerWindow_H

#include <QtWidgets>
#include <QWidget>
#include <QGroupBox>
#include <QCloseEvent>

#include "../game_history/playergamehistory.h"
#include "mainwindow.h"

class MainWindow;

namespace Ui {
class SelectPlayerWindow;
}

class SelectPlayerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SelectPlayerWindow(QWidget *parent = 0, PlayerGameHistory* pgh = 0,
                                MainWindow* menu = 0);
    ~SelectPlayerWindow();

    void init_list();

private slots:

    void on_select_clicked();

private:
    Ui::SelectPlayerWindow *ui;

protected:
    MainWindow* menu;
    PlayerGameHistory* pgh;
    QButtonGroup* bgroup;

    void closeEvent(QCloseEvent* event);
};

#endif // SelectPlayerWindow_H
