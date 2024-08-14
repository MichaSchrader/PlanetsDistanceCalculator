#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "distancecalculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->dateEdit->setDisplayFormat(QString("dd.MM.yyyy"));
    ui->dateEdit->setDateRange(QDate(0001, 01, 01), QDate(7999, 12, 31));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DistanceCalculator calculator = DistanceCalculator();
    QString firstPlanet = this->ui->comboBox->currentText();
    QString secondPlanet = this->ui->comboBox_2->currentText();
    QDate date = this->ui->dateEdit->date();
    auto distance = calculator.calculateDistance(firstPlanet.toStdString(), secondPlanet.toStdString(), date.toJulianDay());
    QString output = QStringLiteral("The distance between %1 and %2 on %3 is %4 km").arg(firstPlanet,
                                                                                        secondPlanet,
                                                                                        date.toString(),
                                                                                        QString::number(distance));
    this->ui->label->setText(output);

}

