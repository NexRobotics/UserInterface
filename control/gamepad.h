#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QObject>

class Gamepad : public QObject
{
    Q_OBJECT
public:
    explicit Gamepad(QObject *parent = 0);

signals:

public slots:
};

#endif // GAMEPAD_H
