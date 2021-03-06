#include "TestWindow.h"
#include "ui_TestWindow.h"

#include <QPen>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>

class Klasa : public QDialog
{
    public:
        Klasa(QWidget * w) :
            QDialog(w)
        {
            new QLabel("safhusahfuiasifhsuia", this);
        }
};

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene(0, 0, 1000, 1000);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->addEllipse(50, 50, 50, 25, QPen(Qt::red), QBrush(Qt::blue));
    ui->graphicsView->scene()->addEllipse(50, 65, 50, 25, QPen(Qt::red));
    ui->graphicsView->scene()->addLine(50, 50, 50, 25, QPen(Qt::green));
    ui->graphicsView->scene()->addEllipse(50, 65, 50, 25, QPen(Qt::red));

    QPainterPath path;
    path.moveTo(0,0);
    path.lineTo(10,10);
    path.addText(100, 100, QFont("Sans Serif", 100, 50, true), "Some text");
    path.arcMoveTo(200, 200, 100, 100, 50);
    path.cubicTo(500, 500, 300, 300, 100, 100);
    ui->graphicsView->scene()->addPath(path, QPen(Qt::gray, 10, Qt::DashDotLine, Qt::RoundCap, Qt::MiterJoin));
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this, "pracoza inzynieroza", "Testoza pracoza projektoza... www.biedoza.pl");
    Klasa k(this);
    k.setModal(false);
    k.show();
}

void TestWindow::on_pushButton2_clicked()
{
    //QMessageBox::information(this, "pracoza inzynieroza", "Testoza pracoza projektoza... www.biedoza.pl");
    Klasa k(this);
    k.setModal(true);
    k.exec();
}

void TestWindow::on_pushButton3_clicked()
{
    //QMessageBox::information(this, "pracoza inzynieroza", "Testoza pracoza projektoza... www.biedoza.pl");
    Klasa k(this);
    k.setModal(false);
    k.exec();
}

bool TestWindow::event(QEvent *event)
{
    //bool isa = event->isAccepted();
    bool r = QMainWindow::event(event);
    //qDebug() << event->type() << isa << r << event->isAccepted();
    return r;
}

QWidget * TestWindow::edit()
{
    return ui->textEdit;
}
