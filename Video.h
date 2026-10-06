#pragma once
#include <string>

/*------------------------------------------------------------
Клас Video представляє один відеофайл у бібліотеці програвача:
заголовок, тему, акторів, оцінку, довжину, швидкість відтворення,
назву файла, дату.
--------------------------------------------------------------*/
class Video
{
protected:
    std::string title;    // заголовок
    std::string theme;    // тема (жанр)
    std::string actors;   // актори (перелічені через кому)
    double rating;        // оцінка (0..10)
    double length;        // довжина, хв
    double speed;         // швидкість відтворення (напр. 1.0 = звичайна)
    std::string fileName; // назва файла
    std::string date;     // дата (РРРР-ММ-ДД)

    static bool containsIgnoreCase(const std::string& text, const std::string& query);

public:
    Video();                                        // конструктор без параметрів
    Video(std::string title, std::string theme, std::string actors,
          double rating, double length, double speed,
          std::string fileName, std::string date);   // параметризований конструктор
    ~Video();                                         // деструктор

    // методи доступу до полів класу (get / set)
    std::string getTitle() const;
    void setTitle(const std::string& value);

    std::string getTheme() const;
    void setTheme(const std::string& value);

    std::string getActors() const;
    void setActors(const std::string& value);

    double getRating() const;
    void setRating(double value);

    double getLength() const;
    void setLength(double value);

    double getSpeed() const;
    void setSpeed(double value);

    std::string getFileName() const;
    void setFileName(const std::string& value);

    std::string getDate() const;
    void setDate(const std::string& value);

    // пошук за підрядком (без урахування регістру) у кожному полі
    bool matchesActor(const std::string& query) const;
    bool matchesTitle(const std::string& query) const;
    bool matchesTheme(const std::string& query) const;
};
