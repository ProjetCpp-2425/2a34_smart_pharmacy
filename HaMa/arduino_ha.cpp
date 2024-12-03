#include "arduino_ha.h"

Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}

int Arduino::connect_arduino()
{
    qDebug() << "Searching for Arduino Uno...";
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Checking port:" << serial_port_info.portName();
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            qDebug() << "Vendor ID:" << QString::number(serial_port_info.vendorIdentifier(), 16);
            qDebug() << "Product ID:" << QString::number(serial_port_info.productIdentifier(), 16);

            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id)
            {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                break;
            }
        }
    }

    qDebug() << "Arduino port name is:" << arduino_port_name;

    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        qDebug() << "Attempting to open port:" << arduino_port_name;
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Port successfully opened.";
            return 0;
        } else {
            qDebug() << "Failed to open port:" << arduino_port_name << serial->errorString();
            return 1;
        }
    } else {
        qDebug() << "Arduino not found.";
        return -1;
    }
}


int Arduino::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable())
    {
        data = serial->readAll(); //récupérer les données reçues
        return data;
    }
}


void Arduino::write_to_arduino( QByteArray d)

{
    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}
