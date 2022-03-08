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


    /// @brief 生成行头
    ___FANTASIA_API
    char* _LineHead(int back = 0) const noexcept;


    ___FANTASIA_API 
    void _WriteScopStart() const noexcept;


    ___FANTASIA_API 
    void _WriteScopEnd() const noexcept;

    
    ___FANTASIA_API 
    static void _WriteLine(const char* content) noexcept;
};




/// @brief 一下宏和类型用于满足单元测试中的一些特别需求。
/// @details 需求1：检测是否调用了正确的重载函数。
#ifdef ___FANTASIA_ENABLE_UNITTEST
	class UnitTestHelper
	{
	private:
		std::string _OverloadFunctionName;

	public:
		std::string OverloadFunctionName() {
			return _OverloadFunctionName;
		}

		void OverloadFunctionName(std::string name) {
			_OverloadFunctionName = name;
		}

	};

#	define protected 	public
#	define private 	public

#	define ___FANTASIA_UnitTestHelper_(_TYPE) \
		_Fantasia::UnitTestHelper UnitTestHelper_##_TYPE;

#	define ___FANTASIA_UnitTestHelper_OverloadFunctionName(_TYPE, _NAME) \
	{                                               \
		UnitTestHelper_##_TYPE.OverloadFunctionName(_NAME); \
	}

#else
#	define ___FANTASIA_UnitTestHelper
#	define ___FANTASIA_UnitTestHelper_OverloadFunctionName(_NAME)
#endif

___FANTASIA_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
