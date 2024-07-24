#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "gamescene.h"
#include "gamecommand.h"
#include <memory>
#include <stack>
#include <vector>

class GameController
{
public:
    GameController();

    void beginPlay();

private:
    bool validateComplete() const;
    void eventListeningLoop();

    int getchFromTerminal() const;
    void moveCursorByOffset(int row_offset, int col_offset);

    std::stack<GameCommand, std::vector<GameCommand>> m_CommandStack;
    std::shared_ptr<GameScene> m_GameScene;
};

#endif // GAMECONTROLLER_H
