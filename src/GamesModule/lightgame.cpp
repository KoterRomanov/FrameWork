#include "lightgame.h"

#include <QMessageBox>
#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QDebug>
#include <QTableWidgetItem>

/*!
  静态变量内外初始化
*/
LightGame* LightGame::m_singleLightGame = NULL;

LightGame::LightGame()
    :m_gameWidget(0)
{
}

/*!
  单例模式：获取对象指针
*/
LightGame* LightGame::getInstance()
{
    if( !m_singleLightGame )
    {
        m_singleLightGame = new LightGame();
    }

    return m_singleLightGame;
}


QWidget* LightGame::getWidget()
{
    if( !m_gameWidget )
    {
        m_gameWidget = new QWidget;
        initGameWindow();
//        m_gameWidget->setStyleSheet("background:gray");

        return m_gameWidget;
    }

    return 0;
}

void LightGame::closeWidget()
{
    if( m_gameWidget )
    {
        m_gameWidget->close();
        delete m_gameWidget;
        m_gameWidget = 0;
    }
}

void LightGame::initGameWindow()
{
    if( !m_gameWidget )
        return;

    m_startGame = new QPushButton( tr("Start") );

    m_quit = new QPushButton( tr("Quit") );

    m_reStart = new QPushButton( tr("Restart") );
    connect( m_reStart, SIGNAL(clicked()), this, SLOT(slot_reStart()) );

    m_setting = new QPushButton( tr("Setting") );

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget( m_startGame );
    buttonLayout->addWidget( m_quit );
    buttonLayout->addWidget( m_reStart );
    buttonLayout->addWidget( m_setting );

    m_gameWindow = new QTableWidget( 10, 10 );
    m_gameWindow->verticalHeader()->hide();//隐藏垂直表头
    m_gameWindow->horizontalHeader()->hide();//隐藏水平表头
    m_gameWindow->setEditTriggers( QAbstractItemView::NoEditTriggers );//设置单元格不可编辑
    m_gameWindow->setSelectionMode( QAbstractItemView::NoSelection );//设置单元格不可选中
    m_gameWindow->setShowGrid( false );
    m_gameWindow->setIconSize( QSize(72, 72) );
    m_gameWindow->setFocusPolicy( Qt::NoFocus );
    connect( m_gameWindow, SIGNAL(cellClicked(int,int)), this, SLOT( slotCellClicked(int,int) ) );
    initCellsIcon();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout( buttonLayout );
    mainLayout->addWidget( m_gameWindow );

    m_gameWidget->setLayout( mainLayout );

}

void LightGame::initCellsIcon()
{
    if( !m_gameWindow )
        return;

    int rows = m_gameWindow->rowCount();
    int columns = m_gameWindow->columnCount();

    for( int r = 0; r < rows; r++ )
    {
        m_gameWindow->setRowHeight( r, 72 );
        //行
        for( int c = 0; c < columns; c++ )
        {
            m_gameWindow->setColumnWidth( c, 72 );
            //列
            QTableWidgetItem *cell = new QTableWidgetItem();
//            cell->setIcon( QIcon( ":/image/Disney_smile.png" ) );
            cell->setIcon( QIcon(":/image/lightsOff.png"));
            m_gameWindow->setItem( r, c, cell );
        }
    }
}

void LightGame::slotCellClicked(int row, int column)
{
//    qDebug() << "cell( " + QString::number(row) + ", " + QString::number(column) + " )";

    QTableWidgetItem *item = m_gameWindow->item( row, column );
    if( item )
    {
        //中
        setItemIcon( item );

        //上
        QTableWidgetItem *upItem = m_gameWindow->item( row-1, column );
        if( upItem )
            setItemIcon( upItem );

        //下
        QTableWidgetItem *downItem = m_gameWindow->item( row+1, column );
        if( downItem )
            setItemIcon( downItem );

        //左
        QTableWidgetItem *leftItem = m_gameWindow->item( row, column-1 );
        if( leftItem )
            setItemIcon( leftItem );

        //右
        QTableWidgetItem *rightItem = m_gameWindow->item( row, column+1 );
        if( rightItem )
            setItemIcon( rightItem );
    }
}

void LightGame::setItemIcon( QTableWidgetItem *item )
{
    if( !item )
        return;

    if( item->data(Qt::UserRole).toInt() == 0 )
    {
        item->setData( Qt::UserRole, 1 );
//        item->setIcon( QIcon(":/image/Disney_kiss.png") );
        item->setIcon( QIcon(":/image/lightsOn.png") );
    }
    else if( item->data(Qt::UserRole).toInt() == 1 )
    {
        item->setData( Qt::UserRole, 0 );
//        item->setIcon( QIcon(":/image/Disney_smile.png") );
        item->setIcon( QIcon(":/image/lightsOff.png"));
    }
}

void LightGame::slot_reStart()
{
    initCellsIcon();
}
