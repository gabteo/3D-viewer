#ifndef COLORS_H
#define COLORS_H

struct color
{
    float r;
    float g;
    float b;

    void operator*(float contrast)
    {
        r *= contrast;
        g *= contrast;
        b *= contrast;

        r = r > 1.0f ? 1.0f : r;
        g = g > 1.0f ? 1.0f : g;
        b = b > 1.0f ? 1.0f : b;
    }
};

static color lightBrown = 
{
    .r = 0.87,
    .g = 0.72,
    .b = 0.53
};

static color darkBrown = 
{
    .r = 0.87*0.9,
    .g = 0.72*0.9,
    .b = 0.53*0.4
};  

void setBackgroundColor(color color);
color rgbToFloat(int r, int g, int b); 


#endif