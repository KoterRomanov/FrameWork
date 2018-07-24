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

#include <QMessageBox>
QWidget* GamesModule::createWidget( const QString &widgetName )
{
    if( widgetName.isEmpty() )
        return 0;

    QWidget *widget = 0;

    if( "LightGame" == widgetName )
    {
        LightGame *obj = LightGame::getInstance();
        if( obj )
        {
            widget = obj->getWidget();
        }
    }


    return widget;
}

void GamesModule::closeOpenWidget()
{
    LightGame *obj = LightGame::getInstance();
    if( obj )
    {
        obj->closeWidget();
    }
}
