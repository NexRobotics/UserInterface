#ifndef PADREADER_H
#define PADREADER_H

#include <iostream>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>
#include <linux/joystick.h>
#include <vector>
#include <unistd.h>
#include <QThread>
#include <QObject>

#define JOYSTICK_DEV "/dev/input/js0"

struct joystick_position {
    float theta, r, x, y;
};

struct joystick_state {
    std::vector<signed short> button;
    std::vector<signed short> axis;
};

class Padreader : public QThread
{
    Q_OBJECT
signals:
    void signal_got_gamepad_info(QStringList info);
    void signal_controller_value_changed(QString type, int number, int value);
    void signal_controller_connection_closed();
public slots:
    void slot_destroy_pad();

  private:
    QStringList info;
    pthread_t thread;
    int joystick_fd;
    js_event *joystick_ev;
    joystick_state *joystick_st;

  protected:
public:
    bool active;
    void run();
    __u32 version;
    __u8 axes;
    __u8 buttons;
    char name[256];

    explicit Padreader(QObject *parent = 0);
    //    cJoystick(QObject *parent);
        ~Padreader();
        static void* loop(void* obj);
        void readEv();
        joystick_position joystickPosition(int n);
            bool buttonPressed(int n);
};

#endif // PADREADER_H
