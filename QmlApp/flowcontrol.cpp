#include "flowcontrol.h"

FlowControl::FlowControl(QObject *parent) :
    QObject(parent)
{
}

void FlowControl::loadAddPage(QString name,QString age,QString birthday)
{
    qDebug() << name << age << birthday;

    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl(QLatin1String("qrc:///add.qml")));
    qmlView->show();

}

void FlowControl::loadDeletePage(QString name)
{
    qDebug() << name;
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl(QLatin1String("qrc:///delete.qml")));
    qmlView->show();

}

void FlowControl::loadViewPage()
{
    qDebug() << "View";
    QDeclarativeView *qmlView = new QDeclarativeView;
    qmlView->setSource(QUrl(QLatin1String("qrc:///view.qml")));
    qmlView->show();
}
