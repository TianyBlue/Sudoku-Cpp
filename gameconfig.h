#ifndef GAMECONFIG_H
#define GAMECONFIG_H
#include <map>
#include <string>

enum class Language{
    Chinese
};

enum class Message{
    ASK_KEY_MAP,
    INPUT_ERROR,
    LOAD_PROGRESS_FAIL,
    ASK_QUIT,
    ASK_SAVE,
    ASK_SAVE_PATH,
    FILE_EXIST_ERROR,
    CONTINUE,
    UNDO_ERROR,
    CONGRATULATION,
    NOT_COMPLETED,
    ASK_DIFFICULTY
};

enum class Difficulty{
    Easy,
    Normal,
    Hard
};


constexpr char CORNER[] = "\u254B"; // 十字 ＋
constexpr char LINE[] = "\u2501"; // 横 -
constexpr char PIPE[] = "\u2503"; // 竖 |
constexpr char ARROW[] = "^";


class GameConfig
{
public:
    static GameConfig* instance(){
        return m_Instance;
    }

    void setLanguage(Language language);
    inline Language getLanguage() const{
        return m_Language;
    }

    // 也可使用reference_wrapper实现动态更换引用
    const std::map<Message, std::string>& getMsgMap() const;

    inline void setEraseCount(std::size_t erase_count){
        m_GameEraseCellCount = erase_count;
    }

    inline std::size_t getEraseCount() const{
        return m_GameEraseCellCount;
    }

    void setDifficulty(Difficulty difficulty);
    inline Difficulty getDifficulty() const{
        return m_Difficulty;
    }


private:
    GameConfig();

    Language m_Language{Language::Chinese};
    std::size_t m_GameEraseCellCount{20};
    Difficulty m_Difficulty{Difficulty::Normal};

    static GameConfig* m_Instance;
};

#endif // GAMECONFIG_H
