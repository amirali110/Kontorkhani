#include "second_list.h"
#include "ui_second_list.h"
#include <QFile>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include <algorithm>
#include <vector>
#include <QMainWindow>
#include <QtCharts>
#include <QBarSet>





second_list::second_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::second_list)
{
    ui->setupUi(this);

    second_list::setWindowTitle(" اطلاعات کنتورخوانی");
    second_list::setWindowIcon(QIcon(QDir::currentPath()+"/files/NIGClogo.png"));

}


second_list::~second_list()
{
    delete ui;
}




void second_list::on_pushButton_clicked()
{
    double Day[22];

    Day[0]=ui->plainTextEdit->toPlainText().toDouble();
    Day[1]=ui->plainTextEdit_2->toPlainText().toDouble();

    Day[2]=ui->plainTextEdit_3->toPlainText().toDouble();
    Day[3]=ui->plainTextEdit_4->toPlainText().toDouble();

    Day[4]=ui->plainTextEdit_5->toPlainText().toDouble();
    Day[5]=ui->plainTextEdit_6->toPlainText().toDouble();

    Day[6]=ui->plainTextEdit_7->toPlainText().toDouble();
    Day[7]=ui->plainTextEdit_8->toPlainText().toDouble();

    Day[8]=ui->plainTextEdit_9->toPlainText().toDouble();
    Day[9]=ui->plainTextEdit_10->toPlainText().toDouble();

    Day[10]=ui->plainTextEdit_11->toPlainText().toDouble();
    Day[11]=ui->plainTextEdit_12->toPlainText().toDouble();

    Day[12]=ui->plainTextEdit_13->toPlainText().toDouble();
    Day[13]=ui->plainTextEdit_14->toPlainText().toDouble();

    Day[14]=ui->plainTextEdit_15->toPlainText().toDouble();
    Day[15]=ui->plainTextEdit_16->toPlainText().toDouble();

    Day[16]=ui->plainTextEdit_17->toPlainText().toDouble();
    Day[17]=ui->plainTextEdit_18->toPlainText().toDouble();

    Day[18]=ui->plainTextEdit_19->toPlainText().toDouble();
    Day[19]=ui->plainTextEdit_20->toPlainText().toDouble();

    Day[20]=ui->plainTextEdit_21->toPlainText().toDouble();
    Day[21]=ui->plainTextEdit_22->toPlainText().toDouble();


    if(Day[0]==NULL || Day[1]==NULL ||Day[2] == NULL ||Day[3]==NULL ||Day[4] == NULL ||Day[5]==NULL ||Day[6]==NULL || Day[7] ==NULL || Day[8] ==NULL ||Day[9] ==NULL ||Day[10] ==NULL ||Day[11] ==NULL ||Day[12] ==NULL ||Day[13] ==NULL ||Day[14] ==NULL ||Day[15] ==NULL ||Day[16] ==NULL ||Day[17] ==NULL ||Day[18] ==NULL ||Day[19] ==NULL ||Day[20] ==NULL ||Day[21] ==NULL ){

        QMessageBox * warn=new QMessageBox;
        warn->setText("لطفا تمامی موارد را وارد نمایید.");
        warn->setWindowIconText("خطا");
        warn->setWindowIcon(QIcon(QDir::currentPath()+"/NIGClogo.png"));
        warn->show();

    }else{

/////////////////////////////////////////////////////////////////////////////////////

    double difference[21];

    for(int i=0;i<=20;i++){

         difference[i]=Day[i+1]-Day[i];
    }

    std::vector <double> vect;

    for(double x:difference){
     vect.push_back(x);
    }

     std::sort(vect.begin() , vect.end());            //Sort fields

     ///////////////////////////////////////////////////////////////////////////////////////

     QJsonObject json;
     QFile file(QDir::currentPath()+"/files/file.txt");

     file.open(QFile::ReadOnly|QFile::Text);

     int f=0;
     while(!file.atEnd()){

         QString x=file.readLine();
         json[QString::number(f)] =x ;

         f++;

     }

     json["13"]=QString::number(vect[20]);

     QByteArray arr;
     arr=QJsonDocument(json).toJson();

     QFile file_write(QDir::currentPath()+"/files/file_json.txt");

     file_write.open(QFile::WriteOnly|QFile::Text|QFile::Append);

    file_write.write(arr);




///////////////////////////////////////////////////////////////////////////////////////////////

     QChart *chart = new QChart();
     QBarSeries *seri=new QBarSeries();

     int index=0;

     while(index<=20){

         QBarSet  *setdata=new QBarSet(QString::number(index+1));
         *setdata<<difference[index];
         seri->append(setdata);
         index++;
     }
     chart->addSeries(seri);
     chart->setTitle(" اعداد به مترمکعب میباشد.");


     chart->setAnimationOptions(QChart::SeriesAnimations);

     seri->setBarWidth(1);
     seri->setLabelsAngle(3);


     QStringList categories;
     categories << "کل";
     QBarCategoryAxis *axisX = new QBarCategoryAxis();
     axisX->append(categories);
     chart->addAxis(axisX,Qt::AlignTrailing);
     seri->attachAxis(axisX);



     QPointF *val=new QPointF;

     val->setX(20);

     QGraphicsSimpleTextItem *Text_chart=new QGraphicsSimpleTextItem(chart);
     Text_chart->setPos(*val);


     QValueAxis *axisY = new QValueAxis();
     axisY->setRange(0,5);
     chart->addAxis(axisY, Qt::AlignLeft);
     seri->attachAxis(axisY);


     chart->legend()->setVisible(true);
          chart->legend()->setAlignment(Qt::AlignBottom);

            QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);


             QMainWindow *window=new QMainWindow;
             window->resize(1000, 600);

             window->setCentralWidget(chartView);

             window->show();

 ///////////////////////////////////////////////////////////////////////////////////

 QMessageBox *ms=new QMessageBox ;
 ms->setWindowIcon(QIcon(QDir::currentPath()+"/files/NIGClogo.png"));


 if(file.isOpen()!=true||file_write.isOpen()!=true){

     ms->setText("ثبت اطلاعات ناموق !");

}
 else{

     ms->setText("اطلاعات با موفقیت ثبت شد.");

 }

 ms->show();


 file.close();
 file_write.close();


 second_list::close();

    }


}




