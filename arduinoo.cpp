#include "arduinoo.h"

Arduinoo::Arduinoo()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduinoo::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduinoo::getserial()
{
    return serial;
}
int Arduinoo::connect_arduino() {
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }
    qDebug() << "Port Arduino trouvé :" << arduino_port_name;

    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            // ... (autres configurations)
            qDebug() << "Arduino ouvert avec succès sur" << arduino_port_name;
            return 0;
        } else {
            qDebug() << "Échec de l'ouverture du port :" << serial->errorString(); // Debug critique
            return 1;
        }
    }
    return -1;
}

int Arduinoo::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray Arduinoo::read_from_arduino() {
    QByteArray data;
    if(serial->isReadable()) {
        serial->waitForReadyRead(50);  // Attend 50ms pour les données
        data = serial->readAll();
        while(serial->waitForReadyRead(100)) {  // Attend 100ms supplémentaires
            data += serial->readAll();
        }
    }
    qDebug() << "Données brutes complètes:" << data.toHex();
    return data;
}


void Arduinoo::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
