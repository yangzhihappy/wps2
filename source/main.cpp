
//user defined
#include "wps_wmainwidget.h"

//system level
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file(":/wps.qss");
    file.open(QFile::ReadOnly);

    if (file.isOpen()) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
		file.close();
    }

	WPS_WMainWidget wps;
	wps.show();

    return app.exec();
}

