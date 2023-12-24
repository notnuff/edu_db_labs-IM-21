#include <QHttpServer>
#include <QHttpServerResponse>
#include <QCoreApplication>
#include <QFile>
#include <QJsonObject>
#include <QString>
#include <QSqlDatabase>
#include <QCommandLineParser>
#include <QJsonArray>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlRecord>
#include "dataCrudApi.h"

#define SCHEME "http"
#define HOST "127.0.0.1"
#define PORT 1488

using namespace Qt::StringLiterals;

static inline QString host(const QHttpServerRequest &request)
{
    return QString::fromLatin1(request.value("Host"));
}

static QHttpServerResponse getAllResponse(const QHttpServerRequest &request){
    //QJsonArray array = myData;
    return QHttpServerResponse("getResponse");
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydb");
    db.setUserName("root");
    db.setPassword("6=Oo6s9<GDfqa5QTg£^T-yC,kbFs8");
    db.setPort(3306);
    bool ok = db.open();
    if (!ok) qDebug() << db.lastError();



    QCommandLineParser parser;
    parser.addOptions({
                       { "port", QCoreApplication::translate("main", "The port the server listens on."),
                        "port" },
                       });
    parser.addHelpOption();
    parser.process(app);

    quint16 portArg = PORT;

    if (!parser.value("port").isEmpty())
        portArg = parser.value("port").toUShort();


    QHttpServer httpServer;
    QSqlQuery query{db};
    DataCrudApi api{&db};

    httpServer.route(
        QString("/data"), QHttpServerRequest::Method::Get,
        [&api](const QHttpServerRequest &request) {
            return api.getAllItems();
        });

    httpServer.route(
        QString("/data/<arg>"), QHttpServerRequest::Method::Get,
        [&api](qint64 itemId) {
            return api.getItem(itemId);
        });

    httpServer.route(
        QString("/data"), QHttpServerRequest::Method::Post,
            [&api](const QHttpServerRequest &request) {
            return api.createItem(request);
        });

    httpServer.route(
        QString("/data/<arg>"), QHttpServerRequest::Method::Patch,
        [&api](qint64 itemId, const QHttpServerRequest &request) {
            return api.updateItem(itemId, request);
        });
    httpServer.route(
        QString("/data"), QHttpServerRequest::Method::Delete,
        [&api]() {
            return api.deleteItem();
        });
    httpServer.route(
        QString("/data/<arg>"), QHttpServerRequest::Method::Delete,
        [&api](qint64 itemId) {
            return api.deleteItem(itemId);
        });


    httpServer.afterRequest(
        [](QHttpServerResponse &&resp) {
            resp.setHeader("Server", "Qt REST full api");
        return std::move(resp);
    });






    const auto port = httpServer.listen(QHostAddress(HOST), portArg);
    if (!port) {
        qWarning() << QCoreApplication::translate("QHttpServerExample",
                                                  "Server failed to listen on a port.");
        return -1;
    }
    qInfo().noquote()
        << QCoreApplication::translate("QHttpServerExample",
                                       "Running on http://127.0.0.1:%1/"
                                       "(Press CTRL+C to quit)").arg(port);

    return app.exec();
}
