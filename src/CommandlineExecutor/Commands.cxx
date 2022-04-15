#include "Commands.hxx"


namespace CommandlineExecutor
{

    std::map<String, std::function<CommandExecuteResult(int, char*[])>> CommandApp::RootOptions
    {
        { "--version",  CommandApp::Version },
        { "-v",         CommandApp::Version },
        { "--help",     CommandApp::Help },
        { "-h",         CommandApp::Help }
    };


    std::map<String, std::function<CommandExecuteResult(int, char*[])>> CommandApp::RootCommands
    {
        { "new",        CommandApp::New }
    };


    bool CommandApp::IsOption(char* arg) {

        if(strlen(arg) < 1) {
            return false;
        }

        if(arg[0] == '-') {
            return true;
        }

        return false;
    }


    CommandExecuteResult CommandApp::Run(int argc, char* argv[]) {

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


    CommandExecuteResult CommandApp::Version(int argc, char* argv[]) {

        std::cout << "fantasia version 0.0.0.0" << std::endl;
        std::cout << std::endl;
        std::cout << "Fantasia Framework maintained and supported by: "     << std::endl
                  << "AndrewDerain (https://github.com/AndrewDerain). "     << std::endl
                  << "GitHub: https://github.com/AndrewDerain/Fantasia "    << std::endl
                  << "E-mail: locomoco@yeah.net "                           << std::endl
                  << std::endl;

        return CommandExecuteResult::Success;
    }


    CommandExecuteResult CommandApp::Help(int argc, char* argv[]) {

        std::stringstream content;

        // title
        content << "                                            " << std::endl
                << "  ------- fantasia usage manual ---------   " << std::endl;

        // usage brief
        content << "                                            " << std::endl
                << "Usage                                       " << std::endl
                << "    fantasia [Options]                      " << std::endl
                << "    fantasia [Command] [Command Options]    " << std::endl;

        // root options
        content << "                                                                " << std::endl
                << "Options                                                         " << std::endl
                << "    --version, -v           = Print version of framework.       " << std::endl
                << "    --help, -h              = Print usage information.          " << std::endl;

        // print commands usage from here
        content << "                                                                " << std::endl
                << "Commands                                                        " << std::endl;

        // command new
        content << "    new                     = Create new project from resource. " << std::endl
                << "      --resource, -t <name> -> Indicate project resource name.  " << std::endl
                << "      --name, -n <name>     -> Set name of the new project.     " << std::endl;

        std::cout << content.str() << std::endl;
        return CommandExecuteResult::Success;
    }


    CommandExecuteResult CommandApp::New(int argc, char* argv[]) {
        std::cout << "new project" << std::endl;

        //if(argc < )

        return CommandExecuteResult::Success;
    }
};
