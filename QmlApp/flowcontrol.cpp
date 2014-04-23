#include "flowcontrol.h"

FlowControl::FlowControl(QObject *parent) :
    QObject(parent)
{
}

void FlowControl::loadAddPage(QString name,QString age,QString birthday)
{
    qDebug() << "loadAddPage";
    qDebug() << name << age << birthday;

    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl(QLatin1String("qrc:///add.qml")));
    qmlView->rootContext()->setContextProperty("DatabaseManager", &databaseManager);
    qmlView->show();
}

void FlowControl::loadDeletePage(QString name)
{
    qDebug() << "loadDeletePage";
    qDebug() << name;
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl(QLatin1String("qrc:///delete.qml")));
    qmlView->show();
}

void FlowControl::loadViewPage()
{
    qDebug() << "loadViewPage";
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl(QLatin1String("qrc:///view.qml")));
    qmlView->rootContext()->setContextProperty("DatabaseManager", &databaseManager);
    qmlView->show();
}
