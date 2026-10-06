#pragma once
#include <iostream>
#include <string>
#include <limits>

// Статичний клас для роботи з консоллю (зчитування чисел і тексту з перевіркою)
class ConsolIO
{
public:
    // Зчитує дійсне число, якщо введено не число - просить повторити
    static double GetValue(std::istream& is)
    {
        double value;
        while (true)
        {
            if (is >> value)
            {
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "\n\tНЕКОРЕКТНИЙ ВВІД! Очікується число. Повторіть: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return value;
    }

    // Зчитує дійсне число в заданому діапазоні [minVal, maxVal]
    static double GetValueInRange(std::istream& is, double minVal, double maxVal)
    {
        while (true)
        {
            double value = GetValue(is);
            if (value >= minVal && value <= maxVal)
                return value;

            std::cout << "\tЗначення має бути в межах [" << minVal << "; " << maxVal
                       << "]. Спробуйте ще раз: ";
        }
    }

    // Зчитує ціле число в заданому діапазоні (напр. для пунктів меню)
    static int GetIntInRange(std::istream& is, int minVal, int maxVal)
    {
        while (true)
        {
            int value = static_cast<int>(GetValue(is));
            if (value >= minVal && value <= maxVal)
                return value;

            std::cout << "\tВведіть число від " << minVal << " до " << maxVal << ": ";
        }
    }

    // Зчитує непорожній рядок тексту з консолі
    static std::string GetText(std::istream& is)
    {
        std::string line;
        while (true)
        {
            std::getline(is, line);
            bool onlySpaces = true;
            for (char c : line)
                if (c != ' ') { onlySpaces = false; break; }

            if (!line.empty() && !onlySpaces)
                break;

            std::cout << "\n\tНЕКОРЕКТНИЙ ВВІД! Очікується текст. Повторіть: ";
        }
        return line;
    }

    // Перевіряє, чи є рік високосним
    static bool IsLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Повертає кількість днів у заданому місяці й році
    static int DaysInMonth(int month, int year)
    {
        static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && IsLeapYear(year))
            return 29;
        return days[month - 1];
    }

    // Зчитує дату у форматі РРРР-ММ-ДД з перевіркою формату ТА реальності дати
    // (місяць 01-12, день 01-31 з урахуванням кількості днів у конкретному місяці)
    static std::string GetDate(std::istream& is)
    {
        while (true)
        {
            std::string date = GetText(is);

            bool formatOk = (date.size() == 10 && date[4] == '-' && date[7] == '-');
            if (formatOk)
            {
                for (size_t i = 0; i < date.size() && formatOk; i++)
                {
                    if (i == 4 || i == 7) continue;
                    if (!isdigit(static_cast<unsigned char>(date[i]))) formatOk = false;
                }
            }

            if (!formatOk)
            {
                std::cout << "\tНЕКОРЕКТНИЙ ФОРМАТ ДАТИ! Очікується РРРР-ММ-ДД. Повторіть: ";
                continue;
            }

            int year  = std::stoi(date.substr(0, 4));
            int month = std::stoi(date.substr(5, 2));
            int day   = std::stoi(date.substr(8, 2));

            if (month < 1 || month > 12)
            {
                std::cout << "\tНЕКОРЕКТНИЙ МІСЯЦЬ (01-12)! Повторіть: ";
                continue;
            }

            if (day < 1 || day > DaysInMonth(month, year))
            {
                std::cout << "\tНЕКОРЕКТНИЙ ДЕНЬ (01-" << DaysInMonth(month, year)
                           << " для цього місяця)! Повторіть: ";
                continue;
            }

            return date;
        }
    }
};
