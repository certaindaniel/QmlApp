#include "flowcontrol.h"
#include "qtquick1applicationviewer.h"
#include <QApplication>
#include <QDeclarativeContext>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FlowControl flowControl;

    QtQuick1ApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QtQuick1ApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qrc:///main.qml"));
    viewer.rootContext()->setContextProperty("FlowControl", &flowControl);
    viewer.showExpanded();

    return app.exec();
}
