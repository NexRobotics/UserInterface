#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QKeyEvent>
#include "interfaces/socket/server/myserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MyServer Mserver;
//    void keyPressEvent(QKeyEvent *ke) ;

private slots:
    void on_inter_combo_currentTextChanged(const QString &arg1);
    void on_controll_combo_currentTextChanged(const QString &arg1);
    void slot_set_disconnected();
    void slot_set_connected();
    void slot_got_data(const QString&);
signals:
    void signal_send_from_main(const QString&);
protected:
    void keyPressEvent(QKeyEvent* e);

private:
    Ui::MainWindow *ui;
    bool connection;
    void ultrasound_detector_receiver(const QStringList &);
    void set_param_tabor(int , const QString &, const QString &);
    QStringList newdata;
};

#endif // MAINWINDOW_H
