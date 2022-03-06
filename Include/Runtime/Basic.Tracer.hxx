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

    
    ___FANTASIA_API
    ~Tracer();


    ___FANTASIA_API
    void WriteLine(const char* line);


private:
    struct Brief
    {
        std::thread::id ThreadID;
        int64_t         SerialNumber;
        int64_t         Hierarchy;
    };


    /// @brief 函数签名
    const char* _Signature;


    /// @brief 域信息
    Brief _Brief;


    /// @brief 父域信息
    Brief _Parent;


    /// @brief 计算单一线程内进入的次数
    ___FANTASIA_API
    int _EnterTimes(bool pluse = false, bool minus = false) const;


    /// @brief   生成行头
    ___FANTASIA_API
    char* _LineHead(int back = 0) const noexcept;


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
