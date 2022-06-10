#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QImage>
#include <QClipboard>
#include <QImage>
#include <QDebug>
#include <QFileDialog>
#include <QDesktopServices>
#include <QKeyEvent>
#include <QUrl>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include "croppingwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCrop_triggered();

    void on_actionSave_triggered();

    void on_actionwebSite_triggered();

private:
    Ui::MainWindow *ui;
    CroppingWindow *croppingWin;
    QClipboard *clipBoard;
    QDoubleSpinBox *spinBoxOpacity;
    QSpinBox *spinBoxQuality;
    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
