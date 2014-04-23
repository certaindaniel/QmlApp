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
    }
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
    }
    return list;
}
