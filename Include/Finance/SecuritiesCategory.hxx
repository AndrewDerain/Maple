#pragma once

#include <BasicConfigs.hxx>
#include <Foundation/PackedEnum.hxx>

#pragma warning(push)
#pragma warning(disable: _FANTASIA_WARNING_DISABLE_IDS)
#pragma pack(push, _FANTASIA_PACKING)
_FANTASIA_BEGIN
namespace Finance
{

    // 基础证券类型
    struct SecuritiesCategory
    {
        EnumElements
        {
            Commodity,              // 商品
            Stock,                  // 股票
            Fund,                   // 基金
            Bond,                   // 债券
            Index                   // 指数
        };

        EnumBasicActions(SecuritiesCategory, 
            Commodity, Stock, Fund, Bond, Index
        )
    };

}
_FANTASIA_END
#pragma pack(pop)
#pragma warning(pop)
