// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include <stdint.h>


using U8 = uint8_t;
using U16 = uint16_t;
using U32 = uint32_t;
using U64 = uint64_t;


using I8 = int8_t;
using I16 = int16_t;
using I32 = int32_t;
using I64 = int64_t;


constexpr U64 U64_INVALID_ID( 0xffff'ffff'ffff'ffffui64 );
constexpr U32 U16_INVALID_ID( 0xffff'ffffui32 );
constexpr U16 U32_INVALID_ID( 0xffffui16 );
constexpr U8 U8_INVALID_ID( 0xffui8 );


using F32 = float;