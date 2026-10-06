#include "Player.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Player library;
    library.Fill();
    library.Run();

    return 0;
}
