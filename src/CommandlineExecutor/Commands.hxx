#pragma once
#include "Fantasia/Foundation"
#include <map>
#include <functional>


namespace CommandlineExecutor
{
    using namespace Fantasia::Foundation;


    struct CommandExecuteResult
    {
        enum EnumUnifyTypeName {
            Success,
            NoSuchOption,
            NoSuchCommand
        };

        EnumBasicActions(CommandExecuteResult,
            Success,
            NoSuchOption,
            NoSuchCommand
        );
    };


    class CommandApp
    {
    public:
        static CommandExecuteResult Run(int argc, char* argv[]);
    

    protected:
        static std::map<String, std::function<CommandExecuteResult(int, char*[])>> RootOptions;
        static std::map<String, std::function<CommandExecuteResult(int, char*[])>> RootCommands;


        /// @brief 判断命令行的参数是不是选项
        /// 以 “--” 或 “-” 开始的字符串被认为是选项
        static bool IsOption(char* arg);


        /// @brief 输出当前程序版本
        /// $ fantasia --version
        /// $ fantasia -v
        static CommandExecuteResult Version(int argc, char* argv[]);


        /// @brief 输出帮助文档
        /// $ fantasia --help
        /// $ fantasia -h
        static CommandExecuteResult Help(int argc, char* argv[]);


        /// @brief 新建项目
        /// $ fantasia new -n my_project
        /// $ fantasia new --template console --name my_project
        /// $ fantasia new -t console -n my_project
        static CommandExecuteResult New(int argc, char* argv[]);
    };
};

/*
 * platform
 *
 * deps:
 *  name version
 *
 */