#include <QApplication>
#include "turbo.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv );

    turbo window;
    window.show();


    return app.exec();
}
