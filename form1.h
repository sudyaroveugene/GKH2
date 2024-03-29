#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class mainView;
}

class mainView : public QWidget
{
    Q_OBJECT

public:
    explicit mainView(QWidget *parent = nullptr);
    ~mainView();

private slots:
    void on_statButton_pressed();
    void on_typeSelector_activated(const QString &arg1);

private:
    Ui::mainView *ui;

    QSqlQuery *baseQuery;
    QSqlTableModel *model;
};

#endif // FORM1_H
