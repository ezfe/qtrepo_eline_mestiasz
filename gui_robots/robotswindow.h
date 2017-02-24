#ifndef ROBOTSWINDOW_H
#define ROBOTSWINDOW_H

#include <QMainWindow>

namespace Ui {
class RobotsWindow;
}

class RobotsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobotsWindow(QWidget *parent = 0);
    ~RobotsWindow();

private:
    Ui::RobotsWindow *ui;
};

#endif // ROBOTSWINDOW_H
