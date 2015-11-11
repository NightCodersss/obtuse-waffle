#include <iostream>
#include "image_processor.hpp"
#include "opencv_image_loader.hpp"
#include "opencv_image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv_image_binarizer.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>

int main(int argc, char **argv)
{
	boost::log::add_file_log(
			boost::log::keywords::file_name = "./log.log",
			boost::log::keywords::auto_flush = true
			);
	BOOST_LOG_TRIVIAL(trace) << "Log begin";

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image>\n";
		BOOST_LOG_TRIVIAL(error) << "Started without image. Stopping.";
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
		BOOST_LOG_TRIVIAL(error) << e.what();
    }

    return 0;
}
