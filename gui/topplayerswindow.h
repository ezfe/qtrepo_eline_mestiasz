#ifndef TOPPLAYERSWINDOW_H
#define TOPPLAYERSWINDOW_H

#include <QWidget>

namespace Ui {
class TopPlayersWindow;
}

class TopPlayersWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TopPlayersWindow(QWidget *parent = 0);
    ~TopPlayersWindow();

private:
    Ui::TopPlayersWindow *ui;
};

#endif // TOPPLAYERSWINDOW_H
