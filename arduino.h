#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
class arduino
{
public:
    arduino();
    void setupSerial();
    void readSerialData();
    /*    bool connect_arduino();
    bool close_arcuino();*/
};

#endif // ARDUINO_H
