#ifndef DATACRUDAPI_H
#define DATACRUDAPI_H

#include <QtGlobal>
#include <QtHttpServer/QHttpServer>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QSqlDatabase>
#include <optional>
#include <QSqlQuery>
#include <QJsonObject>
#include <QSqlError>
#include <QDateTime>
#include <QJsonDocument>
class DataCrudApi
{
public:
    DataCrudApi(QSqlDatabase *db) : db(db)
    {
        query = new QSqlQuery(*db);
    }

    QHttpServerResponse getItem(qint64 itemId) const
    {
        query->prepare("SELECT * FROM mydb.Data WHERE id = :id");
        query->bindValue(":id", itemId);
        if (query->exec() && query->next()) {
            QJsonObject res;
            QJsonObject row{
                {QString("id"), query->value(0).toJsonValue()},
                {QString("size"), query->value(1).toJsonValue()},
                {QString("format"), query->value(2).toJsonValue()},
                {QString("name"), query->value(3).toJsonValue()},
                {QString("updatedAt"), query->value(4).toDateTime().toString("yyyy-MM-dd hh:mm:ss")}
            };
            res.insert(QString("%1").arg(query->value(0).toInt()), row);
            return QHttpServerResponse(res.empty() ?
                                           QVariant("No data").toJsonObject()
                                                   : res
                                       , QHttpServerResponder::StatusCode::Ok);
        }
        return QHttpServerResponse("", QHttpServerResponder::StatusCode::NotFound);

    }
    QHttpServerResponse getAllItems() const
    {
        query->prepare("SELECT * FROM mydb.Data");

        if (query->exec()) {
            if (!query->size()) return QHttpServerResponse("No data", QHttpServerResponder::StatusCode::Ok);
            QJsonObject res;
            while (query->next()){
                QJsonObject row{
                    {QString("id"), query->value(0).toJsonValue()},
                    {QString("size"), query->value(1).toJsonValue()},
                    {QString("format"), query->value(2).toJsonValue()},
                    {QString("name"), query->value(3).toJsonValue()},
                    {QString("updatedAt"), query->value(4).toString()}
                };
                res.insert(QString("%1").arg(query->value(0).toInt()), row);
            }
            return QHttpServerResponse(res, QHttpServerResponder::StatusCode::Ok);
        }
        return QHttpServerResponse("", QHttpServerResponder::StatusCode::NotFound);
    }

    QHttpServerResponse createItem(const QHttpServerRequest &request)
    {
        query->prepare("INSERT INTO mydb.Data (size, format, name, uploadedAt) VALUES "
                            "(:size, :format, :name, :uploadedAt)"
                       );

        QJsonDocument parseDoc= QJsonDocument::fromJson(QByteArray(request.body()));
        QJsonObject parseObject = parseDoc.object();

        query->bindValue(":size", parseObject["size"].toVariant());
        query->bindValue(":format", parseObject["format"].toVariant());
        query->bindValue(":name", parseObject["name"].toVariant());
        query->bindValue(":uploadedAt", QDateTime::currentDateTime());

        if (query->exec()){
            return QHttpServerResponse(QHttpServerResponder::StatusCode::Created);
        };
        qDebug() << query->lastError();
        return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);
    }


    QHttpServerResponse updateItem(qint64 itemId, const QHttpServerRequest &request)
    {
        query->prepare("SELECT * FROM mydb.Data WHERE id = :id");
        query->bindValue(":id", itemId);
        if (!query->exec() && !query->next())
            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);



        QJsonDocument parseDoc= QJsonDocument::fromJson(QByteArray(request.body()));
        QJsonObject parseObject = parseDoc.object();
        QString prepareSet;

        for (QJsonObject::iterator it = parseObject.begin(); it != parseObject.end(); ++it) {
            QString key = it.key();
            QJsonValue value = it.value();
            prepareSet.append(QString("`%1` = '%2', ").arg(key, value.toString()));
        }

        query->prepare("UPDATE mydb.Data "
                       "SET " +
                       prepareSet +
                       "uploadedAt = '" +
                       QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") +
                       "' WHERE (`id` = '" +
                       QString::number(itemId) +
                       "');"
                       );

        if (query->exec()){
            return QHttpServerResponse(QHttpServerResponder::StatusCode::Ok);
        };
        qDebug() << query->lastError() << query->executedQuery();
        qDebug() << db->lastError();
        return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);
    }

    QHttpServerResponse deleteItem(qint64 itemId = -1)
    {
//        query->prepare("SELECT * FROM mydb.Data WHERE id = :id");
//        query->bindValue(":id", itemId);
//        if (!query->exec() && !query->next())
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);
        qDebug() << itemId;
        QString deletePrepare= "";
        if (itemId != -1) deletePrepare.append(QString("WHERE id = %1").arg(itemId));
        query->prepare("DELETE FROM mydb.Data " +
                       deletePrepare);
        if (query->exec())
            qDebug() << query->lastQuery();
            return QHttpServerResponse(QHttpServerResponder::StatusCode::Ok);

        qDebug() << query->lastError() << query->executedQuery();
        qDebug() << db->lastError();
        return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);
    }

private:
    QSqlDatabase *db;
    QSqlQuery *query;
};

//    QHttpServerResponse updateItemFields(qint64 itemId, const QHttpServerRequest &request)
//    {
//        const std::optional<QJsonObject> json = byteArrayToJsonObject(request.body());
//        if (!json)
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);

//        auto item = data.find(itemId);
//        if (item == data.end())
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::NoContent);
//        item->updateFields(*json);

//        return QHttpServerResponse(item->toJson());
//    }

//    QHttpServerResponse deleteItem(qint64 itemId)
//    {
//        if (!data.remove(itemId))
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::NoContent);
//        return QHttpServerResponse(QHttpServerResponder::StatusCode::Ok);
//    }











//class SessionApi
//{
//public:
//    explicit SessionApi(const IdMap<SessionEntry> &sessions,
//                        std::unique_ptr<FromJsonFactory<SessionEntry>> factory)
//        : sessions(sessions), factory(std::move(factory))
//    {
//    }

//    QHttpServerResponse registerSession(const QHttpServerRequest &request)
//    {
//        const auto json = byteArrayToJsonObject(request.body());
//        if (!json)
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);
//        const auto item = factory->fromJson(*json);
//        if (!item)
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);

//        const auto session = sessions.insert(item->id, *item);
//        session->startSession();
//        return QHttpServerResponse(session->toJson());
//    }

//    QHttpServerResponse login(const QHttpServerRequest &request)
//    {
//        const auto json = byteArrayToJsonObject(request.body());

//        if (!json || !json->contains("email") || !json->contains("password"))
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);

//        auto maybeSession = std::find_if(
//            sessions.begin(), sessions.end(),
//            [email = json->value("email").toString(),
//             password = json->value("password").toString()](const auto &it) {
//                return it.password == password && it.email == email;
//            });
//        if (maybeSession == sessions.end()) {
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::NotFound);
//        }
//        maybeSession->startSession();
//        return QHttpServerResponse(maybeSession->toJson());
//    }

//    QHttpServerResponse logout(const QHttpServerRequest &request)
//    {
//        const auto maybeToken = getTokenFromRequest(request);
//        if (!maybeToken)
//            return QHttpServerResponse(QHttpServerResponder::StatusCode::BadRequest);

//        auto maybeSession = std::find(sessions.begin(), sessions.end(), *maybeToken);
//        if (maybeSession != sessions.end())
//            maybeSession->endSession();
//        return QHttpServerResponse(QHttpServerResponder::StatusCode::Ok);
//    }

//    bool authorize(const QHttpServerRequest &request) const
//    {
//        const auto maybeToken = getTokenFromRequest(request);
//        if (maybeToken) {
//            const auto maybeSession = std::find(sessions.begin(), sessions.end(), *maybeToken);
//            return maybeSession != sessions.end() && *maybeSession == *maybeToken;
//        }
//        return false;
//    }

//private:

//};

#endif // DATACRUDAPI_H
