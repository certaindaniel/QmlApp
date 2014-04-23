#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QDebug>
#include <QtSql>
#include <QDeclarativeContext>
#include <QDeclarativeView>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);
    Q_INVOKABLE QStringList dataModel();
signals:

public slots:
    void addUserData(QString name, QString age, QString birthday);
    void findUserData(QString name);
};

#endif // DATABASEMANAGER_H
