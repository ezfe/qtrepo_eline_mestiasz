#ifndef ADDPLAYERWINDOW_H
#define ADDPLAYERWINDOW_H

#include <QWidget>
#include <iostream>

namespace Ui {
class AddPlayerWindow;
}

class AddPlayerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddPlayerWindow(QWidget *parent = 0);
    ~AddPlayerWindow();

    void clearFields();
private slots:
    void on_addPlayerButton_clicked();

private:
    Ui::AddPlayerWindow *ui;
};

#endif // ADDPLAYERWINDOW_H
