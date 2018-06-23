#include "dllmanager.h"
#include <QLibrary>

DllManager::DllManager()
{
    QStringList list;
    list << "Games";
    foreach( QString module, list )
    {
        loadDll( module );
    }
}

void DllManager::loadDll( QString module )
{
    QLibrary dll( module );
    typedef BaseModule* (*DllInterface )();//函数指针
    DllInterface createModule = ( DllInterface )dll.resolve( "createModule" );
    if( createModule )
    {
        BaseModule *pModule = createModule();
        m_PbasemodulesList.append( pModule );
        m_basemodulesMap.insert( module, count() );

    }
}

/*!

*/
int DllManager::type( const QString &dllname )
{
    if( m_basemodulesMap.contains( dllname ) )
        return m_basemodulesMap[dllname];
    else
        return -1;
}

/*!
  This function return pointer of the dll module
*/
BaseModule* DllManager::module( const int index )
{
    if( index > 0 && index <= count() )
        return m_PbasemodulesList.at(index-1);

    return 0;
}

/*!
   This function return amount of dll moudules
*/
int DllManager::count() const
{
    return m_PbasemodulesList.count();
}

