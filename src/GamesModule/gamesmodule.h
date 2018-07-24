#ifndef GAMESMODULE_H
#define GAMESMODULE_H

#include "gamesmodule_global.h"
#include "../../shared/shared_module.h"


class QMainWindow;

extern "C"
{
    GAMESMODULESHARED_EXPORT BaseModule* createModule();
}


class GAMESMODULESHARED_EXPORT GamesModule : public BaseModule
{
    Q_OBJECT
public:
    GamesModule();

    QWidget* createWidget( const QString &widgetName );
    void closeOpenWidget();

private:
    QMainWindow *m_games_window;
};

#endif // GAMESMODULE_H
