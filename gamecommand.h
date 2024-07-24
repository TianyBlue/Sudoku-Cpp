#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include "gamescene.h"
#include <memory>
#include "sudokuvalue.h"

class GameCommand
{
public:
    GameCommand();
    GameCommand(const std::shared_ptr<GameScene> &scene, Point pos, int new_value);

    void execute();
    void undo();

private:
    std::shared_ptr<GameScene> m_GameScene;
    Point m_CommandPos;
    int m_PrevValue;
    int m_ExecuteValue;
};

#endif // GAMECOMMAND_H
