#include <Runtime/Basic.Tracer.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
___FANTASIA_DETAIL_BEGIN

std::atomic_int64_t SerialNumberCounter = 0;

___FANTASIA_API
Tracer::Tracer() {
    _Brief.ThreadID     = std::this_thread::get_id();
    _Brief.SerialNumber = ++SerialNumberCounter;
    _Brief.Hierarchy    = 0;
};


___FANTASIA_API 
void Tracer::_WriteScopStart() const noexcept {
    std::stringstream content;
    _GenLineHead(content);
    content << " ---  -> start";
    _WriteLine(content.str().c_str());
}


___FANTASIA_API 
void Tracer::_WriteScopEnd() const noexcept {
    std::stringstream content;
    _GenLineHead(content);
    content << " ---  -> end";
    _WriteLine(content.str().c_str());
}


___FANTASIA_API 
void Tracer::_WriteLine(const char* content) noexcept {
    std::cout << content << std::endl;
}

___FANTASIA_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
