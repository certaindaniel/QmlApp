//ref: http://www.java2s.com/Code/Cpp/Qt/ConnecttoSqliteanddoinsertdeleteupdateandselect.htm

#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) :
    QObject(parent)
{
}

void DatabaseManager::addUserData(QString name,QString age,QString birthday)
{
    qDebug() << "addUserData";
    qDebug() << name << age << birthday;

    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "userinfo.db" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }
    else
    {
        qDebug( "Connected!" );
        QSqlQuery qry;
        qry.prepare( "CREATE TABLE IF NOT EXISTS userinfo (name VARCHAR(20) UNIQUE PRIMARY KEY, age int, birthday DATE)" );
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        else
        {
            qDebug() << "Table created!";
        }

        qry.prepare( "INSERT INTO userinfo (name, age, birthday) VALUES (:name, :age, :birthday)" );
        qry.bindValue(":name", name);
        qry.bindValue(":age", age);
        qry.bindValue(":birthday", birthday);

        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        else
        {
            qDebug( "Inserted!" );
        }
        qry.finish();
    }
    db.close();
}
QStringList DatabaseManager::dataModel()
{
    QStringList list;

    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "userinfo.db" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }
    else
    {
        qDebug( "Connected!" );
        QSqlQuery qry;
        qry.prepare( "CREATE TABLE IF NOT EXISTS userinfo (name VARCHAR(20) UNIQUE PRIMARY KEY, age int, birthday DATE)" );
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        else
        {
            qDebug() << "Table created!";
        }

        qry.prepare( "SELECT * FROM userinfo" );
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        else
        {
            qDebug( "Selected!" );
            QSqlRecord rec = qry.record();
            int cols = rec.count();

            for( int r=0; qry.next(); r++ )
            {
                for( int c=0; c<cols; c++ )
                {
                    qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
                }

                list.append(qry.value(0).toString());
            }
        }
        qry.finish();
    }
    db.close();

    return list;
}

void DatabaseManager::findUserData(QString name)
{
    QString age;
    QString birthday;

    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "userinfo.db" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }
    else
    {
        qDebug( "Connected!" );
        QString queryString = "SELECT * FROM userinfo where name = '" + name + "'";
        QSqlQuery qry;
        qry.prepare( queryString );
        if( !qry.exec() )
        {
            qDebug() << qry.lastError();
        }
        else
        {
            qDebug( "Selected!" );
            QSqlRecord rec = qry.record();
            int cols = rec.count();

            for( int r=0; qry.next(); r++ )
            {
                for( int c=0; c<cols; c++ )
                {
                    qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
                }
                age = qry.value(1).toString();
                birthday = qry.value(2).toString();
            }
        }
        qry.finish();
    }
    db.close();

    qDebug() << "loadAddPage";
    qDebug() << name << age << birthday;

    QDeclarativeView *qmlView = new QDeclarativeView;
    // To stop this warning from printing every time,
    // you must set the context properties before loading the source file of your QML
    // (ie. Move the setContextProperty methods before setMainQmlFile method).
    qmlView->rootContext()->setContextProperty("DatabaseManager", this);
    qmlView->rootContext()->setContextProperty("showName", name);
    qmlView->rootContext()->setContextProperty("showAge", age);
    qmlView->rootContext()->setContextProperty("showBirthday", birthday);
    qmlView->setSource(QUrl(QLatin1String("qrc:///add.qml")));
    qmlView->show();

}
