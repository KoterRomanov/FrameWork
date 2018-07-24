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
    void initMedia();


private slots:
    void slot_ItemDoubleclicked( QTreeWidgetItem *item, int column );
    void slot_closeOpenWidget(bool);

private:
    QMenu *m_fileAct;//文件菜单
    int m_currentWidgetIndex;//当前打开模块的Id
    QMainWindow *m_centralWidget;
};

#endif // MAINWINDOW_H
