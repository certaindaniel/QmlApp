#include "flowcontrol.h"

FlowControl::FlowControl(QObject *parent) :
    QObject(parent)
{
}

void FlowControl::loadAddPage(QString name,QString age,QString birthday)
{
    qDebug() << "load Add Page";
    qDebug() << name << age << birthday;

    QDeclarativeView *qmlView = new QDeclarativeView;
    // To stop this warning from printing every time,
    // you must set the context properties before loading the source file of your QML
    // (ie. Move the setContextProperty methods before setMainQmlFile method).
    qmlView->rootContext()->setContextProperty("DatabaseManager", &databaseManager);
    qmlView->rootContext()->setContextProperty("showName", name);
    qmlView->rootContext()->setContextProperty("showAge", age);
    qmlView->rootContext()->setContextProperty("showBirthday", birthday);
    qmlView->setSource(QUrl(QLatin1String("qrc:///add.qml")));
    qmlView->connect(qmlView->engine(), SIGNAL(quit()), SLOT(close()));
    qmlView->show();
}

void FlowControl::loadDeletePage(QString name)
{
    qDebug() << "load Delete Page";
    qDebug() << name;
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->rootContext()->setContextProperty("DatabaseManager", &databaseManager);
    qmlView->rootContext()->setContextProperty("FlowControl", this);
    qmlView->rootContext()->setContextProperty("showName", name);
    qmlView->setSource(QUrl(QLatin1String("qrc:///delete.qml")));
    qmlView->connect(qmlView->engine(), SIGNAL(quit()), SLOT(close()));
    qmlView->show();
}

void FlowControl::loadViewPage()
{
    qDebug() << "load View Page";
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->rootContext()->setContextProperty("DatabaseManager", &databaseManager);
    qmlView->rootContext()->setContextProperty("FlowControl", this);
    qmlView->setSource(QUrl(QLatin1String("qrc:///view.qml")));
    qmlView->connect(qmlView->engine(), SIGNAL(quit()), SLOT(close()));
    qmlView->show();
}
