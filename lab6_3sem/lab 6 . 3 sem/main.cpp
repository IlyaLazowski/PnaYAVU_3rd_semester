#include <iostream>
#include <windows.h>
#include "Menu.cpp"

int main() {
    system("color E1");
    setlocale(LC_ALL, "RUS");
    Menu a{};
    a.start();
    return 0;
}