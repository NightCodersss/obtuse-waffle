#include <iostream>
#include "image_processor.hpp"
#include "opencv_image_loader.hpp"
#include "opencv_image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv_image_binarizer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image>\n";
        return 0;
    }

    try 
    {
        auto loader = std::make_unique<OpenCVImageLoader>();
        auto image = loader->load(argv[1]);
        auto binarizer = std::make_unique<OpenCVImageBinarizer>();
        auto bin = binarizer->binarize(*image);
        ((OpenCVImage*)bin.get())->show();
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
