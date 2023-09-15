#include <iostream>


class Date
{
public:
    int m_day{};
    int m_month{};
    int m_year{};

    Date(int day, int month, int year)
    {
        this->m_day = day;
        this->m_month = month;
        this->m_year = year;
    }

    void printDate()
    {
        std::cout << m_day << '/' << m_month 
                    << '/' << m_year << std::endl;
        
    }
};



int main(int argc, char const *argv[])
{
    Date date { 4, 10, 21};
    date.printDate();

    return 0;
}
