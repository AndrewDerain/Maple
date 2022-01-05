#pragma once
#include <BasicConfigs.h>
#include <Foundation/PackedEnum.h>

_FANTASIA_WARNING_DISABLE
_FANTASIA_BEGIN
namespace Finance
{

    // 基础证券类型
    struct SecuritiesCategory
    {
        enum _Type
        {
            Commodity,              // 商品
            Stock,                  // 股票
            Fund,                   // 基金
            Bond,                   // 债券
            Index                   // 指数
        };

        EnumBasicAction(SecuritiesCategory, Commodity, Stock, Fund, Bond, Index)
    };

}
_FANTASIA_END
