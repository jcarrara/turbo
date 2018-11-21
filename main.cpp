#include <QApplication>
#include "turbo.h"

//Main function creates an instance of the turbo object for testing through the QApplication.
int main(int argc, char **argv)
{
    QApplication app (argc, argv );

    turbo window;
    window.show();


    return app.exec();
}
