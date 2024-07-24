#include "gamecontroller.h"
#include "conio.h"
#include "gameconfig.h"
#include <iostream>

GameController::GameController()
    : m_GameScene{std::make_shared<GameScene>()}
{

}

void GameController::beginPlay()
{
    m_GameScene->resetGame();
    m_GameScene->refreshDisplay();
    eventListeningLoop();
}

bool GameController::validateComplete() const
{
    bool complete = m_GameScene->checkComplete();
    if(complete){
        return true;
    }
    else{
        return false;
    }
}

void GameController::eventListeningLoop()
{
    char pressedKey{'\0'};
    while(true){
        pressedKey = getchFromTerminal();

        if(pressedKey >= '0' && pressedKey <= '9'){
            GameCommand command{m_GameScene, m_GameScene->getCursor(), pressedKey - '0'};
            command.execute();
            m_CommandStack.push(std::move(command));

        }
        else{
            switch(pressedKey){
            case 'w':
                moveCursorByOffset(-1, 0);
                break;
            case 's':
                moveCursorByOffset(1, 0);
                break;
            case 'a':
                moveCursorByOffset(0, -1);
                break;
            case 'd':
                moveCursorByOffset(0, 1);
                break;
            case 13:
                if(validateComplete()){
                    std::cout << GameConfig::instance()->getMsgMap().at(Message::CONGRATULATION);
                    return;
                }
                else{
                    std::cout << GameConfig::instance()->getMsgMap().at(Message::NOT_COMPLETED);
                    continue;
                }
                break;
            }
        }

        m_GameScene->refreshDisplay();

    }
}

int GameController::getchFromTerminal() const
{
    return getch();
}

void GameController::moveCursorByOffset(int row_offset, int col_offset)
{
    Point updatedCursor {m_GameScene->getCursor().row + row_offset, m_GameScene->getCursor().col + col_offset };
    static auto validateCursor = [](Point cursor){
        if(cursor.row < 0 || cursor.row >= 9){
            return false;
        }
        if(cursor.col < 0 || cursor.col >= 9){
            return false;
        }

        return true;
    };

    if(!validateCursor(updatedCursor)){
        return;
    }

    m_GameScene->setCursor(updatedCursor);
}
