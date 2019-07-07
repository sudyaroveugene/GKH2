#include "statistic.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <iostream>
#include <stdio.h>

using namespace std;

#define YEAR 366

struct resCounter
{
    long long hourState[YEAR][24];   // показание на начало часа (24 за сутки)
    long long dayState[YEAR];        // показание на 00 часов каждого дня 365 в год
    long long weekState[52];        // показание на 00 часов Понедельника 52 в год
    long long monthState[12];
    long long yearState;            // показания на 00 часов 01.01 указанного года
    int year;                       // номер года
};

struct homeStat
{
    QVector<resCounter> waterCounter;    // счетчик воды
    QVector<resCounter> elCounter;       // счетчик электричества
    QVector<resCounter> gasCounter;      // счетчик газа
    QVector<resCounter> TBOCounter;      // счетчик тверд. быт. отходов

    int readFromFile( QString fileName )
    {
        FILE *in;
        char buffer[80];
        if( (in = fopen( fileName.toStdString().data(), "r" )) == nullptr )
        {
            strerror_s(buffer, 80, errno);
            cerr<<"Ошибка при открытии "<<fileName.data()<<": "<<buffer<<endl;
            return 1;
        }
        char str[256];
        resCounter newCounter;
        for( int j=0; j<YEAR; j++ )
        {
            for( int i=0; i<24; i++ )
                if( fscanf(in, "%s255", str) != EOF)
                    newCounter.hourState[j][i] = atoll( str );
            newCounter.dayState[j] = newCounter.hourState[j][23] - newCounter.hourState[j][0];
        }
        // потребление по неделе
        long long lastCount = newCounter.dayState[0];
        for( int j=0; j<52; j++ )
        {
            newCounter.weekState[j] = newCounter.dayState[j*7] - lastCount;
            lastCount = newCounter.dayState[j*7];
        }
        // потребление по месяцу
        lastCount = newCounter.dayState[0];
        for( int j=0; j<12; j++ )
        {
            newCounter.monthState[j] = newCounter.dayState[j*30] - lastCount;
            lastCount = newCounter.dayState[j*30];
        }
        newCounter.yearState = newCounter.dayState[YEAR-1] - newCounter.dayState[0];
        return 0;
    }

};

struct statistic
{
public:
    statistic();

    QVector<homeStat> resGlobalCounter;
};
