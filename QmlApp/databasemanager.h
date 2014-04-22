#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QDebug>
#include <QtSql>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);

signals:

public slots:
    void addUserData(QString name, QString age, QString birthday);

};

#endif // DATABASEMANAGER_H
