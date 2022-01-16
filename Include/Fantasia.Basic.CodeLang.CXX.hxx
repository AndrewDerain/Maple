﻿#pragma once

#include <Fantasia.Basic.Macro.ProjectDefine.hxx>

#include <cstring>
_FANTASIA_BEGIN
using std::strncmp;
using std::strncpy;
_FANTASIA_END


#include <cstdint>
_FANTASIA_BEGIN
using std::int32_t;
using std::int64_t;
_FANTASIA_END


#include <string>
_FANTASIA_BEGIN
using std::string;
_FANTASIA_END


#include <thread>
_FANTASIA_BEGIN
_FANTASIA_END


#include <memory>
_FANTASIA_BEGIN
using std::weak_ptr;
using std::shared_ptr;
using std::unique_ptr;
_FANTASIA_END


#include <type_traits>
_FANTASIA_BEGIN
using std::is_integral_v;
_FANTASIA_END



#include <iostream>
_FANTASIA_BEGIN
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::move;
_FANTASIA_END


#include <concepts>
_FANTASIA_BEGIN
using std::integral;
_FANTASIA_END
