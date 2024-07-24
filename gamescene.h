#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "sudokuvalue.h"
#include <memory>
#include <array>
#include "sudokublock.h"
#include <concepts>
#include <string>

template<typename T>
concept BLOCKS_CONTAINER = requires(T t){
    typename T::iterator;
    typename T::value_type;
    (*t.begin()).clear();
};


class GameScene
{
public:
    GameScene();

    void resetGame();
    void refreshDisplay() const;
    bool checkComplete() const;
    void setValue(Point pos, int number);
    void setCursor(Point pos);
    inline Point getCursor() const{
        return m_CursorPoint;
    }
    inline int getValue(Point pos) const{
        return m_GameValues[pos.row][pos.col]->getValue();
    }

private:

    void reRandomGameValues();
    void reEraseRandomValues(int erase_count);
    void resetAllBlocks();

    template<BLOCKS_CONTAINER Container>
    void clearBlocks(Container& arraylike_blocks) const;

    int getRandomNumber(int low, int high) const;

    // 打印间隔行，如果line_idx != -1 则检查cursor是否在当前行
    void printUnderLine(int line_idx = -1) const;
    void cls() const;

    Point m_CursorPoint;

    std::array<std::array<std::shared_ptr<SudokuValue>, 9>, 9> m_GameValues;
    std::array<SudokuLineBlock, 9> m_LineBlocks;
    std::array<SudokuColumnBlock, 9> m_ColumnBlocks;
    std::array<SudokuRectBlock, 9> m_RectBlocks;
};

template<BLOCKS_CONTAINER Container>
void GameScene::clearBlocks(Container &arraylike_blocks) const
{
    for(auto& block : arraylike_blocks){
        block.clear();
    }
}
#endif // GAMESCENE_H
