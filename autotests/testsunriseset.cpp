/*
    This file is part of the kholidays library.

    SPDX-FileCopyrightText: 2012 Allen Winter <winter@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testsunriseset.h"
#include "sunriseset.h"
using namespace KHolidays;
using namespace SunRiseSet;

#include <QTest>

QTEST_MAIN(SunriseTest)

void SunriseTest::TestSunrise()
{
    //test bogus latitudes and longitudes
    QCOMPARE(utcSunrise(QDate(2012, 1, 1), 1000.0, 1000.0), QTime(0, 0));
    QCOMPARE(utcSunrise(QDate(2012, 7, 1), -1000.0, -1000.0), QTime(0, 0));
    QCOMPARE(utcSunrise(QDate(2012, 12, 31), 1000.0, -1000.0), QTime(0, 0));

    //NYC
    QCOMPARE(utcSunrise(QDate(2012, 1, 1), 40.72, -74.02), QTime(12, 20));
    QCOMPARE(utcSunrise(QDate(2012, 7, 1), 40.72, -74.02), QTime(9, 29));
    QCOMPARE(utcSunrise(QDate(2012, 12, 31), 40.72, -74.02), QTime(12, 20));

    //LA
    QCOMPARE(utcSunrise(QDate(2012, 1, 1), 34.05, -118.23), QTime(14, 58));
    QCOMPARE(utcSunrise(QDate(2012, 7, 1), 34.05, -118.23), QTime(12, 45));
    QCOMPARE(utcSunrise(QDate(2012, 12, 31), 34.05, -118.23), QTime(14, 58));

    //Berlin
    QCOMPARE(utcSunrise(QDate(2012, 1, 1), 51.40, 7.38), QTime(7, 36));
    QCOMPARE(utcSunrise(QDate(2012, 7, 1), 51.40, 7.38), QTime(3, 19));
    QCOMPARE(utcSunrise(QDate(2012, 12, 31), 51.40, 7.38), QTime(7, 36));

    //Tasmania
    QCOMPARE(utcSunrise(QDate(2012, 1, 1), -14.60, 133.77), QTime(20, 39));
    QCOMPARE(utcSunrise(QDate(2012, 7, 1), -14.60, 133.77), QTime(21, 31));
    QCOMPARE(utcSunrise(QDate(2012, 12, 31), -14.60, 133.77), QTime(20, 39));
}

void SunriseTest::TestSunset()
{
    //NYC
    QCOMPARE(utcSunset(QDate(2012, 1, 1), 40.72, -74.02), QTime(21, 39));
    QCOMPARE(utcSunset(QDate(2012, 7, 1), 40.72, -74.02), QTime(00, 31));
    QCOMPARE(utcSunset(QDate(2012, 12, 31), 40.72, -74.02), QTime(21, 38));

    //LA
    QCOMPARE(utcSunset(QDate(2012, 1, 1), 34.05, -118.23), QTime(00, 54));
    QCOMPARE(utcSunset(QDate(2012, 7, 1), 34.05, -118.23), QTime(3, 8));
    QCOMPARE(utcSunset(QDate(2012, 12, 31), 34.05, -118.23), QTime(00, 54));

    //Berlin
    QCOMPARE(utcSunset(QDate(2012, 1, 1), 51.40, 7.38), QTime(15, 32));
    QCOMPARE(utcSunset(QDate(2012, 7, 1), 51.40, 7.38), QTime(19, 50));
    QCOMPARE(utcSunset(QDate(2012, 12, 31), 51.40, 7.38), QTime(15, 32));

    //Tasmania
    QCOMPARE(utcSunset(QDate(2012, 1, 1), -14.60, 133.77), QTime(9, 37));
    QCOMPARE(utcSunset(QDate(2012, 7, 1), -14.60, 133.77), QTime(8, 47));
    QCOMPARE(utcSunset(QDate(2012, 12, 31), -14.60, 133.77), QTime(9, 37));
}
