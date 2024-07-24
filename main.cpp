#include <Windows.h>
#include "utils.h"
#include "gamecontroller.h"

int main(int argc, char *argv[])
{
    
    Utils::setSystemEnv();

    GameController controller;
    controller.beginPlay();

    return 0;
}
