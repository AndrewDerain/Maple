
# Fantasia Framework


# 这是什么？
这个项目是我自己学习 C++ 的一个实践项目，以个人的喜好打造的，从基本的数据（包括 Int64，Float64，IPC 等等）开始构建的一个 C++ 开发框架。

Fantasia（幻曲）， 这个名字意味着这个库可能永远也不会真正完成。这个库的第一个版本也并没有计划的完成时间以及会包含多少东西。


# 目录结构

## 概述

|类型| 文件夹| 说明 | Git 管理 |
|----|------|------|:----------:|
|文件夹|.buildcache|cmake 配置缓存|无，CMake自动生成|
|文件夹|.vscode|Visual Studio Code 配置文件|有|
|文件夹|Compiled|此项目生成的可执行文件和库文件|有|
|文件夹|Include|对外提供的包含目录|有|
|文件夹|Source|源代码|有|
|文件夹|UnitTest|单元测试|有|
||||

## 文件

|类型| 文件| 说明 |
|------|-------|-----------------|
|markdown|[readme.md](readme.md)|项目概览说明文件
|CMake|[CMakeLists.txt](CMakeLists.txt)|顶层 CMake 项目管理文件
|CMake|[CMakeSettings.json](CMakeSettings.json)|Visual Studio CMake 项目配置文件
||||


# 编译项目

1. 创建目录，并下载此项目
``` shell
    mkdir ~/project
    cd ~/project
    git clone https://github.com/AndrewDerain/Fantasia.git
```

2. 创建 cmake build 缓存
``` shell
    cmake -S . -B .buildcache
```

3. 编译项目，程序会在 Compiled 文件夹中生成
``` shell
    cmake --build .buildcache
```


# 代码原则

**简化语法**
    
- 用最简单的C++语法，完成目标。

**语言及工具版本**

- C++ 20
- CMake 3.20

**代码即注释！**

- 如果你写的类的公开部分代码（public，protected）不能够让读者一眼看出来是做什么用的，请重构，反复斟酌每一个函数名，变量名。

**词性与类型名字的含义**
 | 类型 | 含义|词性  | 例子  |
 |-----|:----|:-----:|:------|   
 | 接口 |描述“可以做什么”| 形容词短语| IRunnable|
 | 类 |描述“是什么” |  名词短语| Runner |
 | 函数 |定义“做什么”| 动词短语| Run, Stop |
 | 属性 |描述“状态”|名词短语 | Status, Height, Width|

**保持命名空间干净**

- Fantasia 命名空间只包含库的使用者需要用的东西，其余的放到 _Fantasia 命名空间里。

**整数**
    
- 此项目中优先使用64位整数，不要单纯只是为了节省空间而节省空间。
- 不要使用无符号整数，避免无符号数和有符号数之间的转换。

**浮点数**

- 此项目优先使用64位浮点数。
- 请使用 Float64 类型进行浮点数运算和大小比较，此类型可以直接使用 `==, <=, >=, >, <` 符号来比较浮点数的大小

**枚举**

- 枚举优先使用64位整数，使用结构体进行包装，借助 EnumUnifyTypeName 和 EnumBasicActions 宏进行包装。
``` c++
// 交易方向
struct TradeDirection
{
    enum EnumUnifyTypeName 
    {
        /// @brief 买入开仓
        BuyOpen,

        /// @brief 买入平仓
        BuyClose,

        /// @brief 卖出开仓
        SellOpen,

        /// @brief 卖出平仓
        SellClose
    };

    EnumBasicActions(TradeDirection, 
        BuyOpen, BuyClose, SellOpen, SellClose
    )

    bool IsBuy() {
        return _Value == BuyOpen || _Value == BuyClose;
    }

    bool IsSell() {
        return _Value == SellOpen || _Value == SellClose;
    }

    bool IsOpen() {
        return _Value == BuyOpen || _Value == SellOpen;
    }

    bool IsClose() {
        return _Value == BuyClose || _Value == SellClose;
    }
};

int main() {
    TradeDirection Direction;
    Direction = Direction.BuyOpen; // 现在你可以使用这样的语法对枚举进行赋值

    if(Direction.IsBuy()) // 调用枚举中的函数

    switch(Direction) {   // 在 swith 中如原生枚举一般使用 TradeDirection 的对象
        case TradeDirection::BuyOpen:
            /// ...
            break;
    }
}
```

**类中成员的定义顺序**
``` c++
class YourClass 
{
// 公开的类型定义，使用 using 替代旧版本的 typedef 以定义新的类型
public:
    // using ...

// 构造函数，析构函数
public:
    YourClass();
    ~YourClass();

    YourClass(...);
    YourClass(...);

public:

};
```


# 致谢
> 仅以此项目，献给一直支持和鼓励我的韦女士 :)
