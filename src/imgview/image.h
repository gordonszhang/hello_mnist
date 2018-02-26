/* Gordon Zhang
 * CPSC 6040
 * 09.18.2017
 * image.h
 * Image class header. Class contains descriptive information, 
 * separated RGB channel pixmaps, as well as an RGBA pixmap
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "structs.h"
#include <vector>

using namespace std;
class Image {
    public:
        Image(int, int, int, int, vector< vector<double> >);
        ~Image();
        void set_channel(int);
        unsigned char* get_pixmap();
        int get_width();
        int get_height();
        void RGBtoHSV(int, int, int, double&, double&, double&);
        static Image* over(Image* fg, Image* bg);
    private:
        int width, height, displayed_channel;
        unsigned char *pixels;
};

#endif