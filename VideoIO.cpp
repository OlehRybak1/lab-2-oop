#include "VideoIO.h"
#include <iostream>
using namespace std;

void VideoIO::Input(Video& v)
{
    cout << "\n\tВведіть заголовок фільму: ";
    v.setTitle(ConsolIO::GetText(cin));

    cout << "\tВведіть тему (жанр): ";
    v.setTheme(ConsolIO::GetText(cin));

    cout << "\tВведіть акторів (через кому): ";
    v.setActors(ConsolIO::GetText(cin));

    cout << "\tВведіть оцінку (0-10): ";
    v.setRating(ConsolIO::GetValueInRange(cin, 0.0, 10.0));

    cout << "\tВведіть довжину, хв (більше 0): ";
    v.setLength(ConsolIO::GetValueInRange(cin, 0.1, 100000.0));

    cout << "\tВведіть швидкість відтворення (1-100): ";
    v.setSpeed(ConsolIO::GetValueInRange(cin, 1.0, 100.0));

    cout << "\tВведіть назву файла: ";
    v.setFileName(ConsolIO::GetText(cin));

    cout << "\tВведіть дату (РРРР-ММ-ДД): ";
    v.setDate(ConsolIO::GetDate(cin));
}

void VideoIO::Output(Video& v)
{
    cout << "\t Фільм:      " << v.getTitle() << '\n';
    cout << "\t Тема:       " << v.getTheme() << '\n';
    cout << "\t Актори:     " << v.getActors() << '\n';
    cout << "\t Оцінка:     " << v.getRating() << '\n';
    cout << "\t Довжина:    " << v.getLength() << " хв\n";
    cout << "\t Швидкість:  " << v.getSpeed() << '\n';
    cout << "\t Файл:       " << v.getFileName() << '\n';
    cout << "\t Дата:       " << v.getDate() << "\n\n";
}
