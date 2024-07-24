#ifndef SudokuBLOCK_H
#define SudokuBLOCK_H
#include <memory>
#include "sudokuvalue.h"
#include <vector>

class SudokuBlockBase
{
public:
    SudokuBlockBase();

    void push(const std::shared_ptr<SudokuValue>& value);
    bool isValid() const;
    virtual void print() const = 0;

    void clear();

protected:
    std::vector<std::shared_ptr<SudokuValue>> m_ValueBlock;
};

class SudokuLineBlock : public SudokuBlockBase{
public:
    void print() const override;
};


class SudokuColumnBlock : public SudokuBlockBase{
public:
    void print() const override;
};

class SudokuRectBlock : public SudokuBlockBase{
public:
    void print() const override;
};










#endif // SudokuBLOCK_H
