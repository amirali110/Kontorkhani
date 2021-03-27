#include "list.h"
#include "ui_list.h"
#include "second_list.h"
#include "xlsxdocument.h"
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QMessageBox>





list::list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list)
{
    ui->setupUi(this);

    list::setWindowIcon(QIcon(QDir::currentPath()+"/files/NIGClogo.png"));

     list::setWindowTitle("اطلاعات پست امداد");


    ui->comboBox->addItem("گرمسیر");
    ui->comboBox->addItem("سردسیر");

    ui->comboBox_2->addItem("G4");
    ui->comboBox_2->addItem("G6");

    ui->comboBox_3->addItem("شمالی");
    ui->comboBox_3->addItem("جنوبی");

    ui->comboBox_4->addItem("حیاط");
    ui->comboBox_4->addItem("داخل راهرو");

    ui->comboBox_5->addItem("آپارتمان");
    ui->comboBox_5->addItem("ساختمان ویلایی");

    ui->comboBox_6->addItem("دیواری");
    ui->comboBox_6->addItem("مخزنی");

}


list::~list()
{
    delete ui;
}

void list::on_pushButton_2_clicked()
{

    QFile file(QDir::currentPath()+"/files/file.txt");
    file.open(QFile::WriteOnly|QFile::Text);



    if(file.isOpen()!=true){

        QMessageBox * error=new QMessageBox;

        error->setText("خطا در باز کردن فایل");
        error->setButtonText(1,"تایید");
        error->setWindowTitle("خطا");
        error->setWindowIcon(QIcon(QDir::currentPath()+"files/NIGClogo.png"));
        error->show();

    }else{
    QTextStream out(&file);



    QString name=ui->plainTextEdit->toPlainText();
    QString kod_alamak=ui->plainTextEdit_2->toPlainText();

    QString mantaghe=ui->comboBox->currentText();
    QString noE_kontor=ui->comboBox_2->currentText();

    QString noE_sakhteman=ui->comboBox_3->currentText();
    QString nasb_kontor=ui->comboBox_4->currentText();

    QString noE_vahed=ui->comboBox_5->currentText();
    QString zirbana=ui->plainTextEdit_3->toPlainText();

    QString Tedad_bokhari=ui->plainTextEdit_4->toPlainText();
    QString Tedad_shomineh=ui->plainTextEdit_5->toPlainText();

    QString noE_abgarmkon=ui->comboBox_6->currentText();
    QString gonjayesh_abgarmkon=ui->plainTextEdit_6->toPlainText();

    QString digar_vasayel=ui->plainTextEdit_7->toPlainText();

    if(name==NULL||kod_alamak==NULL||mantaghe==NULL||noE_kontor==NULL||noE_sakhteman==NULL||nasb_kontor==NULL||noE_vahed==NULL||zirbana==NULL||Tedad_bokhari==NULL||Tedad_shomineh==NULL||noE_abgarmkon==NULL||gonjayesh_abgarmkon==NULL||digar_vasayel==NULL){

        QMessageBox *warn=new QMessageBox;

        warn->setButtonText(1,"تایید");
        warn->setWindowTitle("خطا");
        warn->setText("لطفا تمامی موارد را وارد کنید.");
        warn->setWindowIcon(QIcon(QDir::currentPath()+"files/NIGClogo.png"));

        warn->show();

    }else{

   file.write(name.toUtf8());
   out<<Qt::endl;

   file.write(kod_alamak.toUtf8());
   out<<Qt::endl;

   file.write(mantaghe.toUtf8());
   out<<Qt::endl;

   file.write(noE_kontor.toUtf8());
   out<<Qt::endl;

   file.write(noE_sakhteman.toUtf8());
   out<<Qt::endl;

   file.write(nasb_kontor.toUtf8());
   out<<Qt::endl;

   file.write(noE_vahed.toUtf8());
   out<<Qt::endl;

   file.write(zirbana.toUtf8());
   out<<Qt::endl;

   file.write(Tedad_bokhari.toUtf8());
   out<<Qt::endl;

   file.write(Tedad_shomineh.toUtf8());
   out<<Qt::endl;

   file.write(noE_abgarmkon.toUtf8());
   out<<Qt::endl;

   file.write(gonjayesh_abgarmkon.toUtf8());
   out<<Qt::endl;

   file.write(digar_vasayel.toUtf8());
   out<<Qt::endl;

    file.close();



    second_list *secondlist=new second_list;

    secondlist->show();

    list::close();



         }
    }

}






