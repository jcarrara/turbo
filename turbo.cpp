#include "turbo.h"
#include <QString>
#include "iostream"
#define WINDOW_X 800
#define WINDOW_Y 500


//Base constructor.
//Initializes a window with a single tab, and a tab incrementer.
turbo::turbo(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(WINDOW_X, WINDOW_Y);

    QAbstractButton *button = new QPushButton(this);
    button->setText("Tab 1");
    button->setCheckable(true);
    button->setGeometry( 0, 0, WINDOW_X/5, 25 );
    tabs = new QButtonGroup(this);
    tabs->addButton(button, 1);
    cur_tabs++;

    newTab = new QPushButton(this);
    newTab->setText("+");
    newTab->setGeometry( WINDOW_X/5, 0, 25, 25);
    QObject::connect(newTab, SIGNAL(clicked()), this, SLOT( buttonClicked()));
}


//Called from newTab connection. Adds new tabs, up to a maximum of 4 tabs.
//TODO: Scale tabs as number increases, allowing for support of a larger number of tabs.
void turbo::buttonClicked()
{
    if( cur_tabs < 4 )
    {
    QAbstractButton *button = new QPushButton(this);
    button->setGeometry( (cur_tabs++)*(WINDOW_X/5), 0, WINDOW_X/5, 25 );
    QString s = "Tab ";
    s.append(QString::number(cur_tabs));
    button->setText(s);
    button->setCheckable(true);

    newTab->setGeometry( cur_tabs*WINDOW_X/5, 0, 25, 25 );

    tabs->addButton(button, cur_tabs);
    button->show();
    }
}
