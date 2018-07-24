#ifndef SHARED_MODULE_H
#define SHARED_MODULE_H

#include <QObject>

//基础模块 虚基类
class BaseModule : public QObject
{
    Q_OBJECT
public:
    BaseModule()=default;
    virtual ~BaseModule(){}

    virtual QWidget* createWidget( const QString &widgetName )=0;
    virtual void closeOpenWidget()=0;
};



#endif//SHARED_MODULE_H
