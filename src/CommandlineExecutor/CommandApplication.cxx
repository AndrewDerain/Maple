
#include "CommandApplication.hxx"


namespace CommandlineExecutor
{

    std::map<String, std::function<CommandExecuteResult(int, char*[])>> CommandApplication::RootOptions
    {
        { "--version", CommandApplication::Version },
        { "-v",        CommandApplication::Version },
        { "--help",    CommandApplication::Help },
        { "-h",        CommandApplication::Help }
    };


    std::map<String, std::function<CommandExecuteResult(int, char*[])>> CommandApplication::RootCommands
    {
        {"new", CommandApplication::New }
    };


    bool CommandApplication::IsOption(char* arg) {

        if(strlen(arg) < 1) {
            return false;
        }

        if(arg[0] == '-') {
            return true;
        }

        return false;
    }


    CommandExecuteResult CommandApplication::Run(int argc, char* argv[]) {

        if(argc == 1) {
            return Version(argc, argv);
        }

        if(IsOption(argv[1])) {
            auto OptionIter = RootOptions.find(argv[1]);

            if(OptionIter == RootOptions.end()) {
                std::cout << "No such option: " << argv[1] << std::endl;
                return CommandExecuteResult::NoSuchOption;
            }

            return OptionIter->second(argc, argv);
        }
        else {
            auto CommandIter = RootCommands.find(argv[1]);

            if(CommandIter == RootCommands.end()) {
                std::cout << " No such command：" << argv[1] << std::endl;
                return CommandExecuteResult::NoSuchCommand;
            }

            return CommandIter->second(argc, argv);
        }
    }


    CommandExecuteResult CommandApplication::Version(int argc, char* argv[]) {

        std::cout << "maple version 0.0.0.0" << std::endl;
        std::cout << std::endl;
        std::cout << "Maple Framework maintained and supported by: "     << std::endl
                  << "AndrewDerain (https://github.com/AndrewDerain). "     << std::endl
                  << "GitHub: https://github.com/AndrewDerain/Maple "    << std::endl
                  << "E-mail: locomoco@yeah.net "                           << std::endl
                  << std::endl;

        return CommandExecuteResult::Success;
    }


    CommandExecuteResult CommandApplication::Help(int argc, char* argv[]) {

        std::stringstream content;

        // title
        content << "                                            " << std::endl
                << "  ------- maple usage manual ---------   " << std::endl;

        // usage brief
        content << "                                            " << std::endl
                << "Usage                                       " << std::endl
                << "    maple [Options]                      " << std::endl
                << "    maple [Command] [Command Options]    " << std::endl;

        // root options
        content << "                                                                " << std::endl
                << "Options                                                         " << std::endl
                << "    --version, -v           = Print version of framework.       " << std::endl
                << "    --help, -h              = Print usage information.          " << std::endl;

        // print commands usage from here
        content << "                                                                " << std::endl
                << "Commands                                                        " << std::endl;

        // command new
        content << "    new                     = Create new project from template. " << std::endl
                << "      --template, -t <name> -> Indicate project template name.  " << std::endl
                << "      --name, -n <name>     -> Set the name of your project.    " << std::endl;

        std::cout << content.str() << std::endl;
        return CommandExecuteResult::Success;
    }


    CommandExecuteResult CommandApplication::New(int argc, char* argv[]) {
        std::cout << "new project" << std::endl;

        //if(argc < )

        return CommandExecuteResult::Success;
    }
};
