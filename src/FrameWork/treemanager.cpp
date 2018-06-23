#include "treemanager.h"
#include "dllmanager.h"

TreeManager::TreeManager( DllManager *dllmanager )
    :m_dllmanager( dllmanager )
{
    setup();
}

void TreeManager::setup()
{
    clear();//clear all items
    setHeaderHidden( true );//hide header of tree
    setRootIsDecorated( true );//root item show dot line

    unsigned int count = 1;

    int type = m_dllmanager->type( "Games" );
    if( type )
    {
        count  = 1;

        QTreeWidgetItem *parent = new QTreeWidgetItem( this, type );
        parent->setText( 0, "Games" );
        parent->setData( 0, Qt::UserRole, 0 );

        QTreeWidgetItem *child = new QTreeWidgetItem( parent, type );
        child->setText( 0, "LightGame");//Light Game
        child->setData( 0, Qt::UserRole, count );
        count++;
    }
}

