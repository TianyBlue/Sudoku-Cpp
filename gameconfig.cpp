#include "gameconfig.h"

GameConfig* GameConfig::m_Instance{new GameConfig};

static const std::map<Message, std::string> chineseMessage{
    {Message::ASK_KEY_MAP, "设置按键模式: 1 WASD 2 VIM"},
    {Message::INPUT_ERROR, "输入错误!"},
    {Message::LOAD_PROGRESS_FAIL, "加载存档失败!"},
    {Message::ASK_QUIT, "退出游戏? [Y/N]"},
    {Message::ASK_SAVE, "保存进度? [Y/N]"},
    {Message::ASK_SAVE_PATH, "输入存档文件路径:"},
    {Message::FILE_EXIST_ERROR, "文件已存在"},
    {Message::CONTINUE, "继续"},
    {Message::UNDO_ERROR, "没有可以撤销的动作"},
    {Message::CONGRATULATION, "恭喜! 你解开了谜题!"},
    {Message::NOT_COMPLETED, "对不起, 还未完成"},
    {Message::ASK_DIFFICULTY, "设置难度: 1简单 2普通 3困难"},
};

static const std::map<Difficulty, std::size_t> difficultyEarseCountMap{
    {Difficulty::Easy, 20},
    {Difficulty::Normal, 25},
    {Difficulty::Hard, 30},
};


void GameConfig::setLanguage(Language language)
{
    m_Language = language;
}

const std::map<Message, std::string> &GameConfig::getMsgMap() const
{
    switch(m_Language){
    case Language::Chinese:
        return const_cast<const std::map<Message, std::string>&>(chineseMessage);
    default:
        return const_cast<const std::map<Message, std::string>&>(chineseMessage);
    }
}

void GameConfig::setDifficulty(Difficulty difficulty)
{
    m_Difficulty = difficulty;
    m_GameEraseCellCount = difficultyEarseCountMap.at(m_Difficulty);
}

GameConfig::GameConfig()
{

}
