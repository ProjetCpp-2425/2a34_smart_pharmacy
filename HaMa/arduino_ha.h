#ifndef ARDUINO_HA_H
#define ARDUINO_HA_H

#include <QWidget>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Arduino
{
public:
    // Méthodes de la classe Arduino
    Arduino();
    int connect_arduino();      // Permet de connecter le PC à Arduino
    int close_arduino();        // Permet de fermer la connexion
    void write_to_arduino(QByteArray d); // Envoyer des données vers Arduino
    QByteArray read_from_arduino();    // Recevoir des données de la carte Arduino
    QSerialPort* getserial();         // Accesseur
    QString getarduino_port_name();

private:
    QSerialPort* serial;              // Cet objet rassemble des informations
        // et des fonctions (envoi, lecture de réception, etc.)
        // sur ce qu'est une voie série pour Arduino.
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_producy_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;                  // Contenant les données lues à partir d'Arduino
};

#endif // ARDUINO_HA_H
