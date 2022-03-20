#pragma once
#include <Fantasia.Foundation>
#include <map>
#include <functional>


namespace CommandlineExecutor
{
    using namespace Fantasia::Foundation;


    class CommandApp
    {
    public:
        static int Run(int argc, char* argv[]);
    

    protected:
        static std::map<String, std::function<int(int, char*[])>> CmdMap;

        /// @brief 判断命令行的参数是不是选项
        /// 以 “--” 或 “-” 开始的字符串被认为是选项
        static bool IsOption(char* arg);


        /// @brief 判断命令行的参数是不是值
        /// 不以 “--” 或 “-” 开始的字符串被认为是值；
        /// 双引号“”包裹的字符串被认为是值，即便含有 “--”，或 “-”
        static bool IsValue(char* arg);


        /// @brief 输出当前程序版本
        /// $ fantasia --version
        static int Version(int argc, char* argv[]);


        static int New(int argc, char* argv[]);
    };
};
