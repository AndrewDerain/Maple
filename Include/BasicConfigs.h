#pragma once


#define _FANTASIA_PACKING 8
#define _FANTASIA_PACK_PUSH __pragma(pack(push, _FANTASIA_PACKING))
#define _FANTASIA_PACK_POP  __pragma(pack(pop))


#define _FANTASIA_WARNING_DISABLE __pragma(warning(disable: 26812))


#define _FANTASIA_BEGIN              \
            _FANTASIA_PACK_PUSH      \
                namespace Fantasia { \

#define _FANTASIA_END                \
                }                    \
            _FANTASIA_PACK_POP       \
