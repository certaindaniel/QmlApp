#ifndef FLOWCONTROL_H
#define FLOWCONTROL_H
#include <QDebug>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QObject>
#include "qtquick1applicationviewer.h"
#include "databasemanager.h"
#include <QList>


class FlowControl : public QObject
{
    Q_OBJECT
public:
    explicit FlowControl(QObject *parent = 0);
    DatabaseManager databaseManager;
signals:
public slots:
    void loadAddPage(QString name,QString age,QString birthday);
    void loadDeletePage(QString name);
    void loadViewPage();

private:
};

#endif // FLOWCONTROL_H
