#pragma once
#include "Basic.CodeLang.CXX.hxx"
#include "Basic.Macro.Preconfig.hxx"


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
___FANTASIA_DETAIL_BEGIN

class Tracer
{
public:
    ___FANTASIA_API
    Tracer();


    Tracer(const Tracer& tracer): Tracer() {
        _Brief      = tracer._Brief;
        _Parent     = tracer._Parent;
        _Signature  = tracer._Signature;
    }


    template<size_t _Size>
    Tracer(const char (&signature)[_Size]): Tracer() {
        _Signature = signature;
    
        _WriteScopStart();
    }


    template<size_t _Size>
    Tracer(const char (&signature)[_Size], const Tracer& parent): Tracer() {
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
        _WriteLine(content.str().c_str());
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


    /// @brief 函数签名
    const char* _Signature;


    /// @brief 域信息
    Brief _Brief;


    /// @brief 父域信息
    Brief _Parent;

 
    ___FANTASIA_ALWAYS_INLINE
    void _GenLineHead(std::stringstream& content) const noexcept {
        content 
            << "[ti:" << _Brief.ThreadID << "] " 
            << "[hc:" << _Brief.Hierarchy << "] "
            << "[sn:" << _Brief.SerialNumber << "] "
            << "[si:" << _Signature << "] ";
    }


    ___FANTASIA_API 
    void _WriteScopStart() const noexcept;


    ___FANTASIA_API 
    void _WriteScopEnd() const noexcept;

    
    ___FANTASIA_API 
    static void _WriteLine(const char* content) noexcept;
};

___FANTASIA_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
