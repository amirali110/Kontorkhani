#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "list.h"
#include "second_list.h"
#include <QDir>
#include <QPixmap>
#include <QFile>
#include "xlsxdocument.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QByteArray>
#include <QJsonDocument>
#include <QMessageBox>
#include <regex>
#include <QApplication>







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   MainWindow::setWindowTitle("صفحه اصلی");

    //pushButton : make new list
    //pushButton_2 : history of lists
    //pushButton_3 : close Button


   QApplication::setWindowIcon(QIcon(QDir::currentPath()+"/files/NIGClogo.png"));

    connect(ui->pushButton_3,SIGNAL(clicked()),SLOT(close()));


    MainWindow::setWindowIcon(QIcon(QDir::currentPath()+"/files/NIGClogo.png"));

    QPixmap *pix=new QPixmap;
    pix->load(QDir::currentPath()+"/files/NIGClogo.png");

    ui->label_3->setPixmap(*pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){

    list * first_list=new list;
    first_list->show();

}




void MainWindow::on_pushButton_4_clicked()
{

    QXlsx::Document excel;



    excel.write("A1","نام منطقه");                            //0|
    excel.write("B1","کد علمک");                             //1|
    excel.write("C1","پیک مصرف");                          //13|
    excel.write("D1","منطقه جغرافیایی");                    //2 |
    excel.write("E1","نوع کنتور");                              //3|
    excel.write("F1","نوع ساختمان");                         //4|
    excel.write("G1","محل نصب کنتور");                      //5|
    excel.write("H1","نوع واحد مسکونی");                   //6|
    excel.write("I1","زیر بنای مفید واحد مسکونی");         //7|
    excel.write("J1","تعداد بخاری گازی");                     //8|
    excel.write("K1","تعداد شومینه");                         //9|
    excel.write("L1","نوع آبگرمکن");                         //10|
    excel.write("M1","گنجایش آبگرمکن");                   //11|
    excel.write("N1","دیگر وسایل");                         //12|



    int rawA=2;
    int rawB=2;
    int rawC=2;
    int rawD=2;
    int rawE=2;
    int rawF=2;
    int rawG=2;
    int rawH=2;
    int rawI=2;
    int rawJ=2;
    int rawK=2;
    int rawL=2;
    int rawM=2;
    int rawN=2;



    QFile readfile(QDir::currentPath()+"/files/file_json.txt");
    readfile.open(QFile::ReadOnly|QFile::Text);



    while(!readfile.atEnd()){

        QString text=readfile.readLine();


        if(text.contains(R"("0":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("0")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawA++;
            excel.write("A"+QString::number(rawA),text);

        }else if(text.contains(R"("1":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("1")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawB++;
            excel.write("B"+QString::number(rawB),text);

        }else if(text.contains(R"("2":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("2")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawD++;
            excel.write("D"+QString::number(rawD),text);

        }else if(text.contains(R"("3":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("3")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawE++;
            excel.write("E"+QString::number(rawE),text);

        }else if(text.contains(R"("4":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("4")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawF++;
            excel.write("F"+QString::number(rawF),text);

        }else if(text.contains(R"("5":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("5")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawG++;
            excel.write("G"+QString::number(rawG),text);

        }else if(text.contains(R"("6":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("6")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawH++;
            excel.write("H"+QString::number(rawH),text);

        }else if(text.contains(R"("7":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("7")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawI++;
            excel.write("I"+QString::number(rawI),text);

        }else if(text.contains(R"("8":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("8")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawJ++;
            excel.write("J"+QString::number(rawJ),text);

        }else if(text.contains(R"("9":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("9")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawK++;
            excel.write("K"+QString::number(rawK),text);

        }else if(text.contains(R"("10":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("10")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawL++;
            excel.write("L"+QString::number(rawL),text);

        }else if(text.contains(R"("11":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("11")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawM++;
            excel.write("M"+QString::number(rawM),text);

        }else if(text.contains(R"("12":)")){

            text.remove(":");
            text.remove("n");
            text.remove(R"(\)");
            text.remove(",");
            text.remove(R"("12")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawN++;
            excel.write("N"+QString::number(rawN),text);

        }else if(text.contains(R"("13":)")){

            text.remove(":");
            text.remove(",");
            text.remove(R"("13")");
            text.remove(R"(")");
            text.remove(R"(")");

            rawC++;
            excel.write("C"+QString::number(rawC),text);

        }

    }

    excel.saveAs("C://Users/"+qgetenv("USERNAME")+"/Desktop/خروجی اکسل.xlsx");          //save file in user desktop

    QMessageBox * mes=new QMessageBox;
    mes->setWindowIcon(QIcon(QDir::currentPath()+"files/NIGClogo.png"));

    if(!readfile.isOpen()){

        mes->setText("خطا در باز کردن فایل");
        mes->setButtonText(1,"تایید");
        mes->setWindowTitle("خطا");

      }else if(readfile.isOpen()==true){

        mes->setText("خروجی اکسل با موفقیت تولید شد.");
        mes->setButtonText(1,"تایید");
        mes->setWindowTitle("عملیات موفق");

    }

    mes->show();

    readfile.close();

}




void MainWindow::on_pushButton_2_clicked()
{

    QMessageBox *mes=new QMessageBox;

    if(QFile::remove(QDir::currentPath()+"/files/file.txt")==true & QFile::remove(QDir::currentPath()+"/files/file_json.txt")==true){

        mes->setText(" تمامی داده ها با موفقیت حذف شد.");

    }else{

        mes->setText("حذف داده ها موفقیت آمیز نبود.");

    }

     mes->show();

}





                                                                           //END!

                                                                        //Hojati     [ 1399/12/12 ]




