#pragma once
#include "Basic.CodeLang.CXX.hxx"
#include "Basic.Macro.Decorate.hxx"


__FANTASIA_DETAIL_BEGIN

class Tracer
{
public:
    Tracer() {
        _Brief.ThreadID     = std::this_thread::get_id();
        _Brief.SerialNumber = ++SerialNumberCounter;
        _Brief.Hierarchy    = 0;
    };


    Tracer(Tracer& tracer) {
        _Brief      = tracer._Brief;
        _Parent     = tracer._Parent;
        _Signature  = tracer._Signature;
    }


    template<size_t _Size>
    Tracer(const char (&signature)[_Size]) {
        _Signature = signature;
    
        _WriteScopStart();
    }


    template<size_t _Size>
    Tracer(const char (&signature)[_Size], const Tracer& parent) {
        _Signature = signature;

        _Parent = parent._Brief;
    }


    ~Tracer() {
        _WriteScopEnd();
    }


    void WriteLine(const std::string& line) {
        std::stringstream content;
        _GenLineHead(content);
        content << " | " << line ;
        _WriteLine(content.str());
    }


    template<typename _T>
    void WriteVar(const char* var_name, _T& var) {
        std::cout << " |  Var [" << var_name << "] = [" << var << "]" << std::endl;
    }


private:
    struct Brief
    {
        std::thread::id ThreadID;
        int64_t         SerialNumber;
        int64_t         Hierarchy;
    };

    struct LineContent
    {

    };

    __api
    static std::atomic_int64_t SerialNumberCounter;


    std::string _Signature;


    Brief _Brief;


    Brief _Parent;


    inline 
    void _GenLineHead(std::stringstream& content) const noexcept {
        content 
            << "[ti:" << _Brief.ThreadID << "] " 
            << "[hc:" << _Brief.Hierarchy << "] "
            << "[sn:" << _Brief.SerialNumber << "] "
            << "[si:" << _Signature << "] ";
    }


    inline 
    void _WriteScopStart() const noexcept {
        std::stringstream content;
        _GenLineHead(content);
        content << " ---  -> start";
        _WriteLine(content.str());
    }


    inline 
    void _WriteScopEnd() const noexcept {
        std::stringstream content;
        _GenLineHead(content);
        content << " ---  -> end";
        _WriteLine(content.str());
    }

    
    inline 
    void _WriteLine(const std::string& content) const noexcept {
        std::cout << content << std::endl;
    }
};


#ifdef _FANTASIA_TRACE
#    define TraceArg , ___ParentTracer
#    define TraceScope Fantasia::Tracer ___Tracer(__PRETTY_FUNCTION__);
#    define TraceScopeAndCallStack \
    Fantasia::Tracer ___Tracer(__PRETTY_FUNCTION__, ___ParentTracer);
#    define TraceWriteVar(_Val) \
        std::cout << " |  Var [" << #_Val << "] = [" << _Val << "]" << std::endl;
#else
#    define TraceScope
#    define TraceWriteVar(_Val)
#endif

__FANTASIA_DETAIL_END
