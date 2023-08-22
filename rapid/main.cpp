/*===========================================================================
    CLIPSEditor, editor for CLIPS (C Language Integrated Production System)
    Copyright (C) 2012-2018 Artem G. Novikov

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
===========================================================================*/


#include <QMap>
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include "translator.hpp"
//#include "WndMain.h"
//#include "Exceptions.h"

#include <symboltable.h>
#include <QCommandLineParser>

#include "qfile.h"

#include <QDateTime>

int main(int argc, /*const*/ char** argv)
{
    //QApplication a(argc, argv);
    //bool ret = true;
    //QString Filepath = QCoreApplication::applicationDirPath();

    //QString licenseFile = QString::fromLatin1("%1/license.bat").arg(Filepath);

    //QFile f(licenseFile);
    ////if (!f.exists())
    ////{
    ////    ret = false;
    ////}
    //SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
    //QString license = GetWMICInfo(QString::fromLatin1("wmic baseboard get serialnumber"));
    ////QString remain = 100;
    ////bool ok = false;
    //int remain_dates = 100;// remain.toInt(&ok);

    //QString Last_datetime = QDateTime::currentDateTime().toString(QString::fromLatin1("yyyy-MM-dd"));

    //if (license == GetWMICInfo(QString::fromLatin1("wmic baseboard get serialnumber")) &&  remain_dates > 0)
    //{
    //    QString datetime_str = QDateTime::currentDateTime().toString(QString::fromLatin1("yyyy-MM-dd"));
    //    if (true/*datetime_str != Last_datetime*/)
    //    {
    //        //write
    //        remain_dates = remain_dates - 1;

    //        QString lines;
    //        lines.append(license);
    //        lines.append(QString::fromLatin1("\r\n"));
    //        lines.append(QString::number(remain_dates));
    //        lines.append(QString::fromLatin1("\r\n"));
    //        lines.append(datetime_str);
    //        f.open(QIODevice::WriteOnly);
    //        QByteArray myCypherText = crypto.encryptToByteArray(lines);
    //        f.write(myCypherText.data(), myCypherText.size());
    //        f.close();
    //    }
    //    else
    //    {
    //        ret = false;
    //    }
    //}

    //return a.exec();
    //QCommandLineParser parser;
    //parser.setApplicationDescription(QGuiApplication::translate("main", "Qt"));  // ����Ӧ�ó���������Ϣ
    //parser.addHelpOption();  // ��Ӱ���ѡ�� ��"-h" �� "--help"��
    //parser.addVersionOption();  // ��Ӱ汾ѡ�� ("-v" �� "--version") 

    //parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    //QCommandLineOption srcOption(QStringList() << "s" <<"src",
    //    QGuiApplication::translate("main", "source of As code."),
    //    QGuiApplication::translate("main", "source"), "");
    //parser.addOption(srcOption);

    //QApplication app(argc, argv);
    //parser.process(app);
     QString src = "D:/txt.txt";//parser.value(srcOption);
     Language::Translator translator;
     QString err;
     int ret = (translator.parse(src, err));
     std::map<QString, Language::ModuleNode*> modules = Language::SymbolTable::Instance().Modules();
     return ret;
     //Language::Translator translator;
     //return(translator.parse(argc, argv));
     /*
    try
    {
        QApplication a(argc, argv);
        a.setOrganizationName("beltoforion");
        a.setOrganizationDomain("beltoforion.de");
        a.setApplicationName("As");
        a.setApplicationVersion("1.0");

        QSplashScreen* splash = new QSplashScreen;
        splash->setPixmap(QPixmap(":/images/res/splash.png"));
        splash->show();

        WndMain w;
        QTimer::singleShot(2500, splash, SLOT(close()));
        QTimer::singleShot(2500, &w, SLOT(show()));

        return a.exec();
    }
    catch (Exception& exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.getMessage());
        msgBox.exec();
    }
    catch (std::exception& exc)
    {
        QMessageBox msgBox;
        msgBox.setText(exc.what());
        msgBox.exec();
    }
    catch (...)
    {
        QMessageBox msgBox;
        msgBox.setText("Program aborted due to an unexpected exception");
        msgBox.exec();
    }

    return -1;
    */
     //QApplication app(argc, argv);

     //Config config;

     //qApp->setStyleSheet(config.style);

     //QStringList arguments = QCoreApplication::arguments();
     //arguments.removeFirst();
     //config.openFiles += arguments;

     //QString locale = config.languages.value(config.language);

     //QTranslator trans1;
     //trans1.load(":/lang/clipseditor_" + locale);
     //app.installTranslator(&trans1);

     //QTranslator trans2;
     //trans2.load(":/lang/qtbase_" + locale);
     //app.installTranslator(&trans2);

     //app.setWindowIcon(QPixmap(":/rc/icon.png"));

     //MainWindow window(&config);
     //window.show();

     //return app.exec();
}


