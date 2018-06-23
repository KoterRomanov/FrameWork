#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <QTreeWidget>

class DllManager;

class TreeManager : public QTreeWidget
{
    Q_OBJECT
public:
    TreeManager( DllManager *dllmanager );
    void setup();

private:
    DllManager *m_dllmanager;
};

#endif // TREEMANAGER_H
