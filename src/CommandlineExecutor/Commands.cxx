#include "Commands.hxx"


namespace CommandlineExecutor
{
    std::map<String, std::function<int(int, char*[])>> CommandApp::CmdMap 
    {
        { "--version",  CommandApp::Version},
        { "-v",         CommandApp::Version},

        { "new",        CommandApp::New }
    };



    int CommandApp::Run(int argc, char* argv[]) {

        if(argc == 1) {
            return 0;
        }

        auto CmdIter = CmdMap.find(argv[1]);

        if(CmdIter == CmdMap.end()) {
            std::cout << " 没有此命令：" << argv[1] << std::endl;
            return -1;
        }
        
        return CmdIter->second(argc, argv);
    }


    // --version
    int CommandApp::Version(int argc, char* argv[]) {

        std::cout << "fantasia version 0.0.0.0" << std::endl;
        std::cout << std::endl;
        std::cout << "Fantasia Framework maintained and supported by: "     << std::endl
                  << "AndrewDerain (https://github.com/AndrewDerain). "      << std::endl
                  << "GitHub: https://github.com/AndrewDerain/Fantasia "    << std::endl
                  << "E-mail: locomoco@yeah.net "                           << std::endl
                  << std::endl;

        return 0;
    }


    // new --templateconsole --name=
    int CommandApp::New(int argc, char* argv[]) {
        std::cout << "new project" << std::endl;

        //if(argc < )

        return 0;
    }
};
