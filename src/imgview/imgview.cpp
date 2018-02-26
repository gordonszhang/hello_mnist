/* Gordon Zhang
 * CPSC 6040
 * 09.18.2017
 * imgview.cpp
 * Command-line based image viewing application made using OIIO and GLUT.
 */

#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include "image.h"
#include "mnist_parser.h"

using namespace std;

// Constants
#define WIDTH 300
#define HEIGHT 300

// Global variables
int x, y;
int index = 0;
Image *image;
MNISTDataset *data;

// Draw selected pixmap to screen
void draw()
{
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    // Get image paramters and pixmap from class object
    glDrawPixels(image->get_width(), image->get_height(), GL_RGBA, GL_UNSIGNED_BYTE, image->get_pixmap());
    glFlush();
}

// Handle GL window input. Most behavior manipulates Image object
void input(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q': // q - quit
    case 'Q':
    case 27: // esc - quit
        delete image;
        exit(0);
    case 'b':
    case 'B':
        if(index == 0) return;
        index--;
        image = new Image(data->cols, data->rows, index, 1, data->image_arr);
        draw();
        return;
    case 'n':
    case 'N':
        if(index == data->num_images - 1) return;
        index++;
        cout << index;
        image = new Image(data->cols, data->rows, index, 1, data->image_arr);
        draw();
        return;
    default: // not a valid key -- just ignore it
        return;
    }
}

// Handle GL window resizing
void resize(int w, int h)
{
    // set the viewport to be the entire window
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    // Calculate render origin, attempting to center image
    x = (w - image->get_width()) / 2;
    y = (h - image->get_height()) / 2;

    // Get actual raster render origin, commented out 
    // int array[4];
    // glGetIntegerv(GL_CURRENT_RASTER_POSITION, array);

    // Resize image if window height or width is less than that of image
    double x_factor, y_factor;
    x_factor = 1.0;
    y_factor = 1.0;

    // If window width is less than image width and ratio is less than
    // window height / image height, scale based on width
    if (x < y && x < 0)
    {
        x_factor = double(w) / image->get_width();
        y_factor = x_factor;
    }

    // Otherwise, scale by height
    else if (y < x && y < 0)
    {
        y_factor = double(h) / image->get_height();
        x_factor = y_factor;
    }

    // Perform pixel zoom to scale image
    glPixelZoom(x_factor, y_factor);

    x = (w - image->get_width() * x_factor) / 2;
    y = (h - image->get_height() * y_factor) / 2;
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    glRasterPos2i(x, y); // Set raster render position, accounting for scale
}

int main(int argc, char *argv[])
{
    // Initialize a blank, black image with default width/height
    data = new MNISTDataset("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("imgview");
    glutDisplayFunc(draw);
    glutReshapeFunc(resize);
    glutKeyboardFunc(input);
    
    image = new Image(data->cols, data->rows, index, 1, data->image_arr);
    
    glutMainLoop();

    return 0;
}
