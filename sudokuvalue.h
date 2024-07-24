#ifndef SUDOKUVALUE_H
#define SUDOKUVALUE_H

constexpr int UNSELECTED_VALUE{0};

struct Point{
    int row{};
    int col{};
};

enum class ValueState{
    Init,
    Erased
};


class SudokuValue
{
public:
    SudokuValue(int value, ValueState state);

    inline ValueState getState() const{
        return m_State;
    }

    inline void setState(ValueState state){
        m_State = state;
    }

    inline int getValue() const{
        return m_Value;
    }

    inline void setValue(int value){
        m_Value = value;
    }

private:

    int m_Value{};
    ValueState m_State{};
};

#endif // SUDOKUVALUE_H
