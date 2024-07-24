#include "gamecommand.h"

GameCommand::GameCommand()
{

}

GameCommand::GameCommand(const std::shared_ptr<GameScene> &scene, Point pos, int new_value)
    : m_GameScene{scene}, m_CommandPos{pos}, m_ExecuteValue{new_value}
{

}

void GameCommand::execute()
{
    if(!m_GameScene){
        return;
    }

    m_PrevValue = m_GameScene->getValue(m_CommandPos);
    m_GameScene->setValue(m_CommandPos, m_ExecuteValue);
}

void GameCommand::undo()
{
    if(!m_GameScene){
        return;
    }

    m_GameScene->setValue(m_CommandPos, m_PrevValue);
}
