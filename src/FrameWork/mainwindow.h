#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class DllManager;
class QDockWidget;
class TreeManager;
class QTreeWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DllManager *m_dllmanager;
    QDockWidget *m_listDock;//目录停靠窗口
    TreeManager *m_listTree;//目录树


private:
    void initDock();


private slots:
    void slot_ItemDoubleclicked( QTreeWidgetItem *item, int column );
};

#endif // MAINWINDOW_H
