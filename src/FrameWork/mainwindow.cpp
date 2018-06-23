#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treemanager.h"
#include "dllmanager.h"
#include "../../shared/shared_module.h"
#include <QDockWidget>
#include <QTreeWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();
//    setWindowFlags( windowFlags() & ~Qt::WindowMaximizeButtonHint );//最大化按钮失效
    setWindowIcon( QIcon(":/Image/FrameWork.png") );
    m_dllmanager = new DllManager;
    initDock();

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
        BaseModule *module = m_dllmanager->module(moduleIndex);
        if( tr("LightGame") == itemTxt )
        {
            centralWidget = module->createWidget(itemTxt);

        }

        centralWidget->setStyleSheet("background:red");
        setCentralWidget( centralWidget );
    }
}
