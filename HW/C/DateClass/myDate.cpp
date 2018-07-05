#include <cstdlib>
#include "myDate.h"
#include <cstdlib>
#define LEAPYEAR(i) (i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)

// Constructor (생성자)
myDate::myDate(int year, int month, int day)
    : Year(year), Month(month), Day(day) { }
// Copy Constructor (복사 생성자)
myDate::myDate(const myDate &date)
    : Year(date.Year), Month(date.Month), Day(date.Day) { }
// Accessor functions (접근자)
int myDate::getDayOfMonth() const { return Day; }
int myDate::getMonth() const { return Month; }
int myDate::getYear() const { return Year; }

// Mutator functions (변경자)
void myDate::setDayOfMonth(int day) { Day = day; }
void myDate::setMonth(int month) { Month = month; }
void myDate::setYear(int year) { Year = year; }
void myDate::setDate(int year, int month, int day) {
    Year = year;
    Month = month;
    Day = day;
}

// utility functions
bool myDate::isLeapYear() const
{
    int y = getYear();
    return LEAPYEAR(y);
}
int myDate::getDayOfWeek() const
{
    int totalDays = 0;
    for (int i = 1582; i < Year; i++) {
        totalDays += LEAPYEAR(i) ? 366 : 365;
    }
    for (int i = 1; i < Month; i++) {
        totalDays += dayOfMonth[i - 1];
        totalDays += (i == 2 && isLeapYear()) ? 1: 0;
    }
    totalDays += Day + 4;

    return totalDays % 7;
}
int myDate::getDayOfYear() const
{
    int DayOfYear = 0;
    for (int i = 1; i < Month; i++) {
        DayOfYear += dayOfMonth[i - 1];
        DayOfYear += (i == 2 && isLeapYear()) ? 1: 0;
    }
    DayOfYear += Day;
    return DayOfYear;
}

int myDate::getNumHolidays() const
{
    int numHolidays = 0, i;
    numHolidays += 104;  // 364일까지 토요일, 일요일
    for (i = 0; i < 15; i++) {
        myDate tempDate = myDate(Year, Holidays[i][0], Holidays[i][1]);
        if (tempDate.getDayOfWeek() != 0 && tempDate.getDayOfWeek() != 6) {
            numHolidays++;
        }
    }
    myDate tempDate1 = myDate(Year, 12, 30);
    myDate tempDate2 = myDate(Year, 12, 31);
    if (isLeapYear()) {
        if (tempDate1.getDayOfWeek() == 0 || tempDate1.getDayOfWeek() == 6) {
            numHolidays++;
        }
    }
    if (tempDate2.getDayOfWeek() == 0 || tempDate2.getDayOfWeek() == 6) {
        numHolidays++;
    }
    return numHolidays;
}

int myDate::getNumSummerTimeDays() const
{
    // 3 월의 가장 마지막 일요일에 일광절약시간제를 적용하며, 10 월의 가장 마지막 일요일에 해지한다.
    int numSummerTimeDays = 0, i;
    myDate tempDate = myDate(Year, 3, 31);
    numSummerTimeDays += tempDate.getDayOfWeek() + 1; // 3월 마지막 일요일 ~ 3월 31일 (+)
    for (i = 4; i <= 10; i++) {
        numSummerTimeDays += dayOfMonth[i - 1];  // 4월 1일 ~ 10월 31일
    }
    tempDate = myDate(Year, 10, 31);
    numSummerTimeDays -= tempDate.getDayOfWeek() + 1; // 10월 마지막 일요일 ~ 10월 31일 (-)
    return numSummerTimeDays;
}

void myDate::printCalendarOfMonth() const
{
    cout << Year << " " << Month << endl;
    myDate tempDate(Year, Month, 1);
    int i, cursor = 0, m;
    if (isLeapYear() && Month == 2) {
        m = 29;
    }
    else {
        m = dayOfMonth[Month - 1];
    }
    for (i = 0; i < tempDate.getDayOfWeek(); i++) {
        cout << 0 << " ";
        cursor++;
    }
    for (i = 1; i <= m; i++) {
        if (cursor != 7) {
            cout << i << " ";
            cursor++;
        } else {
            cursor = 1;
            cout << "\n" << i << " ";
        }
    }
    for (i = cursor; cursor != 7; i++)
    {
        cout << 0 << " ";
        cursor++;
    }
}
// DD/MM/YYYY 출력
ostream &operator<<(ostream &outStream, const myDate &date)
{
   outStream << date.Day / 10 << date.Day % 10 << "/" << date.Month / 10 << date.Month % 10 << "/" << date.Year;
}
// 날짜에 몇일을 더하는 연산자
myDate operator+(int num, const myDate &date) {
    myDate tempDate = myDate(date.Year, date.Month, date.Day);
    tempDate.Day += num;
    if (tempDate.Day >= 0) {
        while (tempDate.Day > dayOfMonth[tempDate.Month - 1]) {
            tempDate.Day -= dayOfMonth[tempDate.Month - 1];
            tempDate.Month++;
            if (tempDate.Month > 12) {
                if (LEAPYEAR(tempDate.Year))
                    tempDate.Day--;
                tempDate.Month = 1;
                tempDate.Year++;
            }
        }
    }
    else {
        while (tempDate.Day <= 0) {
            tempDate.Day += dayOfMonth[tempDate.Month - 1];
            tempDate.Month--;
            if (tempDate.Month <= 0) {
                tempDate.Year--;
                if (LEAPYEAR(tempDate.Year))
                    tempDate.Day++;
                tempDate.Month = 12;
            }
        }
    }
    return tempDate;
}
// 날짜(년, 월, 일)에 해당되는 데이터를 입력
istream &operator>>(istream &inStream, myDate &date)
{
    inStream >> date.Year >> date.Month >> date.Day;
}
// 두 날짜 사이의 날짜 수를 나타내는 정수를 리턴
int myDate::operator-(const myDate &date) const
{
    int d1 = 0, d2 = 0, i;
    for (i = 1582; i < Year; i++) {
        d1 += LEAPYEAR(i) ? 366 : 365;
    }
    d1 += getDayOfYear();
    for (i = 1582; i < date.Year; i++) {
        d2 += LEAPYEAR(i) ? 366 : 365;
    }
    d2 += date.getDayOfYear();
    return d1 - d2;
}
myDate myDate::operator+(int num) const
{
    myDate tempDate(Year, Month, Day);
    tempDate = num + tempDate;
    return tempDate;
}
myDate myDate::operator-(int num) const
{
    myDate tempDate(Year, Month, Day);
    tempDate = (-num) + tempDate;
    return tempDate;
}
myDate& myDate::operator++()
{
    Day++;
    return *this;
}
myDate& myDate::operator--()
{
    Day--;
    return *this;
}
myDate myDate::operator++(int)
{
    myDate tempDate(Year, Month, Day);
    Day++;
    return tempDate;
}
myDate myDate::operator--(int)
{
    myDate tempDate(Year, Month, Day);
    Day--;
    return tempDate;
}
myDate& myDate::operator=(const myDate &date)
{
    Year = date.Year;
    Month = date.Month;
    Day = date.Day;
    return *this;
}
myDate& myDate::operator+=(int num)
{
    *this = num + *this;
    return *this;
}
myDate& myDate::operator-=(int num)
{
    *this = (-num) + *this;
}
bool myDate::operator>(const myDate &date) const
{
    return *this - date > 0;
}
bool myDate::operator>=(const myDate &date) const
{
    return *this - date >= 0;
}
bool myDate::operator<(const myDate &date) const
{
    return *this - date < 0;
}
bool myDate::operator<=(const myDate &date) const
{
    return *this - date <= 0;
}
bool myDate::operator==(const myDate &date) const
{
    return date.Year == Year && date.Month == Month && date.Day == Day;
}
bool myDate::operator!=(const myDate &date) const
{
    return !(operator==(date));
}