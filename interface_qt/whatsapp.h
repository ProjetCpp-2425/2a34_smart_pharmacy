#ifndef WHATSAPP_H
#define WHATSAPP_H
#include "QString"

class whatsapp
{
public:
    whatsapp();
    // Function to send a WhatsApp message
    void sendWhatsApp(const QString &to, const QString &message);
};

#endif // WHATSAPP_H
