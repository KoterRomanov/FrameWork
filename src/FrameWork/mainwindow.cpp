#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treemanager.h"
#include "dllmanager.h"
#include "../../shared/shared_module.h"
#include <QDockWidget>
#include <QTreeWidget>
#include <QAction>
#include <QMenu>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_fileAct(0),
    ui(new Ui::MainWindow),m_centralWidget(0)
{
    ui->setupUi(this);
    showMaximized();
//    setWindowFlags( windowFlags() & ~Qt::WindowMaximizeButtonHint );//最大化按钮失效
    setWindowIcon( QIcon(":/Image/FrameWork.png") );
    m_dllmanager = new DllManager;
    m_centralWidget = new QMainWindow;
    initDock();
    initMedia();
    setCentralWidget( m_centralWidget );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDock()
{
    m_listDock = new QDockWidget( tr("目录"), this );
    m_listTree = new TreeManager( m_dllmanager );
    m_listDock->setWidget( m_listTree );

    addDockWidget( Qt::LeftDockWidgetArea, m_listDock );

    connect( m_listTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
             this, SLOT(slot_ItemDoubleclicked(QTreeWidgetItem*,int)) );

}

void MainWindow::initMedia()
{
    m_fileAct = menuBar()->addMenu(tr("&File"));

    QAction *quit = new QAction( tr("&Quit"), m_fileAct );
    connect( quit, SIGNAL(triggered(bool)), qApp, SLOT(quit()) );
    m_fileAct->addAction( quit );

    QAction *closeWidget = new QAction( tr("&CloseWidget"), m_fileAct );
    connect( closeWidget, SIGNAL(triggered(bool)), this, SLOT(slot_closeOpenWidget(bool)) );
    m_fileAct->addAction( closeWidget );

}

void MainWindow::slot_ItemDoubleclicked( QTreeWidgetItem *item, int column )
{
    if( !item )
        return;

    QTreeWidgetItem *parent = item->parent();
    if( !parent )
        return;

    QString parentTxt = parent->text(0);
    QString itemTxt = item->text(0);

    if( tr("Games" ) == parentTxt )
    {
        QWidget *centralWidget = 0;
        int moduleIndex = m_dllmanager->type("Games");
        m_currentWidgetIndex= moduleIndex;
        BaseModule *module = m_dllmanager->module(moduleIndex);
        if( tr("LightGame") == itemTxt )
        {
            centralWidget = module->createWidget(itemTxt);

        }

        if( centralWidget )
        {
              m_centralWidget->setCentralWidget( centralWidget );
//            QMainWindow *centrl = new QMainWindow;
//            setCentralWidget( centrl );
        }
    }
}

void MainWindow::slot_closeOpenWidget(bool trigger )
{
    Q_ASSERT( trigger );

    BaseModule *module = m_dllmanager->module(m_currentWidgetIndex);
    if( module )
    {
        module->closeOpenWidget();
    }


}
