#include "sudokublock.h"
#include <set>
#include "gameconfig.h"
#include <iostream>
#include "colormodifier.h"
#include <string>

SudokuBlockBase::SudokuBlockBase()
{

}

void SudokuBlockBase::push(const std::shared_ptr<SudokuValue> &value)
{
    m_ValueBlock.push_back(value);
}

bool SudokuBlockBase::isValid() const
{
    if(m_ValueBlock.size() != 9){
        return false;
    }

    std::set<int> existedValue;
    for(auto& value : m_ValueBlock){
        if(value->getValue() == UNSELECTED_VALUE){
            return false;
        }
        if(existedValue.contains(value->getValue())){
            return false;
        }
        existedValue.emplace(value->getValue());
    }

    return true;
}

void SudokuBlockBase::clear()
{
    m_ValueBlock.clear();
}

void SudokuLineBlock::print() const
{
    using std::cout;
    using std::endl;

    cout << PIPE;
    for(auto& value : m_ValueBlock){
        if(value->getValue() == UNSELECTED_VALUE){
            cout << "   " << PIPE;
        }else{
            if(value->getState() == ValueState::Erased){
                cout << " " << ColorModifier::toColoredStr(ColorCode::FG_GREEN, std::to_string(value->getValue())) << " " << PIPE;
            }
            else{
                cout << " " << value->getValue() << " " << PIPE;
            }
        }
    }
    cout << endl;
}

void SudokuColumnBlock::print() const
{

}

void SudokuRectBlock::print() const
{

}
