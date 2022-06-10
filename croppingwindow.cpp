#include "croppingwindow.h"
#include "ui_croppingwindow.h"

CroppingWindow::CroppingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CroppingWindow)
{
    ui->setupUi(this);
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    currentScreen = QGuiApplication::primaryScreen();
}

CroppingWindow::~CroppingWindow()
{
    delete ui;
    delete currentScreen;
}

const QPixmap &CroppingWindow::getImg() const
{
    return img;
}

void CroppingWindow::setImg(const QPixmap &newImg)
{
    img = newImg;
}

void CroppingWindow::mousePressEvent(QMouseEvent *event)
{
    origin = event->pos();
    rubberBand->setGeometry(QRect(origin, QSize()));
    rubberBand->show();
}
void CroppingWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::setWindowOpacity(0);
    QPixmap pix = currentScreen->grabWindow(0,rubberBand->geometry().x(),rubberBand->geometry().y(),rubberBand->width(),rubberBand->height());
    rubberBand->hide();
    //this->setVisible(false);
    emit imgChanged(pix);
}

void CroppingWindow::mouseMoveEvent(QMouseEvent *event)
{
    QToolTip::showText(event->globalPosition().toPoint(),QString::number(rubberBand->size().width())+","+QString::number(rubberBand->size().height()));
    rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
}

void CroppingWindow::keyPressEvent(QKeyEvent *event)
{
    event->accept();
    if(event->key() == Qt::Key::Key_Escape){
        setImg(QPixmap());
        //this->setVisible(false);
    }
}

