#include <stdlib.h> // EXIT_FAILURE
#include <iostream> // cerr
#include <QApplication>
#include <QtGui>
#include <QRegExp>
#include <QTranslator>
#include <QMessageBox>
#include <QDesktopWidget>

#include "include/mainwindow.h"

int main( int argc, char* argv[] )
{
    Q_INIT_RESOURCE( qtmindmap );
    QApplication a( argc, argv );

    // translation
    QString locale = QLocale::system().name();
    QTranslator translator;

    if ( locale != "C" && !translator.load( QString( "/usr/share/qtmindmap/i18n/qtmindmap_" ) + locale ) )
        std::cerr << "No translation file for locale: " << locale.toStdString() << std::endl;
    else
        a.installTranslator( &translator );

    MainWindow w;
    w.resize( QDesktopWidget().availableGeometry(&w).size() );
    w.show();

    return a.exec();
}
