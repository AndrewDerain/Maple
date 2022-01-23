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

#define _FANTASIA_INLINE inline

#define _FANTASIA_EXPORT 


// struct _PrintFunction
// {
//     _PrintFunction() {
//         std::cout << scop << std::endl;
//     }
//     ~_PrintFunction() {
//         std::cout << __FUNCTION__ << std::endl;
//     }

//     std::string scop;
// };


#define _PrintVar(_Val) \
    std::cout << "Var [" << #_Val << "] = [" << _Val << "]" << std::endl;

#define _PrintFunc \
    std::cout << __FUNCTION__ << std::endl;

// class T
// {
// public: 
//     // static function
//     // static variables

//     // constructors
//     // functions
//     // operators

//     // variables
//     // inherited 
// protected:

// private:
// };