#ifndef TURBO_H
#define TURBO_H

#include <QWidget>
#include <QPushButton>

class turbo : public QWidget
{
    Q_OBJECT
public:
    explicit turbo(QWidget *parent = nullptr);
private:
    QPushButton *button;
    bool clicked = false;

private slots:
    void buttonClicked();
};

#endif // TURBO_H
