#ifndef SECOND_LIST_H
#define SECOND_LIST_H

#include <QWidget>

namespace Ui {
class second_list;
}

class second_list : public QWidget
{
    Q_OBJECT

public:
    explicit second_list(QWidget *parent = nullptr);
    ~second_list();

private slots:
    void on_pushButton_clicked();

private:
    Ui::second_list *ui;
};

#endif // SECOND_LIST_H
