#pragma once

#include <d3dx11.h>
#include <d3dcompiler.h>
#include <D3DX11async.h>

namespace HR_SDK
{
	namespace D3D_Formats
	{
		enum E
		{
			UNKNOWN,
			RGBA_32_TYPELESS,
			RGBA_32_FLOAT,
			RGBA_32_UINT,
			RGBA_32_INT,
			RGB_32_TYPELESS,
			RGB_32_FLOAT,
			RGB_32_UINT,
			RGB_32_INT,
			RGBA_16_TYPELESS,
			RGBA_16_FLOAT,
			RGBA_16_UNORM,
			RGBA_16_UINT,
			RGBA_16_NORM,
			RGBA_16_INT,
			RG_32_TYPELESS,
			RG_32_FLOAT,
			RG_32_UINT,
			RG_32_INT,
			RGBA_8_TYPELESS = 27,
			RGBA_8_UNORM,
			RGBA_8_UNORM_SRGB,
			RGBA_8_UINT,
			RGBA_8_SNORM,
			RGBA_8_SINT,
			R_32_UINT = 42,
			D_24_UNORM_S8_UINT = 45,
		};
	}

	namespace D3D_Drivers
	{
		enum E
		{
			UNKNOWN,
			HARDWARE = UNKNOWN + 1,
			REFERENCE = HARDWARE + 1,
			NULL_TYPE = REFERENCE + 1,
			SOFTWARE = NULL_TYPE + 1,
			WARP = SOFTWARE + 1
		};
	}

	namespace D3D_Levels
	{
		enum E
		{
			L_9_1,
			L_9_2,
			L_9_3,
			L_10,
			L_10_1,
			L_11,
			L_11_1
		};
	}

	namespace D3D_Usages
	{
		enum E
		{
			DEFAULT,
			INMUTABLE,
			DYNAMIC,
			STAGING
		};
	}

	namespace D3D_Access
	{
		enum E
		{
			NONE,
			WRITE =		0X10000L,
			READ =		0X20000L
		};
	}

	namespace D3D_Binds
	{
		enum E
		{
			VERTEX_BUFFER =		0x1L,
			INDEX_BUFFER =		0X2L,
			CONST_BUFFER =		0X4L,
			SHADER_RESOURCE =	0x8L,
			STREAM_OUTPUT =		0x10L,
			RENDER_TARGET =		0x20l,
			DEPTH_STENCIL =		0x40L,
			UNORDERED_ACCESS =	0x80l
		};
	}

	namespace D3D_FillModes
	{
		enum E
		{
			WIREFRAME = 2,
			SOLID =		3
		};
	}

	namespace D3D_CullModes
	{
		enum E
		{
			NONE =		1,
			FRONT =		2,
			BACK =		3
		};
	}

	namespace D3D_Topologies
	{
		enum E
		{
			UNDEFINED,
			POINT_LIST,
			LINE_LIST,
			LINE_STRIP,
			TRIANGLE_LIST,
			TRIANGLE_STRIP,
			LINE_LIST_ADJ = 10,
			LINE_STRIP_ADJ,
			TRIANGLE_LIST_ADJ,
			TRIANGLE_STRIP_ADJ
		};
	}

	inline DXGI_FORMAT				TranslateFormat
	(
		D3D_Formats::E prm_Format
	)
	{
		return (DXGI_FORMAT)prm_Format;
	}

	inline D3D_DRIVER_TYPE			TranslateDriver
	(
		D3D_Drivers::E prm_Driver
	)
	{
		return (D3D_DRIVER_TYPE)prm_Driver;
	}

	inline D3D_FEATURE_LEVEL*		TranslateLevel
	(
		D3D_Levels::E prm_Level
	)
	{
		return (D3D_FEATURE_LEVEL*)prm_Level;
	}

	inline D3D11_USAGE				TranslateUsage
	(
		D3D_Usages::E prm_Usage
	)
	{
		return (D3D11_USAGE)prm_Usage;
	}

	inline D3D11_CPU_ACCESS_FLAG	TranslateAccess
	(
		D3D_Access::E prm_Access
	)
	{
		return (D3D11_CPU_ACCESS_FLAG)prm_Access;
	}

	inline D3D11_BIND_FLAG			TranslateBind
	(
		D3D_Binds::E prm_Bind
	)
	{
		return (D3D11_BIND_FLAG)prm_Bind;
	}

	inline D3D11_PRIMITIVE_TOPOLOGY				TranslateTopology
	(
		D3D_Topologies::E prm_Topology
	)
	{
		return (D3D11_PRIMITIVE_TOPOLOGY)prm_Topology;
	}

	inline D3D11_FILL_MODE			TranslateFillMode
	(
		D3D_FillModes::E prm_FillMode
	)
	{
		return (D3D11_FILL_MODE)prm_FillMode;
	}

	inline D3D11_CULL_MODE			TranslateCullMode
	(
		D3D_CullModes::E prm_CullMode
	)
	{
		return (D3D11_CULL_MODE)prm_CullMode;
	}

}