#include "sms.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QDebug>
#include <QJsonArray>
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
    // 1. Configuration de l'URL
    QUrl url("https://8k383r.api.infobip.com/sms/2/text/advanced");
    QNetworkRequest request(url);

    // 2. Authentification
    QString apiKey = "d451e0c6871e50231fc36066dd501381-697d944a-8b85-458e-bcae-48125a83c1d4";
    request.setRawHeader("Authorization", "App " + apiKey.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Accept", "application/json");

    // 3. Construction du payload correct
    QJsonObject destination;
    destination["to"] = "+216" + toNumber; // Ajout de l'indicatif Tunisie

    QJsonObject messageObj;
    messageObj["from"] = "+447491163443"; // Votre numéro UK
    messageObj["destinations"] = QJsonArray({destination});
    messageObj["text"] = message;

    QJsonObject root;
    root["messages"] = QJsonArray({messageObj});

    // Debug avant envoi
    qDebug() << "Envoi SMS à:" << "+216" + toNumber;
    qDebug() << "Payload:" << QJsonDocument(root).toJson();

    // 4. Envoi de la requête
    QNetworkReply *reply = m_manager->post(request, QJsonDocument(root).toJson());

    // 5. Gestion de la réponse
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            qDebug() << "Réponse API:" << response;
            emit smsSent(true);
        } else {
            QString error = QString("Erreur %1: %2")
            .arg(reply->error())
                .arg(reply->errorString());
            qDebug() << "Erreur d'envoi:" << error;
            emit smsSent(false, error);
        }
        reply->deleteLater();
    });
}
