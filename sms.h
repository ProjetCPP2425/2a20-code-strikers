#ifndef SMS_H
#define SMS_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>

class SmsSender : public QObject
{
    Q_OBJECT
public:
    explicit SmsSender(const QString &apiKey, const QString &fromNumber, QObject *parent = nullptr);
    ~SmsSender();

    void sendSms(const QString &toNumber, const QString &message);

signals:
    void smsSent(bool success, const QString& error = QString());

private:
    QString m_apiKey;
    QString m_fromNumber;
    QNetworkAccessManager* m_manager;
};

#endif // SMS_H
