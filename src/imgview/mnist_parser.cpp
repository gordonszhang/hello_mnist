/*
 * Created by Derek Rodriguez on 2/14/18.
 * Last edited by:
 */

#include "mnist_parser.h"

MNISTDataset::MNISTDataset(string image_path, string label_path) : image_arr(), label_arr(), num_images(), rows(), cols()
{
    ifstream image_file(image_path.c_str(), ifstream::binary);
    if (image_file.is_open())
    {
        int magic_number = 0;
        image_file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = FlipEndian(magic_number);

        if(magic_number != 2051) {
            cout << "Invalid image file" << endl;
            return;
        }

        image_file.read((char*)&num_images,sizeof(num_images));
        num_images = FlipEndian(num_images);
        image_file.read((char*)&rows,sizeof(rows));
        rows= FlipEndian(rows);
        image_file.read((char*)&cols,sizeof(cols));
        cols= FlipEndian(cols);

        image_arr.resize(num_images, vector<double>(rows * cols));

        for(int i = 0; i < num_images; ++i)
        {
            for(int r = 0; r < rows; ++r)
            {
                for(int c = 0; c < cols; ++c)
                {
                    unsigned char temp = 0;
                    image_file.read((char*)&temp, sizeof(temp));
                    image_arr[i][(rows * r) + c] = (double)temp;
                }
            }
        }
    }
    else 
    {
        cout << "Error opening image file" << endl;
    }

    ifstream label_file(label_path.c_str(), ifstream::binary);
    if (label_file.is_open())
    {
        int magic_number = 0;
        int num_labels = 0;
        label_file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = FlipEndian(magic_number);
        label_file.read((char*)&num_labels,sizeof(num_labels));
        num_labels = FlipEndian(num_labels);
        
        if(magic_number != 2049) {
            cout << "Invalid label file" << endl;
            return;
        }
        if(num_images != num_labels) {
            cout << "Label file does not match image file" << endl;
            return;
        }

        label_arr.resize(num_images);

        for(int i = 0; i < num_images; ++i)
        {
            unsigned char temp = 0;
            label_file.read((char*)&temp, sizeof(temp));
            label_arr[i] = (int)temp;
        }
    }
    else 
    {
        cout << "Error opening label file" << endl;
    }
}
/*
int main()
{
    MNISTDataset data("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");
    return 0;
}
*/