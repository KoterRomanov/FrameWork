#ifndef LIGHTGAME_H
#define LIGHTGAME_H

#include <QWidget>

class QTableWidget;
class QPushButton;
class QTableWidgetItem;

class LightGame : public QObject/*: public QWidget*/
{
    Q_OBJECT
private:
    LightGame();

    void initGameWindow();//初始化游戏界面
    void initCellsIcon();//初始化灯图标
    void setItemIcon( QTableWidgetItem *item );

public:
    QWidget* getWidget();
    void closeWidget();
    static LightGame* getInstance();

private:
    QWidget *m_gameWidget;
    static LightGame *m_singleLightGame;


    QTableWidget *m_gameWindow;//游戏界面

    QPushButton *m_startGame;//开始游戏
    QPushButton *m_quit;//退出游戏
    QPushButton *m_reStart;//重玩游戏
    QPushButton *m_setting;//设置

private slots:
    void slotCellClicked(int row, int column );
    void slot_reStart();

};

#endif // LIGHTGAME_H
