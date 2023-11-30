#pragma once
#include "glm/glm.hpp"

using color3_t = glm::vec3;
using color4_t = glm::vec4;
using rgba_t = uint32_t;


inline color3_t RGBColor(float r, float g, float b)
{
    r = glm::clamp(r, 0.0f, 1.0f);
    g = glm::clamp(g, 0.0f, 1.0f);
    b = glm::clamp(b, 0.0f, 1.0f);

    return color3_t(r, g, b);
}

inline color4_t RGBAColor(float r, float g, float b, float a)
{
    r = glm::clamp(r, 0.0f, 1.0f);
    g = glm::clamp(g, 0.0f, 1.0f);
    b = glm::clamp(b, 0.0f, 1.0f);
    a = glm::clamp(b, 0.0f, 1.0f);

    return color4_t(r, g, b, a);
}

inline rgba_t ConvertColorToUInt(const color4_t& color) 
{
    glm::ivec4 intColor = glm::clamp(glm::ivec4(color * 255.0f), 0, 255);

    // Pack into unsigned int( 8 bits per slot)
    return (intColor.r << 24) | (intColor.g << 16) | (intColor.b << 8) | (intColor.a);
}

inline color4_t ConvertUIntToColor(rgba_t colornumber)
{
    float r = ((colornumber >> 24) & 0xFF) * 1.0f / 255.0f;
    float g = ((colornumber >> 16) & 0xFF) * 1.0f / 255.0f;
    float b = ((colornumber >> 8) & 0xFF) * 1.0f / 255.0f;
    float a = (colornumber & 0xFF) * 1.0f / 255.0f;

    return color4_t(r, g, b, a);
}