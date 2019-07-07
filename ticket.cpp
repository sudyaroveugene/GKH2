#include "ticket.h"

#include <QString>
#include <QStringList>
#include <QTime>

struct homeAddress
{
    QString Street;     // улица
    QString homeNumber; // номер дома
    int flat;           // квартира
};

const QStringList problemTypes = { "Свет", "Вода", "Канализация", "Газ",
    "Бытовые отходы", "Уборка снега", "Гололед"  };

// Заявка
struct ticket
{
public:
    ticket();

    QString Name;               // ФИО заявителя
    QString phone;              // телефон заявителя
    homeAddress persAddr;       // адрес заявителя
    QString problemType;        // тип проблемы из списка
    QString problem;            // описание проблемы
    homeAddress problemAddr;    // адрес проблемы
    QTime   startTime;          // время поступления заявки
    QTime   finishTime;         // время устранения проблемы
    bool    feedBack;           // отметка об обратной связи на заявку
};
