#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

char getch()
{
    termios oldSettings{};
    termios newSettings{};

    // Сохраняем текущие настройки терминала
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;

    // Отключаем ожидание Enter и отображение введённого символа
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    char key;
    read(STDIN_FILENO, &key, 1);

    // Восстанавливаем настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return key;
}

int main()
{
    cout << "Press a key: " << flush;

    char key = getch();

    cout << "\nYou entered: " << key << '\n';
    return 0;
}