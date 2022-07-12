//
// Created by 宋豪杰 on 2022/7/11.
//

#pragma once


template<typename _Data, typename _Host>
class PropertyT {
protected:

    _Data _Value;
};


template<typename _Data>
class IProperty
{
public:

};


#define Property(ARGS) PropertyT<ARGS, Host> Value

/*
 * MapleObject(Type)
 *      using ___MapleObjectPropertyHost = Type
 *
 *
 *
 *
 *
 */