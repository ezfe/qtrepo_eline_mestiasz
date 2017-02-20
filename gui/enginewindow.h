#ifndef ENGINEWINDOW_H
#define ENGINEWINDOW_H

#include <QWidget>

namespace Ui {
class EngineWindow;
}

class EngineWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EngineWindow(QWidget *parent = 0);
    ~EngineWindow();

private:
    Ui::EngineWindow *ui;
};

#endif // ENGINEWINDOW_H
