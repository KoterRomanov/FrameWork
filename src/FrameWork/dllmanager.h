#ifndef DLLMANAGER_H
#define DLLMANAGER_H

#include <QMap>
#include <QList>

class BaseModule;

class DllManager
{
public:
    DllManager();
    int type( const QString &dllname );
    BaseModule* module( const int index );//get module point for index

private:
    void loadDll(QString module);
    int count() const;

private:
    QList< BaseModule* >m_PbasemodulesList;//all load module point
    QMap< QString, int >m_basemodulesMap;//all load module name and index
};

#endif // DLLMANAGER_H
