## SudokuCpp 控制台数独游戏
> 参考了 https://github.com/mayerui/sudoku的实现

### 编译
要求编译器为支持C++20(主要是std::format)的MSVC或GCC编译器。
即MSVC2019或GCC 13以上版本。

### 变化
- 程序内去除了指针，使用std::shared_ptr管理每个单元和格网。
- 随机数使用了Modern C++风格的std::random_engine和std::random_distribution产生。
- 分离Controller和Scene
- 使用单例GameConfig控制游戏设定。

### 操作
目前，程序运行后直接进入游戏，使用 WASD进行操作，按下Enter键检验是否完成。

### TODO
- 语言、难度等设定
- 提交出错的位置提示
- ......

