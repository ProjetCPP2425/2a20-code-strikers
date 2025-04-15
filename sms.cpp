#include "sms.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QDebug>

SmsSender::SmsSender(const QString &apiKey, const QString &fromNumber, QObject *parent)
    : QObject(parent),
    m_apiKey(apiKey),
    m_fromNumber(fromNumber),
    m_manager(new QNetworkAccessManager(this))
{
}

SmsSender::~SmsSender()
{
    // Automatic cleanup via Qt's parent-child system
}

void SmsSender::sendSms(const QString &toNumber, const QString &message)
{
    QUrl url("8k383r.api.infobip.com");
    QNetworkRequest request(url);

    request.setRawHeader("Authorization", "App " + m_apiKey.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["from"] = "d451e0c6871e50231fc36066dd501381-697d944a-8b85-458e-bcae-48125a83c1d4";
    json["to"] = "+21626790445";
    json["text"] = message;

    QNetworkReply *reply = m_manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        QByteArray response = reply->readAll();
        qDebug() << "API Response:" << response;

        if (reply->error() == QNetworkReply::NoError) {
            emit smsSent(true);
            qDebug() << "SMS sent successfully!";
        } else {
            QString error = reply->errorString();
            emit smsSent(false, error);
            qDebug() << "SMS Error:" << error;
        }
        reply->deleteLater();
    });
}
