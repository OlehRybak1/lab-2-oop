#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    cout << "Введіть кількість відеофайлів у бібліотеці (1-1000): ";
    videoCount = static_cast<int>(ConsolIO::GetValueInRange(cin, 1, 1000));
    videos = new Video[videoCount];
    ioWorker = new VideoIO();
}

Player::~Player()
{
    delete[] videos;
    delete ioWorker;
}

void Player::Fill()
{
    for (int i = 0; i < videoCount; i++)
    {
        cout << "\n--- Відео #" << (i + 1) << " ---";
        ioWorker->Input(videos[i]);
    }
}

void Player::ShowAll()
{
    cout << "\nСписок усіх фільмів у бібліотеці:\n";
    for (int i = 0; i < videoCount; i++)
        ioWorker->Output(videos[i]);
}

void Player::SearchByActor()
{
    cout << "\nВведіть ім'я актора (можна частково): ";
    string query = ConsolIO::GetText(cin);

    bool found = false;
    cout << "\nФільми за участю \"" << query << "\":\n";
    for (int i = 0; i < videoCount; i++)
    {
        if (videos[i].matchesActor(query))
        {
            ioWorker->Output(videos[i]);
            found = true;
        }
    }
    if (!found)
        cout << "\tНічого не знайдено.\n";
}

void Player::SearchByTitle()
{
    cout << "\nВведіть назву (можна частково): ";
    string query = ConsolIO::GetText(cin);

    bool found = false;
    cout << "\nФільми з назвою, що містить \"" << query << "\":\n";
    for (int i = 0; i < videoCount; i++)
    {
        if (videos[i].matchesTitle(query))
        {
            ioWorker->Output(videos[i]);
            found = true;
        }
    }
    if (!found)
        cout << "\tНічого не знайдено.\n";
}

void Player::SearchByTheme()
{
    cout << "\nВведіть тему (можна частково): ";
    string query = ConsolIO::GetText(cin);

    bool found = false;
    cout << "\nФільми теми, що містить \"" << query << "\":\n";
    for (int i = 0; i < videoCount; i++)
    {
        if (videos[i].matchesTheme(query))
        {
            ioWorker->Output(videos[i]);
            found = true;
        }
    }
    if (!found)
        cout << "\tНічого не знайдено.\n";
}

void Player::PrintMenu() const
{
    cout << "\n========= МЕНЮ =========\n";
    cout << "1. Показати всі фільми\n";
    cout << "2. Пошук за актором\n";
    cout << "3. Пошук за назвою\n";
    cout << "4. Пошук за темою\n";
    cout << "0. Вихід\n";
    cout << "Ваш вибір: ";
}

void Player::Run()
{
    int choice;
    do
    {
        PrintMenu();
        choice = ConsolIO::GetIntInRange(cin, 0, 4);

        switch (choice)
        {
        case 1: ShowAll();       break;
        case 2: SearchByActor(); break;
        case 3: SearchByTitle(); break;
        case 4: SearchByTheme(); break;
        case 0: cout << "\nЗавершення роботи.\n"; break;
        }
    } while (choice != 0);
}
