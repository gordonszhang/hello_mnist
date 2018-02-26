/* Gordon Zhang
 * CPSC 6040
 * 09.18.2017
 * image.cpp
 * Image class implementation
 */

#include <GL/freeglut.h>
#include "image.h"
#include <stdio.h>
#include <iostream>

using namespace std;
extern double hue_threshold, hue_ideal, saturation_threshold, value_threshold,
              saturation_ideal, value_ideal;
extern bool spill_supress;

// Image constructor. Takes a pixmap and the number of channels,
// converts it to RGBA encoding and stores a pointer in the object
Image::Image(int w, int h, int s_i, int channels, vector< vector<double> > image_arr) : width(w), height(h), displayed_channel(ALL) {
    width = w;
    height = h;
    vector<double> selected_image = image_arr[s_i];
    
    if(channels == 1) { // Grayscale
        pixels = new unsigned char[width * height * 4];
        rgba_pixel* rgba_pixmap = (rgba_pixel*)(pixels);
        // Convert to RGBA
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                int index = i * width + j;
                int flipped_index = (height - 1 - i) * width + j;
                //cout << selected_image[index] << " ";
                rgba_pixmap[index].r = selected_image[flipped_index];
                rgba_pixmap[index].g = selected_image[flipped_index];
                rgba_pixmap[index].b = selected_image[flipped_index];
                rgba_pixmap[index].a = 255;
            }
            //cout << endl;
        }
    }
}

// Image class destructor
Image::~Image() {
    delete pixels;
}

// Getter for currently selected pixmap. Returns a pointer to an
// array of unsigned char
unsigned char* Image::get_pixmap() {
    if (displayed_channel == ALL) { // All channels
        return pixels;
        //return (unsigned char*)mask;
    }
}

// Setter for currently displayed_channel. See constant
// declaration in structs.h
void Image::set_channel(int dc) {
    displayed_channel = dc;
}

// Getter for image width. Returns an int.
int Image::get_width() {
    return width;
}

// Getter for image height. Returns an int
int Image::get_height() {
    return height;
}

/*
Input RGB color primary values : r , g, and b on scale 0
−
255
Output HSV colors : h on scale 0
−
360, s and v on scale 0
−
1
*/

void Image::RGBtoHSV(int r, int g, int b, double &h, double &s, double &v)
{
    double red, green, blue;
    double max, min, delta;
    red = r / 255.0;
    green = g / 255.0;
    blue = b / 255.0;
    /*
    r, g, b to 0
    −
    1 scale
    */
    max = maximum(red, green, blue);
    min = minimum(red, green, blue);
    v = max;
    /*
    value is maximum of r, g, b
    */
    if (max == 0)
    {
        /*
        saturation and hue 0 if value is 0
        */
        s = 0;
        h = 0;
    }
    else
    {
        s = (max - min) / max;
        /*
        saturation is color purity on scale 0
        −
        1
        */
        delta = max - min;
        if (delta == 0)
        {
            /*
            hue doesn’t matter if saturation is 0
            */
            h = 0;
        }
        else
        {
            if (red == max)
            {
                /*
                otherwise , determine hue on scale 0
                −
                360
                */
                h = (green - blue) / delta;
            }
            else if (green == max)
            {
                h = 2.0 + (blue - red) / delta;
            }
            else
            {
                /*
                (blue == max)
                */
                h = 4.0 + (red - green) / delta;
            }
            h = h * 60.0;
            if (h < 0)
            {
                h = h + 360.0;
            }
        }
    }
}