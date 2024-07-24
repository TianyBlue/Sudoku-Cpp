#include "gamescene.h"
#include "gameconfig.h"
#include <iostream>
#include <random>
#include <unordered_map>
#include <set>
#include <stdlib.h>
#include <windows.h>

GameScene::GameScene()
{

}

void GameScene::resetGame()
{
    reRandomGameValues();
    reEraseRandomValues(GameConfig::instance()->getEraseCount());
    resetAllBlocks();
}

void GameScene::refreshDisplay() const
{
    cls();
    printUnderLine();

    for(int line_idx{}; auto& lineBlock : m_LineBlocks){
        lineBlock.print();
        printUnderLine(line_idx);
        ++line_idx;
    }
}

void GameScene::reRandomGameValues()
{
    // XXX: pseudo random
    static char map_pattern[10][10] {
        "ighcabfde",
        "cabfdeigh",
        "fdeighcab",
        "ghiabcdef",
        "abcdefghi",
        "defghiabc",
        "higbcaefd",
        "bcaefdhig",
        "efdhigbca"
    };

    std::vector<char> charList {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    std::unordered_map<char, int> charMap;
    for(int i{1}; i <= 9; ++i){
        int idx = getRandomNumber(0, charList.size() - 1);
        charMap.emplace(charList[idx], i);

        charList.erase(charList.begin() + idx);
    }

    for(int row{}; row < 9; ++row){
        for(int col{}; col < 9; ++col){
            m_GameValues[row][col] = std::make_shared<SudokuValue>(charMap[map_pattern[row][col]], ValueState::Init);
        }
    }
}

void GameScene::reEraseRandomValues(int erase_count)
{
    std::set<int> erased_idx;
    while(erased_idx.size() < erase_count){
        erased_idx.emplace(getRandomNumber(0, 80));
    }

    for(auto idx : erased_idx){
        int row = idx / 9;
        int col = idx % 9;

        m_GameValues[row][col]->setState(ValueState::Erased);
        m_GameValues[row][col]->setValue(UNSELECTED_VALUE);
    }
}

void GameScene::resetAllBlocks()
{
    clearBlocks(m_LineBlocks);
    clearBlocks(m_ColumnBlocks);
    clearBlocks(m_RectBlocks);

    for(int row{}; row < 9; ++row){
        int rowBlockIdx = row / 3;
        for(int col{}; col < 9; ++col){
            int colBlockIdx = col / 3;

            m_LineBlocks[row].push(m_GameValues[row][col]);
            m_ColumnBlocks[col].push(m_GameValues[row][col]);

            m_RectBlocks[rowBlockIdx * 3 + colBlockIdx].push(m_GameValues[row][col]);
        }
    }
}

bool GameScene::checkComplete() const
{
    for(auto& line_block : m_LineBlocks){
        if(!line_block.isValid()){
            return false;
        }
    }

    for(auto& col_block : m_ColumnBlocks){
        if(!col_block.isValid()){
            return false;
        }
    }

    for(auto& rect_block : m_RectBlocks){
        if(!rect_block.isValid()){
            return false;
        }
    }

    return true;
}

void GameScene::setValue(Point pos, int number)
{
    m_GameValues[pos.row][pos.col]->setValue(number);
}

void GameScene::setCursor(Point pos)
{
    m_CursorPoint = pos;
}

int GameScene::getRandomNumber(int low, int high) const
{
    static std::random_device seeder;
    static std::mt19937 engine{static_cast<std::mt19937::result_type>(seeder.entropy())};
    std::uniform_int_distribution distribution{low, high};

    return distribution(engine);
}

void GameScene::printUnderLine(int line_idx) const
{
    if(line_idx != m_CursorPoint.row){
        for(int col{}; col < 9; ++col){
            std::cout << CORNER << LINE << LINE << LINE;
        }
        std::cout << CORNER << std::endl;
    }
    else{
        for(int col{}; col < m_CursorPoint.col; ++col){
            std::cout << CORNER << LINE << LINE << LINE;
        }

        std::cout << CORNER << LINE << ARROW << LINE;

        for(int col{m_CursorPoint.col + 1}; col < 9; ++col){
            std::cout << CORNER << LINE << LINE << LINE;
        }

        std::cout << CORNER << std::endl;
    }
}

void GameScene::cls() const
{
#if defined(_MSC_VER) && defined(_WIN32)
    system("cls");
#elif defined(_MSC_VER) && defined(__linux__)
    system("clear");
#else
    std::cout << "\033[2J\033[H";
#endif
}


