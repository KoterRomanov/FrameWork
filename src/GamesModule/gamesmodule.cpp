#include "gamesmodule.h"
#include "lightgame.h"
#include <QDebug>
#include <QMainWindow>

BaseModule* createModule()
{
    return new GamesModule;
}


GamesModule::GamesModule()
{
    m_games_window = new QMainWindow;
}

QWidget* GamesModule::createWidget( const QString &widgetName )
{
    if( widgetName.isEmpty() )
        return 0;

    QWidget *widget = 0;

    if( "LightGame" == widgetName )
    {
        widget = new QWidget;
    }


    return widget;
}
