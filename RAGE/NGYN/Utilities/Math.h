// Copyright © 2024 XDreamist. All rights reserved.
#pragma once

#include "../Common/Common.h"

namespace RAGE::Math
{
	constexpr float PI = 3.14159265358979323846264338327950288419716939937510f;
	constexpr float EPSILON = 1e-5f;

#if defined(_WIN64)
	using Vec2 = DirectX::XMFLOAT2;
	using Vec2A = DirectX::XMFLOAT2A;
	using Vec3 = DirectX::XMFLOAT3;
	using Vec3A = DirectX::XMFLOAT3A;
	using Vec4 = DirectX::XMFLOAT4;
	using Vec4A = DirectX::XMFLOAT4A;
	using U32V2 = DirectX::XMUINT2;
	using U32V3 = DirectX::XMUINT3;
	using U32V4 = DirectX::XMUINT4;
	using I32V2 = DirectX::XMINT2;
	using I32V3 = DirectX::XMINT3;
	using I32V4 = DirectX::XMINT4;
	using MAT3x3 = DirectX::XMFLOAT3X3;
	using MAT4x4 = DirectX::XMFLOAT4X4;
	using MAT4x4A = DirectX::XMFLOAT4X4A;
#endif
}