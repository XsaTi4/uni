#ifndef INPUT_HPP
#define INPUT_HPP

#include <termios.h>
#include <unistd.h>

inline char getch() {
  termios oldSettings{};
    tcgetattr(STDIN_FILENO, &oldSettings);

    termios newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    char key{};
    read(STDIN_FILENO, &key, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    return key;
}

#endif