/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTableView>
#include <QApplication>
#include <QTableView>
#include <QImage>
#include <QImageReader>

#include "customsqlmodel.h"
#include "editablesqlmodel.h"
#include "form1.h"
#include "ui_form1.h"

//void initializeModel(QSqlQueryModel *model);
QSqlDatabase db;

static bool createConnection( QSqlQuery& query )
{
//    QString Name;               // ФИО заявителя
//    QString phone;              // телефон заявителя
//    homeAddress persAddr;       // адрес заявителя
//    QString problemType;        // тип проблемы из списка
//    QString problem;            // описание проблемы
//    homeAddress problemAddr;    // адрес проблемы
//    QTime   startTime;          // время поступления заявки
//    QTime   finishTime;         // время устранения проблемы
//    bool    feedBack;           // отметка об обратной связи на заявку

    query.exec("create table problems (id int primary key, "
               "fio varchar(40), phone varchar(15), homeAddr varchar(50), problemType varchar(20), "
               "problemDesc varchar(50), problemAddr varchar(40), startTime varchar(20), finishTime varchar(20), feedback varchar(4))" );
    query.exec("insert into problems values(1, 'Иванов А.С.', '8-123-259-1245', 'Демакова, 24, кв. 25', 'вода', 'прорыв водопровода',"
               "'Демакова, 32','12.07.2019 13-23', '', 'нет')  ");
    query.exec("insert into problems values(2, 'Петров И.И.', '8-123-344-1245', 'Советская, 54, кв. 2', 'канализация', 'течь',"
               "'Ленина, 32','12.07.2019 13-23', '', 'нет')  ");
    query.exec("insert into problems values(3, 'Степанов А.Б.', '8-123-259-5752', 'Ленина, 77, кв. 78', 'электричество', 'нет света',"
               "'Ленина, 32','12.07.2019 13-23', '', 'нет')  ");
    query.exec("insert into problems values(4, 'Светлов И.Б.', '8-923-259-5752', 'Выборная, 24, кв. 221', 'вода', 'нет холодной воды',"
               "'Выборная, 24','07.06.2019 11-23', '07.06.2019 14-30', 'да' ) ");
    query.exec("insert into problems values(5, 'Кравченко И.Б.', '8-223-259-5535', 'Никитина, 36', 'электричество', 'нет света',"
               "'Никитина, 36','12.06.2019 18-23', '12.06.2019 23-30', 'да' ) ");
    query.exec("insert into problems values(6, 'Бабушкина А.Н.', '334-25-52', 'Большевистская, 152', 'вода', 'нет горячей воды',"
               "'Большевистская, 152','15.06.2019 10-12', '20.06.2019 14-30', 'да' )  ");
    query.exec("insert into problems values(7, 'Деточкин И.П.', '123-59-52', 'Вокзальная магистраль 3/1, 24', 'электричество', 'нет света',"
               "'Вокзальная магистраль 3/1, 15','22.06.2019 15-30', '22.06.2019 16-00', 'да' ) ");
    query.exec("insert into problems values(8, 'Степанов А.Б.', '8-123-259-5752', 'Ленина, 24', 'электричество', 'нет света',"
               "'Ленина, 32','12.07.2019 13-23', '', 0)  ");
    query.exec("insert into problems values(9, 'Степанов А.Б.', '8-123-259-5752', 'Ленина, 24', 'электричество', 'нет света',"
               "'Ленина, 32','12.07.2019 13-23', '', 0)  ");
    query.exec("insert into problems values(10, 'Степанов А.Б.', '8-123-259-5752', 'Ленина, 24', 'электричество', 'нет света',"
               "'Ленина, 32','12.07.2019 13-23', '', 0)  ");
    query.exec("insert into problems values(11, 'Степанов А.Б.', '8-123-259-5752', 'Ленина, 24', 'электричество', 'нет света',"
               "'Ленина, 32','12.07.2019 13-23', '', 0)  ");
    query.exec("insert into problems values(12, 'Степанов А.Б.', '8-123-259-5752', 'Ленина, 24', 'электричество', 'нет света',"
               "'Ленина, 32','12.07.2019 13-23', '', 0)  ");

    return true;
}

mainView::mainView(QWidget *parent) : QWidget(parent), ui(new Ui::mainView)
{
    ui = new Ui::mainView;
    ui->setupUi(this);
    this->setWindowTitle( "ЖКХ (прототип)" );

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(db.open()) {
        model = new QSqlTableModel( ui->tableView, db );
        // запросы к базе данных
        baseQuery = new QSqlQuery( db );
        createConnection( *baseQuery );
        baseQuery->exec("select * from problems");

        model->setTable( "problems" );
        model->select();
        model->setHeaderData( 0 , Qt :: Horizontal , tr( " № \nзаявки" ));
        model->setHeaderData( 1 , Qt :: Horizontal , tr( "ФИО" ));
        model->setHeaderData( 2 , Qt :: Horizontal , tr( "Телефон" ));
        model->setHeaderData( 3 , Qt :: Horizontal , tr( "Адрес" ));
        model->setHeaderData( 4 , Qt :: Horizontal , tr( "Тип проблемы" ));
        model->setHeaderData( 5 , Qt :: Horizontal , tr( "Проблема" ));
        model->setHeaderData( 6 , Qt :: Horizontal , tr( "Адрес" ));
        model->setHeaderData( 7 , Qt :: Horizontal , tr( "Время\nполучения" ));
        model->setHeaderData( 8 , Qt :: Horizontal , tr( "Время\nустранения" ));
        model->setHeaderData( 9 , Qt :: Horizontal , tr( "Ответ\nотправлен" ));

        ui->tableView->setModel( model );
        ui->tableView->setSortingEnabled( true );
        ui->tableView->sortByColumn( 0, Qt::AscendingOrder );
    // включаем перетаскивание колонок
        ui->tableView->horizontalHeader()->setSectionsMovable(true);
    // делаем минимальную ширину колонки нулевой - колонки можно скрывать
        ui->tableView->horizontalHeader()->setMinimumSectionSize( 0 );
        ui->tableView->show();

        QImageReader reader("map.jpg");
        reader.setAutoTransform(true);
        QImage problemMap = reader.read();
        if (problemMap.isNull()) {
            QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                     tr("Cannot load problemMap file") );
            exit(1);
        }
        ui->mapView->setPixmap(QPixmap::fromImage(problemMap));
        ui->mapView->resize(ui->mapView->pixmap()->size());
        ui->mapView->update();
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

mainView::~mainView()
{
    if( baseQuery )
        delete baseQuery;
    if( model )
        delete model;
    delete ui;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainView myMainView;

    myMainView.show();


    return app.exec();
}
