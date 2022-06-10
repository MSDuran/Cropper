#ifndef CROPPINGWINDOW_H
#define CROPPINGWINDOW_H

#include <QMainWindow>
#include <QRubberBand>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QScreen>
#include <QPixmap>
#include <QToolTip>
#include <QString>

#include <QDebug>
namespace Ui {
class CroppingWindow;
}

class CroppingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CroppingWindow(QWidget *parent = nullptr);
    ~CroppingWindow();
    const QPixmap &getImg() const;
    void setImg(const QPixmap &newImg);
signals:
    void imgChanged(const QPixmap &newImg);
private:
    Ui::CroppingWindow *ui;
    QRubberBand *rubberBand;
    QScreen *currentScreen;
    QPoint origin;
    QPixmap img;
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // CROPPINGWINDOW_H
