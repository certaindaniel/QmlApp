#ifndef FLOWCONTROL_H
#define FLOWCONTROL_H
#include <QDebug>
#include <QDeclarativeView>
#include <QObject>

class FlowControl : public QObject
{
    Q_OBJECT
public:
    explicit FlowControl(QObject *parent = 0);

signals:

public slots:
    void loadAddPage(QString name,QString age,QString birthday);
    void loadDeletePage(QString name);
    void loadViewPage();
};

#endif // FLOWCONTROL_H
