﻿#include "crc.h"

namespace ubase
{
	template<typename T, T N>
	static const T* GetCrcTable()
	{
		static T CrcTable[0x100];
		for (T i = 0; i < _countof(CrcTable); ++i)
		{
			T crc = i;
			for (size_t j = 0; j < 8; ++j)
			{
				crc = (crc >> 1) ^ ((crc & 1) ? N : 0);
			}
			CrcTable[i] = crc;
		}
		return CrcTable;
	}

	template<typename T, T N>
	static T crc(const void* data, const size_t size, const T V)
	{
		static const T* const ct = GetCrcTable<T, N>();
		T ret = V;
		const uint8* buf = (const uint8*)data;
		for (size_t i = 0; i < size; ++i)
		{
			ret = ct[(ret & 0xFF) ^ buf[i]] ^ (ret >> 8);
		}
		return ret;
	}

	uint16 crc16(const void* data, const size_t size)
	{
		return crc<uint16, 0xA001>(data, size, 0);
	}

	uint32 crc32(const void* data, const size_t size)
	{
		return ~crc<uint32, 0xEDB88320>(data, size, 0xFFFFFFFF);
	}

	uint64 crc64(const void* data, const size_t size)
	{
		return ~crc<uint64, 0xC96C5795D7870F42>(data, size, 0xFFFFFFFFFFFFFFFF);
	}

	uint16 crcccitt(const void* data, const size_t size)
	{
		return crc<uint16, 0x8408>(data, size, 0xFFFF);
	}

}