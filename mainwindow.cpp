#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Cropper");
    clipBoard = QGuiApplication::clipboard();

    ui->toolBar->setMovable(false);
    ui->actionSave->setEnabled(false);
    ui->actionSave->setToolTip("In order to save, please take a screenshot");

    ui->toolBar->addWidget(new QLabel("Opacity: ",this));
    spinBoxOpacity = new QDoubleSpinBox(this);
    spinBoxOpacity->setRange(0.1,0.9);
    spinBoxOpacity->setSingleStep(0.1);
    spinBoxOpacity->setDecimals(1);
    spinBoxOpacity->setValue(0.2);
    ui->toolBar->addWidget(spinBoxOpacity);

    //add tooltip

    ui->toolBar->addWidget(new QLabel("Quality: ",this));
    spinBoxQuality = new QSpinBox(this);
    spinBoxQuality->setRange(0,100);
    spinBoxQuality->setSingleStep(1);
    spinBoxQuality->setValue(25);
    ui->toolBar->addWidget(spinBoxQuality);

    //add tooltip

    setCentralWidget(ui->imageLabel);
    croppingWin = new CroppingWindow(this);

    connect(croppingWin,&CroppingWindow::imgChanged,[&](const QPixmap &newImg){
        ui->imageLabel->setPixmap(newImg);
        this->show();
        croppingWin->setVisible(false);
        ui->actionSave->setEnabled(true);
        ui->actionSave->setToolTip("Save");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCrop_triggered()
{
    this->hide();
    croppingWin->showFullScreen();
    croppingWin->setWindowOpacity(spinBoxOpacity->value());
    croppingWin->show();
}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(this,"Choose a path to save the image",QDir::currentPath(),                                                "PNG (*.png);;BMP (*.bmp);;CUR (*.cur);;GIF (*.gif);;ICNS (*.icns);;ICO (*.ico);;JPEG (*.jpeg);;JPG (*.jpg);;PBM (*.pbm);;PGM (*.pgm);;PPM (*.ppm);;SVG (*.svg);;SVGZ (*.svgz);;TGA (*.tga);;TIF (*.tif);;TIFF (*.tiff);;WBMP (*.wbmp);;WEBP (*.webp);;XBM (*.xbm);;XPM (*.xpm)");
    qDebug()<<path;
    ui->imageLabel->pixmap().save(path, nullptr, spinBoxQuality->value());
}

void MainWindow::on_actionwebSite_triggered()
{
    QDesktopServices::openUrl(QUrl(QGuiApplication::organizationDomain()));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    event->accept();
    if(!ui->imageLabel->pixmap().isNull() && event->matches(QKeySequence::Copy)){
        clipBoard->setPixmap(ui->imageLabel->pixmap());
    }
}

