#include "turbo.h"

turbo::turbo(QWidget *parent) : QWidget(parent)
{
    setFixedSize( 150, 100 );
    button = new QPushButton("Before", this);
    button->setGeometry( 10, 10, 130, 80 );
    button->setChecked(true);
    QObject::connect(button, SIGNAL (clicked()), this, SLOT (buttonClicked()));
}

void turbo::buttonClicked()
{
    if( !clicked )
        button->setText("After");
    else
        button->setText("Before");

    clicked = !clicked;
}
