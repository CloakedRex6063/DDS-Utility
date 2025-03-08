#pragma once
#include "fstream"

// Minimal cross-platform DDS texture utility
// MIT License (see the end of this file)

namespace dds
{
    enum DDS_PIXELFORMAT_FLAGS
    {
        DDPF_ALPHAPIXELS =
        0x1, // Texture contains alpha data; dwRGBAlphaBitMask contains valid data.
        DDPF_ALPHA = 0x2, // Used in some older DDS files for alpha channel only uncompressed data
        // (dwRGBBitCount contains the alpha channel bitcount; dwABitMask contains
        // valid data)
        DDPF_FOURCC = 0x4, // Texture contains compressed RGB data; dwFourCC contains valid data.
        DDPF_RGB = 0x40, // Texture contains uncompressed RGB data; dwRGBBitCount and the RGB masks
        // (dwRBitMask, dwGBitMask, dwBBitMask) contain valid data.
        DDPF_YUV = 0x200, // Used in some older DDS files for YUV uncompressed data (dwRGBBitCount
        // contains the YUV bit count; dwRBitMask contains the Y mask, dwGBitMask
        // contains the U mask, dwBBitMask contains the V mask)
        DDPF_LUMINANCE = 0x20000 // Used in some older DDS files for single channel color
        // uncompressed data (dwRGBBitCount contains the luminance channel
        // bit count; dwRBitMask contains the channel mask). Can be
        // combined with DDPF_ALPHAPIXELS for a two channel DDS file.
    };

    struct DDS_PIXELFORMAT
    {
        unsigned dwSize;
        unsigned dwFlags;
        unsigned dwFourCC;
        unsigned dwRGBBitCount;
        unsigned dwRBitMask;
        unsigned dwGBitMask;
        unsigned dwBBitMask;
        unsigned dwABitMask;
    };

    enum DDSD_CAPS
    {
        DDSD_CAPS = 0x1, // Required in every .dds file.
        DDSD_HEIGHT = 0x2, // Required in every .dds file.
        DDSD_WIDTH = 0x4, // Required in every .dds file.
        DDSD_PITCH = 0x8, // Required when pitch is provided for an uncompressed texture.
        DDSD_PIXELFORMAT = 0x1000, // Required in every .dds file.
        DDSD_MIPMAPCOUNT = 0x20000, // Required in a mipmapped texture.
        DDSD_LINEARSIZE = 0x80000, // Required when pitch is provided for a compressed texture.
        DDSD_DEPTH = 0x800000 // Required in a depth texture.
    };

    enum DDSCAPS
    {
        DDSCAPS_COMPLEX =
        0x8, // Optional; must be used on any file that contains more than one surface (a
        // mipmap, a cubic environment map, or mipmapped volume texture).
        DDSCAPS_MIPMAP = 0x400000, // Optional; should be used for a mipmap.
        DDSCAPS_TEXTURE = 0x1000, // Required
    };

    enum DDSCAPS2
    {
        DDSCAPS2_CUBEMAP = 0x200, // Required for a cube map.
        DDSCAPS2_CUBEMAP_POSITIVEX =
        0x400, // Required when these surfaces are stored in a cube map.
        DDSCAPS2_CUBEMAP_NEGATIVEX =
        0x800, // Required when these surfaces are stored in a cube map.
        DDSCAPS2_CUBEMAP_POSITIVEY =
        0x1000, // Required when these surfaces are stored in a cube map.
        DDSCAPS2_CUBEMAP_NEGATIVEY =
        0x2000, // Required when these surfaces are stored in a cube map.
        DDSCAPS2_CUBEMAP_POSITIVEZ =
        0x4000, // Required when these surfaces are stored in a cube map.
        DDSCAPS2_CUBEMAP_NEGATIVEZ =
        0x8000, // Required when these surfaces are stored in a cube map.
        DDSCAPS2_VOLUME = 0x200000, // Required for a volume texture.
    };

    typedef struct
    {
        unsigned dwSize;
        unsigned dwFlags;
        unsigned dwHeight;
        unsigned dwWidth;
        unsigned dwPitchOrLinearSize;
        unsigned dwDepth;
        unsigned dwMipMapCount;
        unsigned dwReserved1[11];
        DDS_PIXELFORMAT ddspf;
        unsigned dwCaps;
        unsigned dwCaps2;
        unsigned dwCaps3;
        unsigned dwCaps4;
        unsigned dwReserved2;
    } DDS_HEADER;

    enum DXGI_FORMAT
    {
        DXGI_FORMAT_UNKNOWN = 0,
        DXGI_FORMAT_R32G32B32A32_TYPELESS = 1,
        DXGI_FORMAT_R32G32B32A32_FLOAT = 2,
        DXGI_FORMAT_R32G32B32A32_UINT = 3,
        DXGI_FORMAT_R32G32B32A32_SINT = 4,
        DXGI_FORMAT_R32G32B32_TYPELESS = 5,
        DXGI_FORMAT_R32G32B32_FLOAT = 6,
        DXGI_FORMAT_R32G32B32_UINT = 7,
        DXGI_FORMAT_R32G32B32_SINT = 8,
        DXGI_FORMAT_R16G16B16A16_TYPELESS = 9,
        DXGI_FORMAT_R16G16B16A16_FLOAT = 10,
        DXGI_FORMAT_R16G16B16A16_UNORM = 11,
        DXGI_FORMAT_R16G16B16A16_UINT = 12,
        DXGI_FORMAT_R16G16B16A16_SNORM = 13,
        DXGI_FORMAT_R16G16B16A16_SINT = 14,
        DXGI_FORMAT_R32G32_TYPELESS = 15,
        DXGI_FORMAT_R32G32_FLOAT = 16,
        DXGI_FORMAT_R32G32_UINT = 17,
        DXGI_FORMAT_R32G32_SINT = 18,
        DXGI_FORMAT_R32G8X24_TYPELESS = 19,
        DXGI_FORMAT_D32_FLOAT_S8X24_UINT = 20,
        DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS = 21,
        DXGI_FORMAT_X32_TYPELESS_G8X24_UINT = 22,
        DXGI_FORMAT_R10G10B10A2_TYPELESS = 23,
        DXGI_FORMAT_R10G10B10A2_UNORM = 24,
        DXGI_FORMAT_R10G10B10A2_UINT = 25,
        DXGI_FORMAT_R11G11B10_FLOAT = 26,
        DXGI_FORMAT_R8G8B8A8_TYPELESS = 27,
        DXGI_FORMAT_R8G8B8A8_UNORM = 28,
        DXGI_FORMAT_R8G8B8A8_UNORM_SRGB = 29,
        DXGI_FORMAT_R8G8B8A8_UINT = 30,
        DXGI_FORMAT_R8G8B8A8_SNORM = 31,
        DXGI_FORMAT_R8G8B8A8_SINT = 32,
        DXGI_FORMAT_R16G16_TYPELESS = 33,
        DXGI_FORMAT_R16G16_FLOAT = 34,
        DXGI_FORMAT_R16G16_UNORM = 35,
        DXGI_FORMAT_R16G16_UINT = 36,
        DXGI_FORMAT_R16G16_SNORM = 37,
        DXGI_FORMAT_R16G16_SINT = 38,
        DXGI_FORMAT_R32_TYPELESS = 39,
        DXGI_FORMAT_D32_FLOAT = 40,
        DXGI_FORMAT_R32_FLOAT = 41,
        DXGI_FORMAT_R32_UINT = 42,
        DXGI_FORMAT_R32_SINT = 43,
        DXGI_FORMAT_R24G8_TYPELESS = 44,
        DXGI_FORMAT_D24_UNORM_S8_UINT = 45,
        DXGI_FORMAT_R24_UNORM_X8_TYPELESS = 46,
        DXGI_FORMAT_X24_TYPELESS_G8_UINT = 47,
        DXGI_FORMAT_R8G8_TYPELESS = 48,
        DXGI_FORMAT_R8G8_UNORM = 49,
        DXGI_FORMAT_R8G8_UINT = 50,
        DXGI_FORMAT_R8G8_SNORM = 51,
        DXGI_FORMAT_R8G8_SINT = 52,
        DXGI_FORMAT_R16_TYPELESS = 53,
        DXGI_FORMAT_R16_FLOAT = 54,
        DXGI_FORMAT_D16_UNORM = 55,
        DXGI_FORMAT_R16_UNORM = 56,
        DXGI_FORMAT_R16_UINT = 57,
        DXGI_FORMAT_R16_SNORM = 58,
        DXGI_FORMAT_R16_SINT = 59,
        DXGI_FORMAT_R8_TYPELESS = 60,
        DXGI_FORMAT_R8_UNORM = 61,
        DXGI_FORMAT_R8_UINT = 62,
        DXGI_FORMAT_R8_SNORM = 63,
        DXGI_FORMAT_R8_SINT = 64,
        DXGI_FORMAT_A8_UNORM = 65,
        DXGI_FORMAT_R1_UNORM = 66,
        DXGI_FORMAT_R9G9B9E5_SHAREDEXP = 67,
        DXGI_FORMAT_R8G8_B8G8_UNORM = 68,
        DXGI_FORMAT_G8R8_G8B8_UNORM = 69,
        DXGI_FORMAT_BC1_TYPELESS = 70,
        DXGI_FORMAT_BC1_UNORM = 71,
        DXGI_FORMAT_BC1_UNORM_SRGB = 72,
        DXGI_FORMAT_BC2_TYPELESS = 73,
        DXGI_FORMAT_BC2_UNORM = 74,
        DXGI_FORMAT_BC2_UNORM_SRGB = 75,
        DXGI_FORMAT_BC3_TYPELESS = 76,
        DXGI_FORMAT_BC3_UNORM = 77,
        DXGI_FORMAT_BC3_UNORM_SRGB = 78,
        DXGI_FORMAT_BC4_TYPELESS = 79,
        DXGI_FORMAT_BC4_UNORM = 80,
        DXGI_FORMAT_BC4_SNORM = 81,
        DXGI_FORMAT_BC5_TYPELESS = 82,
        DXGI_FORMAT_BC5_UNORM = 83,
        DXGI_FORMAT_BC5_SNORM = 84,
        DXGI_FORMAT_B5G6R5_UNORM = 85,
        DXGI_FORMAT_B5G5R5A1_UNORM = 86,
        DXGI_FORMAT_B8G8R8A8_UNORM = 87,
        DXGI_FORMAT_B8G8R8X8_UNORM = 88,
        DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
        DXGI_FORMAT_B8G8R8A8_TYPELESS = 90,
        DXGI_FORMAT_B8G8R8A8_UNORM_SRGB = 91,
        DXGI_FORMAT_B8G8R8X8_TYPELESS = 92,
        DXGI_FORMAT_B8G8R8X8_UNORM_SRGB = 93,
        DXGI_FORMAT_BC6H_TYPELESS = 94,
        DXGI_FORMAT_BC6H_UF16 = 95,
        DXGI_FORMAT_BC6H_SF16 = 96,
        DXGI_FORMAT_BC7_TYPELESS = 97,
        DXGI_FORMAT_BC7_UNORM = 98,
        DXGI_FORMAT_BC7_UNORM_SRGB = 99,
        DXGI_FORMAT_AYUV = 100,
        DXGI_FORMAT_Y410 = 101,
        DXGI_FORMAT_Y416 = 102,
        DXGI_FORMAT_NV12 = 103,
        DXGI_FORMAT_P010 = 104,
        DXGI_FORMAT_P016 = 105,
        DXGI_FORMAT_420_OPAQUE = 106,
        DXGI_FORMAT_YUY2 = 107,
        DXGI_FORMAT_Y210 = 108,
        DXGI_FORMAT_Y216 = 109,
        DXGI_FORMAT_NV11 = 110,
        DXGI_FORMAT_AI44 = 111,
        DXGI_FORMAT_IA44 = 112,
        DXGI_FORMAT_P8 = 113,
        DXGI_FORMAT_A8P8 = 114,
        DXGI_FORMAT_B4G4R4A4_UNORM = 115,
        DXGI_FORMAT_P208 = 130,
        DXGI_FORMAT_V208 = 131,
        DXGI_FORMAT_V408 = 132,
        DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE,
        DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE,
        D3DFMT_R8G8B8, // Note: you will need to handle conversion of this legacy format yourself
        DXGI_FORMAT_FORCE_DWORD = 0xffffffff
    };

    enum D3D10_RESOURCE_DIMENSION
    {
        D3D10_RESOURCE_DIMENSION_UNKNOWN = 0,
        D3D10_RESOURCE_DIMENSION_BUFFER = 1,
        D3D10_RESOURCE_DIMENSION_TEXTURE1D = 2,
        D3D10_RESOURCE_DIMENSION_TEXTURE2D = 3,
        D3D10_RESOURCE_DIMENSION_TEXTURE3D = 4
    };

    enum DDS_RESOURCE_MISC_TEXTURECUBE
    {
        DDS_RESOURCE_MISC_TEXTURECUBE = 0x4, // Indicates a 2D texture is a cube-map texture.
    };

    enum DDS_ALPHA_MODE
    {
        DDS_ALPHA_MODE_UNKNOWN =
        0x0, // Alpha channel content is unknown. This is the value for legacy files, which
        // typically is assumed to be 'straight' alpha.
        DDS_ALPHA_MODE_STRAIGHT =
        0x1, // Any alpha channel content is presumed to use straight alpha.
        DDS_ALPHA_MODE_PREMULTIPLIED =
        0x2, // Any alpha channel content is using premultiplied alpha. The only legacy
        // file formats that indicate this information are 'DX2' and 'DX4'.
        DDS_ALPHA_MODE_OPAQUE = 0x3, // Any alpha channel content is all set to fully opaque.
        DDS_ALPHA_MODE_CUSTOM =
        0x4, // Any alpha channel content is being used as a 4th channel and is not intended to
        // represent transparency (straight or premultiplied).
    };

    typedef struct
    {
        DXGI_FORMAT dxgiFormat;
        D3D10_RESOURCE_DIMENSION resourceDimension;
        unsigned miscFlag;
        unsigned arraySize;
        unsigned miscFlags2;
    } DDS_HEADER_DXT10;

    static constexpr unsigned fourcc(
        const char a,
        const char b,
        const char c,
        const char d)
    {
        return (
            (static_cast<unsigned>(d) << 24) | (static_cast<unsigned>(c) << 16) |
            (static_cast<unsigned>(b) << 8) | static_cast<unsigned>(a));
    }

    struct Header
    {
        unsigned magic;
        DDS_HEADER header;
        DDS_HEADER_DXT10 header10;

        // Returns true if this structure can be used, false otherwise
        [[nodiscard]]
        constexpr bool IsValid() const
        {
            return magic == fourcc('D', 'D', 'S', ' ') &&
                   header.ddspf.dwSize == sizeof(DDS_PIXELFORMAT);
        }

        // Returns true if the header10 member is valid
        [[nodiscard]]
        constexpr bool IsDx10() const
        {
            return (header.ddspf.dwFlags & DDPF_FOURCC) &&
                   header.ddspf.dwFourCC == fourcc('D', 'X', '1', '0');
        }

        // returns the width of the texture in pixels
        [[nodiscard]]
        constexpr unsigned Width() const
        {
            return header.dwWidth < 1 ? 1 : header.dwWidth;
        }

        // returns the height of the texture in pixels
        [[nodiscard]]
        constexpr unsigned Height() const
        {
            return header.dwHeight < 1 ? 1 : header.dwHeight;
        }

        // returns the depth of the texture in pixels
        [[nodiscard]]
        constexpr unsigned Depth() const
        {
            return header.dwDepth < 1 ? 1 : header.dwDepth;
        }

        // returns the mipmap levels in the texture per slice
        [[nodiscard]]
        constexpr unsigned MipLevels() const
        {
            return header.dwMipMapCount > 0 ? header.dwMipMapCount : 1;
        }

        // returns the number of slices in the texture
        [[nodiscard]]
        constexpr unsigned ArraySize() const
        {
            if (!IsDx10())
            {
                if (IsCubemap())
                    return 6;
                return 1;
            }
            unsigned count = 0;
            if (IsCubemap())
                count = header10.arraySize * 6;
            else
                count = header10.arraySize;
            count = count < 1 ? 1 : count;
            return count;
        }

        // returns the format of the texture in the DXGI_FORMAT that is compatible with DX10, even
        // when the texture is using legacy format
        [[nodiscard]]
        constexpr DXGI_FORMAT Format() const
        {
            if (!IsDx10())
            {
                if (header.ddspf.dwFlags & DDPF_RGB)
                {
                    switch (header.ddspf.dwRGBBitCount)
                    {
                        case 32:
                            if (header.ddspf.dwRBitMask == 0x000000ff &&
                                header.ddspf.dwGBitMask == 0x0000ff00 &&
                                header.ddspf.dwBBitMask == 0x00ff0000 &&
                                header.ddspf.dwABitMask == 0xff000000)
                            {
                                return DXGI_FORMAT_R8G8B8A8_UNORM;
                            }
                            if (header.ddspf.dwRBitMask == 0x00ff0000 &&
                                header.ddspf.dwGBitMask == 0x0000ff00 &&
                                header.ddspf.dwBBitMask == 0x000000ff &&
                                header.ddspf.dwABitMask == 0xff000000)
                            {
                                return DXGI_FORMAT_B8G8R8A8_UNORM;
                            }
                            if (header.ddspf.dwRBitMask == 0x00ff0000 &&
                                header.ddspf.dwGBitMask == 0x0000ff00 &&
                                header.ddspf.dwBBitMask == 0x000000ff &&
                                header.ddspf.dwABitMask == 0x00000000)
                            {
                                return DXGI_FORMAT_B8G8R8X8_UNORM;
                            }

                            if (header.ddspf.dwRBitMask == 0x0000ffff &&
                                header.ddspf.dwGBitMask == 0xffff0000 &&
                                header.ddspf.dwBBitMask == 0x00000000 &&
                                header.ddspf.dwABitMask == 0x00000000)
                            {
                                return DXGI_FORMAT_R16G16_UNORM;
                            }

                            if (header.ddspf.dwRBitMask == 0xffffffff &&
                                header.ddspf.dwGBitMask == 0x00000000 &&
                                header.ddspf.dwBBitMask == 0x00000000 &&
                                header.ddspf.dwABitMask == 0x00000000)
                            {
                                return DXGI_FORMAT_R32_FLOAT;
                            }
                            break;
                        case 24:
                            return D3DFMT_R8G8B8;
                        case 16:
                            if (header.ddspf.dwRBitMask == 0x7c00 &&
                                header.ddspf.dwGBitMask == 0x03e0 &&
                                header.ddspf.dwBBitMask == 0x001f && header.ddspf.dwABitMask == 0x8000)
                            {
                                return DXGI_FORMAT_B5G5R5A1_UNORM;
                            }
                            if (header.ddspf.dwRBitMask == 0xf800 &&
                                header.ddspf.dwGBitMask == 0x07e0 &&
                                header.ddspf.dwBBitMask == 0x001f && header.ddspf.dwABitMask == 0x0000)
                            {
                                return DXGI_FORMAT_B5G6R5_UNORM;
                            }

                            if (header.ddspf.dwRBitMask == 0x0f00 &&
                                header.ddspf.dwGBitMask == 0x00f0 &&
                                header.ddspf.dwBBitMask == 0x000f && header.ddspf.dwABitMask == 0xf000)
                            {
                                return DXGI_FORMAT_B4G4R4A4_UNORM;
                            }
                            break;
                        default:
                            break;
                    }
                } else if (header.ddspf.dwFlags & DDPF_LUMINANCE)
                {
                    if (8 == header.ddspf.dwRGBBitCount)
                    {
                        if (header.ddspf.dwRBitMask == 0x000000ff &&
                            header.ddspf.dwGBitMask == 0x00000000 &&
                            header.ddspf.dwBBitMask == 0x00000000 &&
                            header.ddspf.dwABitMask == 0x00000000)
                        {
                            return DXGI_FORMAT_R8_UNORM;
                        }
                        if (header.ddspf.dwRBitMask == 0x000000ff &&
                            header.ddspf.dwGBitMask == 0x0000ff00 &&
                            header.ddspf.dwBBitMask == 0x00000000 &&
                            header.ddspf.dwABitMask == 0x00000000)
                        {
                            return DXGI_FORMAT_R8G8_UNORM;
                        }
                    }
                    if (16 == header.ddspf.dwRGBBitCount)
                    {
                        if (header.ddspf.dwRBitMask == 0x0000ffff &&
                            header.ddspf.dwGBitMask == 0x00000000 &&
                            header.ddspf.dwBBitMask == 0x00000000 &&
                            header.ddspf.dwABitMask == 0x00000000)
                        {
                            return DXGI_FORMAT_R16_UNORM;
                        }
                        if (header.ddspf.dwRBitMask == 0x000000ff &&
                            header.ddspf.dwGBitMask == 0x0000ff00 &&
                            header.ddspf.dwBBitMask == 0x00000000 &&
                            header.ddspf.dwABitMask == 0x00000000)
                        {
                            return DXGI_FORMAT_R8G8_UNORM;
                        }
                    }
                } else if (header.ddspf.dwFlags & DDPF_ALPHA)
                {
                    if (8 == header.ddspf.dwRGBBitCount)
                    {
                        return DXGI_FORMAT_A8_UNORM;
                    }
                } else if (header.ddspf.dwFlags & DDPF_FOURCC)
                {
                    if (fourcc('D', 'X', 'T', '1') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC1_UNORM;
                    }
                    if (fourcc('D', 'X', 'T', '3') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC2_UNORM;
                    }
                    if (fourcc('D', 'X', 'T', '5') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC3_UNORM;
                    }

                    if (fourcc('D', 'X', 'T', '4') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC2_UNORM;
                    }
                    if (fourcc('D', 'X', 'T', '5') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC3_UNORM;
                    }

                    if (fourcc('A', 'T', 'I', '1') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC4_UNORM;
                    }
                    if (fourcc('B', 'C', '4', 'U') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC4_UNORM;
                    }
                    if (fourcc('B', 'C', '4', 'S') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC4_SNORM;
                    }

                    if (fourcc('A', 'T', 'I', '2') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC5_UNORM;
                    }
                    if (fourcc('B', 'C', '5', 'U') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC5_UNORM;
                    }
                    if (fourcc('B', 'C', '5', 'S') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_BC5_SNORM;
                    }

                    if (fourcc('R', 'G', 'B', 'G') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_R8G8_B8G8_UNORM;
                    }
                    if (fourcc('G', 'R', 'G', 'B') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_G8R8_G8B8_UNORM;
                    }

                    if (fourcc('Y', 'U', 'Y', '2') == header.ddspf.dwFourCC)
                    {
                        return DXGI_FORMAT_YUY2;
                    }

                    switch (header.ddspf.dwFourCC)
                    {
                        case 36:
                            return DXGI_FORMAT_R16G16B16A16_UNORM;
                        case 110:
                            return DXGI_FORMAT_R16G16B16A16_SNORM;
                        case 111:
                            return DXGI_FORMAT_R16_FLOAT;
                        case 112:
                            return DXGI_FORMAT_R16G16_FLOAT;
                        case 113:
                            return DXGI_FORMAT_R16G16B16A16_FLOAT;
                        case 114:
                            return DXGI_FORMAT_R32_FLOAT;
                        case 115:
                            return DXGI_FORMAT_R32G32_FLOAT;
                        case 116:
                            return DXGI_FORMAT_R32G32B32A32_FLOAT;
                    }
                }
                return DXGI_FORMAT_UNKNOWN;
            }
            return header10.dxgiFormat;
        }

        // returns tru if the texture is a cubemap, false otherwise
        [[nodiscard]]
        constexpr bool IsCubemap() const
        {
            if (IsDx10())
            {
                return header10.miscFlag & DDS_RESOURCE_MISC_TEXTURECUBE;
            }
            return (header.dwCaps2 & DDSCAPS2_CUBEMAP) &&
                   (header.dwCaps2 & DDSCAPS2_CUBEMAP_POSITIVEX) &&
                   (header.dwCaps2 & DDSCAPS2_CUBEMAP_NEGATIVEX) &&
                   (header.dwCaps2 & DDSCAPS2_CUBEMAP_POSITIVEY) &&
                   (header.dwCaps2 & DDSCAPS2_CUBEMAP_NEGATIVEY) &&
                   (header.dwCaps2 & DDSCAPS2_CUBEMAP_POSITIVEZ) &&
                   (header.dwCaps2 & DDSCAPS2_CUBEMAP_NEGATIVEZ);
        }

        // returns true if the texture is one dimensional, false otherwise
        [[nodiscard]]
        constexpr bool Is1D() const
        {
            if (!IsDx10())
                return false;
            return header10.resourceDimension == D3D10_RESOURCE_DIMENSION_TEXTURE1D;
        }

        // returns true if the texture is three dimensional, false otherwise
        [[nodiscard]]
        constexpr bool Is3D() const
        {
            if (!IsDx10())
                return false;
            return (header.dwCaps2 & DDSCAPS2_VOLUME) &&
                   header10.resourceDimension == D3D10_RESOURCE_DIMENSION_TEXTURE3D;
        }

        // returns the number of bits per element. Element refers to a block of pixels if the
        // texture is block compressed, or a single pixel otherwise
        [[nodiscard]]
        constexpr unsigned BitsPerElement() const
        {
            switch (Format())
            {
                case DXGI_FORMAT_R32G32B32A32_TYPELESS:
                case DXGI_FORMAT_R32G32B32A32_FLOAT:
                case DXGI_FORMAT_R32G32B32A32_UINT:
                case DXGI_FORMAT_R32G32B32A32_SINT:
                    return 128;

                case DXGI_FORMAT_R32G32B32_TYPELESS:
                case DXGI_FORMAT_R32G32B32_FLOAT:
                case DXGI_FORMAT_R32G32B32_UINT:
                case DXGI_FORMAT_R32G32B32_SINT:
                    return 96;

                case DXGI_FORMAT_R16G16B16A16_TYPELESS:
                case DXGI_FORMAT_R16G16B16A16_FLOAT:
                case DXGI_FORMAT_R16G16B16A16_UNORM:
                case DXGI_FORMAT_R16G16B16A16_UINT:
                case DXGI_FORMAT_R16G16B16A16_SNORM:
                case DXGI_FORMAT_R16G16B16A16_SINT:
                case DXGI_FORMAT_R32G32_TYPELESS:
                case DXGI_FORMAT_R32G32_FLOAT:
                case DXGI_FORMAT_R32G32_UINT:
                case DXGI_FORMAT_R32G32_SINT:
                case DXGI_FORMAT_R32G8X24_TYPELESS:
                case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
                case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
                case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
                case DXGI_FORMAT_Y416:
                case DXGI_FORMAT_Y210:
                case DXGI_FORMAT_Y216:
                    return 64;

                case DXGI_FORMAT_R10G10B10A2_TYPELESS:
                case DXGI_FORMAT_R10G10B10A2_UNORM:
                case DXGI_FORMAT_R10G10B10A2_UINT:
                case DXGI_FORMAT_R11G11B10_FLOAT:
                case DXGI_FORMAT_R8G8B8A8_TYPELESS:
                case DXGI_FORMAT_R8G8B8A8_UNORM:
                case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
                case DXGI_FORMAT_R8G8B8A8_UINT:
                case DXGI_FORMAT_R8G8B8A8_SNORM:
                case DXGI_FORMAT_R8G8B8A8_SINT:
                case DXGI_FORMAT_R16G16_TYPELESS:
                case DXGI_FORMAT_R16G16_FLOAT:
                case DXGI_FORMAT_R16G16_UNORM:
                case DXGI_FORMAT_R16G16_UINT:
                case DXGI_FORMAT_R16G16_SNORM:
                case DXGI_FORMAT_R16G16_SINT:
                case DXGI_FORMAT_R32_TYPELESS:
                case DXGI_FORMAT_D32_FLOAT:
                case DXGI_FORMAT_R32_FLOAT:
                case DXGI_FORMAT_R32_UINT:
                case DXGI_FORMAT_R32_SINT:
                case DXGI_FORMAT_R24G8_TYPELESS:
                case DXGI_FORMAT_D24_UNORM_S8_UINT:
                case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
                case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
                case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
                case DXGI_FORMAT_R8G8_B8G8_UNORM:
                case DXGI_FORMAT_G8R8_G8B8_UNORM:
                case DXGI_FORMAT_B8G8R8A8_UNORM:
                case DXGI_FORMAT_B8G8R8X8_UNORM:
                case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
                case DXGI_FORMAT_B8G8R8A8_TYPELESS:
                case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
                case DXGI_FORMAT_B8G8R8X8_TYPELESS:
                case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
                case DXGI_FORMAT_AYUV:
                case DXGI_FORMAT_Y410:
                case DXGI_FORMAT_YUY2:
                case D3DFMT_R8G8B8: // need to be expanded with alpha
                    return 32;

                case DXGI_FORMAT_P010:
                case DXGI_FORMAT_P016:
                    return 24;

                case DXGI_FORMAT_R8G8_TYPELESS:
                case DXGI_FORMAT_R8G8_UNORM:
                case DXGI_FORMAT_R8G8_UINT:
                case DXGI_FORMAT_R8G8_SNORM:
                case DXGI_FORMAT_R8G8_SINT:
                case DXGI_FORMAT_R16_TYPELESS:
                case DXGI_FORMAT_R16_FLOAT:
                case DXGI_FORMAT_D16_UNORM:
                case DXGI_FORMAT_R16_UNORM:
                case DXGI_FORMAT_R16_UINT:
                case DXGI_FORMAT_R16_SNORM:
                case DXGI_FORMAT_R16_SINT:
                case DXGI_FORMAT_B5G6R5_UNORM:
                case DXGI_FORMAT_B5G5R5A1_UNORM:
                case DXGI_FORMAT_A8P8:
                case DXGI_FORMAT_B4G4R4A4_UNORM:
                    return 16;

                case DXGI_FORMAT_NV12:
                case DXGI_FORMAT_NV11:
                    return 12;

                case DXGI_FORMAT_R8_TYPELESS:
                case DXGI_FORMAT_R8_UNORM:
                case DXGI_FORMAT_R8_UINT:
                case DXGI_FORMAT_R8_SNORM:
                case DXGI_FORMAT_R8_SINT:
                case DXGI_FORMAT_A8_UNORM:
                case DXGI_FORMAT_AI44:
                case DXGI_FORMAT_IA44:
                case DXGI_FORMAT_P8:
                    return 8;

                case DXGI_FORMAT_R1_UNORM:
                    return 1;

                case DXGI_FORMAT_BC1_TYPELESS:
                case DXGI_FORMAT_BC1_UNORM:
                case DXGI_FORMAT_BC1_UNORM_SRGB:
                case DXGI_FORMAT_BC4_TYPELESS:
                case DXGI_FORMAT_BC4_UNORM:
                case DXGI_FORMAT_BC4_SNORM:
                    return 64;

                case DXGI_FORMAT_BC2_TYPELESS:
                case DXGI_FORMAT_BC2_UNORM:
                case DXGI_FORMAT_BC2_UNORM_SRGB:
                case DXGI_FORMAT_BC3_TYPELESS:
                case DXGI_FORMAT_BC3_UNORM:
                case DXGI_FORMAT_BC3_UNORM_SRGB:
                case DXGI_FORMAT_BC5_TYPELESS:
                case DXGI_FORMAT_BC5_UNORM:
                case DXGI_FORMAT_BC5_SNORM:
                case DXGI_FORMAT_BC6H_TYPELESS:
                case DXGI_FORMAT_BC6H_UF16:
                case DXGI_FORMAT_BC6H_SF16:
                case DXGI_FORMAT_BC7_TYPELESS:
                case DXGI_FORMAT_BC7_UNORM:
                case DXGI_FORMAT_BC7_UNORM_SRGB:
                    return 128;
                default:
                    return 0;
            }
        }

        // returns 1 for non-block compressed formats, or the block size if it's compressed
        [[nodiscard]]
        constexpr unsigned BlockSize() const
        {
            switch (Format())
            {
                case DXGI_FORMAT_BC1_TYPELESS:
                case DXGI_FORMAT_BC1_UNORM:
                case DXGI_FORMAT_BC1_UNORM_SRGB:
                case DXGI_FORMAT_BC4_TYPELESS:
                case DXGI_FORMAT_BC4_UNORM:
                case DXGI_FORMAT_BC4_SNORM:
                case DXGI_FORMAT_BC2_TYPELESS:
                case DXGI_FORMAT_BC2_UNORM:
                case DXGI_FORMAT_BC2_UNORM_SRGB:
                case DXGI_FORMAT_BC3_TYPELESS:
                case DXGI_FORMAT_BC3_UNORM:
                case DXGI_FORMAT_BC3_UNORM_SRGB:
                case DXGI_FORMAT_BC5_TYPELESS:
                case DXGI_FORMAT_BC5_UNORM:
                case DXGI_FORMAT_BC5_SNORM:
                case DXGI_FORMAT_BC6H_TYPELESS:
                case DXGI_FORMAT_BC6H_UF16:
                case DXGI_FORMAT_BC6H_SF16:
                case DXGI_FORMAT_BC7_TYPELESS:
                case DXGI_FORMAT_BC7_UNORM:
                case DXGI_FORMAT_BC7_UNORM_SRGB:
                    return 4;
                default:
                    return 1;
            }
        }

        // returns the vulkan equivalent of the stored formats, some formats are not in vulkan and
        // hence are undefined.
        [[nodiscard]]
        constexpr VkFormat GetVulkanFormat() const
        {
            switch (Format())
            {
                case DXGI_FORMAT_R32G32B32A32_FLOAT:
                    return VK_FORMAT_R32G32B32A32_SFLOAT;
                case DXGI_FORMAT_R32G32B32A32_UINT:
                    return VK_FORMAT_R32G32B32A32_UINT;
                case DXGI_FORMAT_R32G32B32A32_SINT:
                    return VK_FORMAT_R32G32B32A32_SINT;
                case DXGI_FORMAT_R32G32B32_FLOAT:
                    return VK_FORMAT_R32G32B32_SFLOAT;
                case DXGI_FORMAT_R32G32B32_UINT:
                    return VK_FORMAT_R32G32B32_UINT;
                case DXGI_FORMAT_R32G32B32_SINT:
                    return VK_FORMAT_R32G32B32_SINT;
                case DXGI_FORMAT_R16G16B16A16_FLOAT:
                    return VK_FORMAT_R16G16B16A16_SFLOAT;
                case DXGI_FORMAT_R16G16B16A16_UNORM:
                    return VK_FORMAT_R16G16B16A16_UNORM;
                case DXGI_FORMAT_R16G16B16A16_UINT:
                    return VK_FORMAT_R16G16B16A16_UINT;
                case DXGI_FORMAT_R16G16B16A16_SNORM:
                    return VK_FORMAT_R16G16B16A16_SNORM;
                case DXGI_FORMAT_R16G16B16A16_SINT:
                    return VK_FORMAT_R16G16B16A16_SINT;
                case DXGI_FORMAT_R32G32_FLOAT:
                    return VK_FORMAT_R32G32_SFLOAT;
                case DXGI_FORMAT_R32G32_UINT:
                    return VK_FORMAT_R32G32_UINT;
                case DXGI_FORMAT_R32G32_SINT:
                    return VK_FORMAT_R32G32_SINT;
                case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
                    return VK_FORMAT_D32_SFLOAT_S8_UINT;
                case DXGI_FORMAT_R11G11B10_FLOAT:
                    return VK_FORMAT_B10G11R11_UFLOAT_PACK32;
                case DXGI_FORMAT_R8G8B8A8_UNORM:
                    return VK_FORMAT_R8G8B8A8_UNORM;
                case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
                    return VK_FORMAT_R8G8B8A8_SRGB;
                case DXGI_FORMAT_R8G8B8A8_UINT:
                    return VK_FORMAT_R8G8B8A8_UINT;
                case DXGI_FORMAT_R8G8B8A8_SNORM:
                    return VK_FORMAT_R8G8B8A8_SNORM;
                case DXGI_FORMAT_R8G8B8A8_SINT:
                    return VK_FORMAT_R8G8B8A8_SINT;
                case DXGI_FORMAT_R16G16_FLOAT:
                    return VK_FORMAT_R16G16_SFLOAT;
                case DXGI_FORMAT_R16G16_UNORM:
                    return VK_FORMAT_R16G16_UNORM;
                case DXGI_FORMAT_R16G16_UINT:
                    return VK_FORMAT_R16G16_UINT;
                case DXGI_FORMAT_R16G16_SNORM:
                    return VK_FORMAT_R16G16_SNORM;
                case DXGI_FORMAT_R16G16_SINT:
                    return VK_FORMAT_R16G16_SINT;
                case DXGI_FORMAT_D32_FLOAT:
                    return VK_FORMAT_D32_SFLOAT;
                case DXGI_FORMAT_R32_FLOAT:
                    return VK_FORMAT_R32_SFLOAT;
                case DXGI_FORMAT_R32_UINT:
                    return VK_FORMAT_R32_UINT;
                case DXGI_FORMAT_R32_SINT:
                    return VK_FORMAT_R32_SINT;
                case DXGI_FORMAT_D24_UNORM_S8_UINT:
                    return VK_FORMAT_D24_UNORM_S8_UINT;
                case DXGI_FORMAT_R8G8_UNORM:
                    return VK_FORMAT_R8G8_UNORM;
                case DXGI_FORMAT_R8G8_UINT:
                    return VK_FORMAT_R8G8_UINT;
                case DXGI_FORMAT_R8G8_SNORM:
                    return VK_FORMAT_R8G8_SNORM;
                case DXGI_FORMAT_R8G8_SINT:
                    return VK_FORMAT_R8G8_SINT;
                case DXGI_FORMAT_R16_FLOAT:
                    return VK_FORMAT_R16_SFLOAT;
                case DXGI_FORMAT_D16_UNORM:
                    return VK_FORMAT_D16_UNORM;
                case DXGI_FORMAT_R16_UNORM:
                    return VK_FORMAT_R16_UNORM;
                case DXGI_FORMAT_R16_UINT:
                    return VK_FORMAT_R16_UINT;
                case DXGI_FORMAT_R16_SNORM:
                    return VK_FORMAT_R16_SNORM;
                case DXGI_FORMAT_R16_SINT:
                    return VK_FORMAT_R16_SINT;
                case DXGI_FORMAT_R8_UNORM:
                    return VK_FORMAT_R8_UNORM;
                case DXGI_FORMAT_R8_UINT:
                    return VK_FORMAT_R8_UINT;
                case DXGI_FORMAT_R8_SNORM:
                    return VK_FORMAT_R8_SNORM;
                case DXGI_FORMAT_R8_SINT:
                    return VK_FORMAT_R8_SINT;
                case DXGI_FORMAT_BC1_UNORM:
                    return VK_FORMAT_BC1_RGB_UNORM_BLOCK;
                case DXGI_FORMAT_BC1_UNORM_SRGB:
                    return VK_FORMAT_BC1_RGB_SRGB_BLOCK;
                case DXGI_FORMAT_BC2_UNORM:
                    return VK_FORMAT_BC2_UNORM_BLOCK;
                case DXGI_FORMAT_BC2_UNORM_SRGB:
                    return VK_FORMAT_BC2_SRGB_BLOCK;
                case DXGI_FORMAT_BC3_UNORM:
                    return VK_FORMAT_BC3_UNORM_BLOCK;
                case DXGI_FORMAT_BC3_UNORM_SRGB:
                    return VK_FORMAT_BC3_SRGB_BLOCK;
                case DXGI_FORMAT_BC4_UNORM:
                    return VK_FORMAT_BC4_UNORM_BLOCK;
                case DXGI_FORMAT_BC4_SNORM:
                    return VK_FORMAT_BC4_SNORM_BLOCK;
                case DXGI_FORMAT_BC5_UNORM:
                    return VK_FORMAT_BC5_UNORM_BLOCK;
                case DXGI_FORMAT_BC5_SNORM:
                    return VK_FORMAT_BC5_SNORM_BLOCK;
                case DXGI_FORMAT_B5G6R5_UNORM:
                    return VK_FORMAT_B5G6R5_UNORM_PACK16;
                case DXGI_FORMAT_B5G5R5A1_UNORM:
                    return VK_FORMAT_B5G5R5A1_UNORM_PACK16;
                case DXGI_FORMAT_B8G8R8A8_UNORM:
                    return VK_FORMAT_B8G8R8A8_UNORM;
                case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
                    return VK_FORMAT_B8G8R8A8_SRGB;
                case DXGI_FORMAT_BC7_UNORM:
                    return VK_FORMAT_BC7_UNORM_BLOCK;
                case DXGI_FORMAT_BC7_UNORM_SRGB:
                    return VK_FORMAT_BC7_SRGB_BLOCK;
                case DXGI_FORMAT_BC6H_SF16:
                    return VK_FORMAT_BC6H_SFLOAT_BLOCK;
                default:
                    return VK_FORMAT_UNDEFINED;
            }
        }


        [[nodiscard]]
        constexpr VkExtent3D GetVulkanExtent() const
        {
            return VkExtent3D
            {
                .width = Width(),
                .height = Height(),
                .depth = Depth(),
            };
        }

        // returns the create info for a vulkan image view. image needs to be set manually
        [[nodiscard]]
        VkImageViewCreateInfo GetVulkanImageViewCreateInfo() const
        {
            const auto viewType = Is1D()
                                      ? VK_IMAGE_VIEW_TYPE_1D
                                      : Is3D()
                                            ? VK_IMAGE_VIEW_TYPE_3D
                                            : IsCubemap()
                                                  ? VK_IMAGE_VIEW_TYPE_CUBE
                                                  : VK_IMAGE_VIEW_TYPE_2D;
            const auto subresourceRange = VkImageSubresourceRange
            {
                .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                .levelCount = MipLevels(),
                .layerCount = ArraySize(),
            };
            return VkImageViewCreateInfo{
                .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
                .viewType = viewType,
                .format = GetVulkanFormat(),
                .subresourceRange = subresourceRange,
            };
        }

        // returns the create info for a vulkan image
        [[nodiscard]]
        constexpr VkImageCreateInfo GetVulkanImageCreateInfo(
            const VkImageUsageFlags usage,
            const VkSampleCountFlagBits sampleCount = VK_SAMPLE_COUNT_1_BIT,
            const VkSharingMode sharingMode = VK_SHARING_MODE_EXCLUSIVE) const
        {
            return VkImageCreateInfo{
                .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
                .flags = IsCubemap()
                             ? VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT
                             : VkImageCreateFlags(),
                .imageType = Is1D()
                                 ? VK_IMAGE_TYPE_1D
                                 : Is3D()
                                       ? VK_IMAGE_TYPE_3D
                                       : VK_IMAGE_TYPE_2D,
                .format = GetVulkanFormat(),
                .extent = VkExtent3D(Width(), Height(), Depth()),
                .mipLevels = MipLevels(),
                .arrayLayers = IsCubemap() ? 6u : 1u,
                .samples = sampleCount,
                .tiling = VK_IMAGE_TILING_OPTIMAL,
                .usage = usage,
                .sharingMode = sharingMode,
                .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
            };
        }

        // returns the size of a specific mipmap in bytes
        [[nodiscard]]
        constexpr unsigned long long MipSize(const unsigned mip) const
        {
            const unsigned long long bpe = BitsPerElement();
            const unsigned long long blocksize = BlockSize();
            unsigned long long num_elements_x = Width();
            unsigned long long num_elements_y = Height();
            unsigned long long num_elements_z = Depth();
            num_elements_x >>= mip;
            num_elements_y >>= mip;
            num_elements_z >>= mip;
            num_elements_x = num_elements_x < 1 ? 1 : num_elements_x;
            num_elements_y = num_elements_y < 1 ? 1 : num_elements_y;
            num_elements_z = num_elements_z < 1 ? 1 : num_elements_z;
            const unsigned long long num_blocks_x = (num_elements_x + blocksize - 1) / blocksize;
            const unsigned long long num_blocks_y = (num_elements_y + blocksize - 1) / blocksize;
            return num_blocks_x * num_blocks_y * num_elements_z * bpe / 8ull;
        }

        // returns the size of one slice in bytes
        [[nodiscard]]
        constexpr unsigned long long SliceSize() const
        {
            const unsigned mips = MipLevels();
            unsigned long long size = 0;
            for (unsigned mip = 0; mip < mips; ++mip)
            {
                size += MipSize(mip);
            }
            return size;
        }

        // returns the size of the whole pixel data in bytes, including all slices and mipmaps
        [[nodiscard]]
        constexpr unsigned long long DataSize() const
        {
            return ArraySize() * SliceSize();
        }

        // returns the offset of the pixel data relative to the beginning of the file, in bytes
        [[nodiscard]]
        constexpr unsigned long long DataOffset() const
        {
            unsigned long long offset = sizeof(Header);
            if (!IsDx10())
                offset -= sizeof(Header::header10);
            return offset;
        }

        // returns the offset of a specific slice relative to the beginning of the file, in bytes
        [[nodiscard]]
        constexpr unsigned long long SliceOffset(const unsigned slice) const
        {
            return DataOffset() + SliceSize() * slice;
        }

        // returns the offset of a specific mipmap of a specific slice relative to the beginning of
        // the file, in bytes
        [[nodiscard]]
        constexpr unsigned long long MipOffset(
            const unsigned mip,
            const unsigned slice = 0) const
        {
            unsigned long long offset = SliceOffset(slice);
            for (unsigned i = 0; i < mip; ++i)
            {
                offset += MipSize(i);
            }
            return offset;
        }

        // returns the size of one row in a specific mip level in bytes
        [[nodiscard]]
        constexpr unsigned RowPitch(const unsigned mip) const
        {
            const unsigned long long bpe = BitsPerElement();
            const unsigned long long blocksize = BlockSize();
            unsigned long long num_elements_x = Width();
            num_elements_x >>= mip;
            num_elements_x = num_elements_x < 1 ? 1 : num_elements_x;
            const unsigned long long num_blocks_x = (num_elements_x + blocksize - 1) / blocksize;
            return static_cast<unsigned>(num_blocks_x * bpe / 8);
        }

        // returns the size of a specific slice at a specific mip level in bytes
        [[nodiscard]]
        constexpr unsigned SlicePitch(const unsigned mip) const
        {
            const unsigned long long bpe = BitsPerElement();
            const unsigned long long blocksize = BlockSize();
            unsigned long long num_elements_x = Width();
            unsigned long long num_elements_y = Height();
            num_elements_x >>= mip;
            num_elements_y >>= mip;
            num_elements_x = num_elements_x < 1 ? 1 : num_elements_x;
            num_elements_y = num_elements_y < 1 ? 1 : num_elements_y;
            const unsigned long long num_blocks_x = (num_elements_x + blocksize - 1) / blocksize;
            const unsigned long long num_blocks_y = (num_elements_y + blocksize - 1) / blocksize;
            return static_cast<unsigned>(num_blocks_x * num_blocks_y * bpe / 8ull);
        }
    };

    // Read DDS header from memory
    //	data:	pointer to memory, this should be the very start of the DDS file (fourcc bytes
    // included) 	size:	size of memory that data points to. It should be sizeof(dds::Header)
    // or larger
    //
    //	returns dds::Header, which you can use to determine relative memory offsets and sizes
    // required to reference
    // certain parts of
    // the texture
    inline Header ReadHeader(const std::string &filePath)
    {
        auto stream = std::ifstream(filePath, std::ios::binary | std::ios::in);
        std::vector<char> headerData(sizeof(dds::Header) / sizeof(char));
        stream.read(headerData.data(), sizeof(dds::Header) / sizeof(char));
        Header h = {};
        if (headerData.data() == nullptr)
            return h; // invalid pointer
        h.magic = *(const unsigned *) headerData.data();
        if (h.magic != fourcc('D', 'D', 'S', ' '))
            return h; // fourcc is invalid

        h.header = *reinterpret_cast<const DDS_HEADER *>(
            static_cast<const char *>(headerData.data()) + sizeof(h.magic));
        if (h.IsDx10())
        {
            h.header10 = reinterpret_cast<const Header *>(headerData.data())->header10;
        }

        return h;
    }

    // Write the DDS header into memory.
    //	dst:		destination file in memory, must be at least of sizeof(dds::Header)
    //	format:		data format of texture data that will be placed after header
    //	width:		width of top mip level
    //	height:		height of top mip level (you can set this to 0 to indicate 1D texture)
    //	mip_levels:	number of mip levels in the file
    //	array_size:	number of slices in the file. For cubemaps, there is one slice for every
    // face. For 3D texture, there
    // is
    // always only 1 slice. 	is_cubemap:	whether the texture is a cubemap. If it is a
    // cubemap, it must have at least array_size = 6
    //	depth:		depth of 3D texture (you can set this to 0 to indicate that the texture is
    // not 3D)
    inline void WriteHeader(
        void *dst,
        const DXGI_FORMAT format,
        const unsigned int width,
        const unsigned int height,
        const unsigned int mip_levels = 1,
        const unsigned int array_size = 1,
        const bool is_cubemap = false,
        const unsigned int depth = 0)
    {
        Header h = {};
        h.magic = fourcc('D', 'D', 'S', ' ');
        h.header.dwSize = sizeof(DDS_HEADER);
        h.header.dwFlags =
                DDSD_CAPS | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT | DDSD_MIPMAPCOUNT;
        h.header.dwWidth = width;
        h.header.dwHeight = height;
        h.header.dwDepth = depth;
        h.header.dwMipMapCount = mip_levels;
        h.header.ddspf.dwSize = sizeof(DDS_PIXELFORMAT);
        h.header.ddspf.dwFlags = DDPF_FOURCC;
        h.header.ddspf.dwFourCC = fourcc('D', 'X', '1', '0');
        h.header.dwCaps = DDSCAPS_TEXTURE;

        h.header10.dxgiFormat = format;
        h.header10.resourceDimension = D3D10_RESOURCE_DIMENSION_TEXTURE2D;
        h.header10.miscFlags2 = DDS_ALPHA_MODE_UNKNOWN;

        if (is_cubemap)
        {
            h.header10.arraySize = array_size / 6;
            h.header.dwCaps |= DDSCAPS_COMPLEX;
            h.header.dwCaps2 = DDSCAPS2_CUBEMAP | DDSCAPS2_CUBEMAP_POSITIVEX |
                               DDSCAPS2_CUBEMAP_NEGATIVEX | DDSCAPS2_CUBEMAP_POSITIVEY |
                               DDSCAPS2_CUBEMAP_NEGATIVEY | DDSCAPS2_CUBEMAP_POSITIVEZ |
                               DDSCAPS2_CUBEMAP_NEGATIVEZ;
            h.header10.miscFlag = DDS_RESOURCE_MISC_TEXTURECUBE;
        } else if (depth > 0)
        {
            h.header10.arraySize = 1;
            h.header10.resourceDimension = D3D10_RESOURCE_DIMENSION_TEXTURE3D;
            h.header.dwCaps2 = DDSCAPS2_VOLUME;
        } else
        {
            h.header10.arraySize = array_size;
        }

        if (height == 0)
        {
            h.header10.resourceDimension = D3D10_RESOURCE_DIMENSION_TEXTURE1D;
            h.header.dwHeight = 1;
        }
        if (mip_levels > 1)
        {
            h.header.dwCaps |= DDSCAPS_COMPLEX;
        }

        *static_cast<Header *>(dst) = h;
    }
} // namespace dds

// Copyright(c) 2024 Allen Philip
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
