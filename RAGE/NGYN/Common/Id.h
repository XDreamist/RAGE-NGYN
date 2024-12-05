// Copyright © 2024 XDreamist. All rights reserved.
#pragma once


#include "Common.h"


namespace RAGE::ID {

	using IdType = U32;

	namespace internal {

		constexpr U32 GEN_BITS{ 10 };
		constexpr U32 INDX_BITS{ sizeof(IdType) * 8 - GEN_BITS };
		constexpr IdType INDX_MASK{ (IdType{1} << INDX_BITS) - 1 };
		constexpr IdType GEN_MASK{ (IdType{1} << GEN_BITS) - 1 };
	}

	constexpr IdType INVALID_ID{ IdType(- 1) };
	constexpr U32 MIN_DETECTED_ELEMENTS{ 1024 };

	using GenType = std::conditional_t<internal::GEN_BITS <= 16, std::conditional_t<internal::GEN_BITS <= 8, U8, U16>, U32 >;
	static_assert(sizeof(GenType) * 8 >= internal::GEN_BITS);
	static_assert((sizeof(IdType) - sizeof(GenType)) > 0);

	constexpr bool isValid(IdType id)
	{
		return id != INVALID_ID;
	}

	constexpr IdType index(IdType id)
	{
		IdType index{ id & internal::INDX_MASK };
		assert(index != internal::INDX_MASK);
		return index;
	}

	constexpr IdType generation(IdType id)
	{
		return (id >> internal::INDX_BITS) & internal::GEN_MASK;
	}

	constexpr IdType newGeneration(IdType id)
	{
		const IdType GENERATION{ ID::generation(id) + 1 };
		assert(GENERATION < ((U64)1 << internal::GEN_BITS) - 1);
		return index(id) | (GENERATION << internal::INDX_BITS);
	}

#if _DEBUG
	namespace internal {
		struct id_base
		{
			constexpr explicit id_base(IdType id) : _id{ id } {}
			constexpr operator IdType() const { return _id; }

		private:
			IdType _id;
		};
	}

#define DEFINE_TYPED_ID(Name)                                       \
    struct Name final : ID::internal::id_base                       \
	{                                                               \
        constexpr explicit Name(ID::IdType id) : id_base{ id } {}   \
        constexpr Name() : id_base{ 0 } {}                          \
    };

#else
#define DEFINE_TYPED_ID(name) using name = ID::IdType;
#endif
}