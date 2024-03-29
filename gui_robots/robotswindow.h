#ifndef ROBOTSWINDOW_H
#define ROBOTSWINDOW_H

#include <QWidget>
#include "../engines/engine.h"
#include "../engines/robots.h"

namespace Ui {
class RobotsWindow;
}

class RobotsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RobotsWindow(QWidget *parent = 0);
    ~RobotsWindow();

    void handle_event(char cmd);

private slots:
    void on_yButton_clicked();

    void on_kButton_clicked();

    void on_uButton_clicked();

    void on_hButton_clicked();

    void on_lButton_clicked();

    void on_bButton_clicked();

    void on_jButton_clicked();

    void on_nButton_clicked();

    void on_wButton_clicked();

    void on_tButton_clicked();

    void on_qButton_clicked();

    void on_rButton_clicked();

private:
    Ui::RobotsWindow *ui;
    Engine * engine;
    void refresh_gameboard();
};

#endif // ROBOTSWINDOW_H
