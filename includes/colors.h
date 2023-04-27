#ifndef COLORS_H
#define COLORS_H

struct color
    {
        float r;
        float g;
        float b;
    };

static color lightBrown = 
{
    .r = 0.87,
    .g = 0.72,
    .b = 0.53
};

void setBackgroundColor(color color);
color rgbToFloat(int r, int g, int b); 


#endif