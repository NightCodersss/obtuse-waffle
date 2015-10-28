#include "image_processor.hpp"
#include "opencv_image_loader.hpp"
#include "opencv_image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv_image_binarizer.hpp"

int main()
{
    auto loader = std::make_unique<OpenCVImageLoader>();
    auto image = loader->load("a.png");
    auto binarizer = std::make_unique<OpenCVImageBinarizer>();
    auto bin = binarizer->binarize(*image);
    ((OpenCVImage*)bin.get())->show();
    return 0;
}
