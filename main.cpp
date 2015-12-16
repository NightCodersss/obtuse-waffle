#include <iostream>
#include "opencv_image_loader.hpp"
#include "opencv_image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "image_preprocessor.hpp"
#include "opencv_image_binarizer.hpp"
#include "opencv_image_denoiser.hpp"
#include "opencv_image.hpp"
#include "image_processor.hpp"

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

        std::unique_ptr<Command<OpenCVColorType>> binarizer = std::make_unique<OpenCVImageBinarizer>();
        std::unique_ptr<Command<OpenCVColorType>> denoiser = std::make_unique<OpenCVImageDenoiser>();

        ImagePreprocessor<OpenCVColorType> prep;
        auto im = prep.preprocess(*image, { std::cref(*denoiser), std::cref(*binarizer), std::cref(*denoiser)});

        im->show();
    }

    catch (std::exception& error)
    {
		BOOST_LOG_TRIVIAL(error) << error.what();
    }

    return 0;
}
