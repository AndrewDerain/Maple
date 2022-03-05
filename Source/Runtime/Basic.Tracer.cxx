#include <Runtime/Basic.Tracer.hxx>


#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
___FANTASIA_DETAIL_BEGIN

enum {
    LineContentSize = 1024
};


std::atomic_int64_t SerialNumberCounter = 0;


char Indent1[] =
        "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   "
        "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   ";


char Indent[] =
        "                                                                "
        "                                                                ";


___FANTASIA_API
Tracer::Tracer() {
    _Brief.ThreadID     = std::this_thread::get_id();
    _Brief.SerialNumber = ++SerialNumberCounter;
    _Brief.Hierarchy    = _EnterTimes(true);
};


___FANTASIA_API
Tracer::~Tracer() {
    _WriteScopEnd();
    _EnterTimes(false, true);
}


___FANTASIA_API
void Tracer::WriteLine(const char* line) {
    char LineContent[LineContentSize];

    snprintf(
        LineContent, LineContentSize, 
        "%s<LineContent Serial=\"%04lld\" %s/>", 
        _LineHead(),
        _Brief.SerialNumber,
        line
    );
    
    _WriteLine(LineContent);
}


___FANTASIA_API
int Tracer::_EnterTimes(bool pluse, bool minus) const {

    static thread_local int times = 0;
    
    if(pluse) times++;
    if(minus) times--;

    return times;
}


___FANTASIA_API
char* Tracer::_LineHead(int back) const noexcept {

    return 
        (char*)(&Indent[sizeof(Indent) - 1 - (_EnterTimes() - back) * sizeof(char) * 4]);
}


___FANTASIA_API 
void Tracer::_WriteScopStart() const noexcept {
    char LineContent[LineContentSize];

    snprintf(
        LineContent, LineContentSize, 
        "%s<Scope Serial=\"%04lld\" Hierarchy=\"%lld\" Thread=\"%lld\" Signature:\"%s\">", 
        _LineHead(1), 
        _Brief.SerialNumber,
        _Brief.Hierarchy,
        (*(uint64_t*)&_Brief.ThreadID),
        _Signature
    );

    _WriteLine(LineContent);
}


___FANTASIA_API 
void Tracer::_WriteScopEnd() const noexcept {
    char LineContent[LineContentSize];

    snprintf(
        LineContent, LineContentSize, 
        "%s</Scope>", 
        _LineHead(1)
    );

    _WriteLine(LineContent);
}


___FANTASIA_API 
void Tracer::_WriteLine(const char* content) noexcept {
    printf("%s\n", content);
}

___FANTASIA_DETAIL_END
#pragma pack(pop)
#pragma warning(pop)
