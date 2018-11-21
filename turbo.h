#ifndef TURBO_H
#define TURBO_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>

//Class header for basic window with tab functionality. WIP.
class turbo : public QWidget
{
    Q_OBJECT
public:
    explicit turbo(QWidget *parent = nullptr);
private:
    QButtonGroup *tabs = nullptr;
    QPushButton *newTab = nullptr;
    int cur_tabs = 0;

private slots:
    void buttonClicked();
};

#endif // TURBO_H
