﻿#pragma once


#define _FANTASIA_PACKING 8


#define _FANTASIA_WARNING_DISABLE_IDS \
            26812


#define _FANTASIA_BEGIN              \
            namespace Fantasia {     
#define _FANTASIA_END                \
            }                        


#define _FANTASIA_DETAIL_BEGIN       \
            namespace _Fantasia {    
#define _FANTASIA_DETAIL_END         \
            }


#define _FANTASIA_EXPORT 


#ifdef _FANTASIA_HEADER_ONLY
#    define _FANTASIA_INLINE inline
#else
#    define _FANTASIA_INLINE
#endif
