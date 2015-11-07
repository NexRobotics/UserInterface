#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog_server : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_server(QWidget *parent = 0);
    ~Dialog_server();

signals:
    void sostart();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
