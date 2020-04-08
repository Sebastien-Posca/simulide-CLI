/***************************************************************************
 *   Copyright (C) 2012 by santiago González                               *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#include <QApplication>
#include <QTranslator>
#include <string>
#include <iostream>
using namespace std;

#include "mainwindow.h"

int main(int argc, char *argv[])
{

#ifdef _WIN32
    QStringList paths = QCoreApplication::libraryPaths();
    paths.append("plugins");
    paths.append("plugins/platforms");
    paths.append("plugins/imageformats");
    paths.append("plugins/sqldrivers");
    paths.append("plugins/bearer");
    paths.append("plugins/generic");
    paths.append("plugins/iconengines");
    paths.append("plugins/qmltooling");
    paths.append("plugins/printsupport");
    QCoreApplication::setLibraryPaths(paths);
#endif

    string simuPath;
    string hexPath;
    string logsPath;

  
    for (int i = 0; i < argc-1; ++i) {

        if(strcmp(argv[i],"--simu") == 0){
            simuPath=argv[i+1];
        }
        if(strcmp(argv[i],"--hex") == 0){
            hexPath=argv[i+1];
        }
        if(strcmp(argv[i],"--logs") == 0){
            logsPath=argv[i+1];
            QFile file_obj(QString::fromStdString(logsPath));
            if(!file_obj.open(QIODevice::ReadOnly)){
                qDebug()<<"Failed to open " << QString::fromStdString(logsPath);
                exit(1);
            }

            QTextStream file_text(&file_obj);
            QString json_string;
            json_string = file_text.readAll();
            file_obj.close();
            QByteArray json_bytes = json_string.toLocal8Bit();
            auto json_doc=QJsonDocument::fromJson(json_bytes);

            if(json_doc.isNull()){
                qDebug()<<"Failed to create JSON doc.";
                exit(2);
            }
            if(!json_doc.isArray()){
                qDebug() << "JSON doc is not an array.";
                exit(1);
            }

            QJsonArray json_array = json_doc.array();

            if(json_array.isEmpty()){
                qDebug() << "The array is empty";
                exit(1);
            }
            qDebug() << json_array;
            for(int i=0; i< json_array.count(); ++i){
                qDebug() << i;
                qDebug() << json_array.at(i).toObject();
            }
        }
        
    }
    //QApplication::setGraphicsSystem( "raster" );//native, raster, opengl
    QApplication app( argc, argv );

    QString locale   = QLocale::system().name().split("_").first();
    QString langFile = "../share/simulide/translations/simulide_"+locale+".qm";
    
    QFile file( langFile );
    if( !file.exists() ) langFile = "../share/simulide/translations/simulide_en.qm";
    
    QTranslator translator;
    translator.load( langFile );
    app.installTranslator( &translator );
    
    MainWindow window;

    if(!simuPath.empty() && !hexPath.empty()){
        window.autoStart(simuPath, hexPath);
    }
    
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = ( screenGeometry.width()-window.width() ) / 2;
    int y = ( screenGeometry.height()-window.height() ) / 2;
    window.move( x, y );

    window.show();
    app.setApplicationVersion( APP_VERSION );
    return app.exec();
}

