#ifndef ADDPLAYERWINDOW_H
#define ADDPLAYERWINDOW_H

#include <QWidget>

namespace Ui {
class AddPlayerWindow;
}

class AddPlayerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddPlayerWindow(QWidget *parent = 0);
    ~AddPlayerWindow();

private:
    Ui::AddPlayerWindow *ui;
};

#endif // ADDPLAYERWINDOW_H
