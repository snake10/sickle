#include <mainwindow.h>
#include <QApplication>
#include <QSurfaceFormat>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    QString locale = QLocale::system().name();
    translator.load(QString(":/lang/editor_") + locale);
    app.installTranslator(&translator);

    QSurfaceFormat format;
    format.setDepthBufferSize(16);
    format.setStencilBufferSize(8);
    format.setSamples(16);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    MainWindow window;
    window.resize(640, 480);
    window.show();

    return app.exec();
}