#include <iostream>

class Date
{
public:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day)
        : m_year { year }
        , m_month { month }
        , m_day { day }
    {
    }

    int getYear()  { return m_year; }
    int getMonth() { return m_month; }
    int getDay()   { return m_day; }
};

// note: We're passing date by const reference here to avoid making a copy of date
void printDate(const Date &date)
{
    this->m_year = 100;
    // std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

int main()
{
    Date date{2016, 10, 16};
    printDate(date);

    return 0;
}