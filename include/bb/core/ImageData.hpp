/*
   Copyright 2013 Research In Motion Limited

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef BB_CORE_IMAGEDATA_HPP_
#define BB_CORE_IMAGEDATA_HPP_

#include "ImageDataMock.hpp"

#include <bb/testing/proxybase.h>

namespace bb
{

class ImageData : public bb::testing::ProxyBase<ImageDataMock>{
public:
	ImageData(PixelFormat::Type format, int width, int height) {}
	~ImageData() {}
	ImageData(const ImageData& other) {}

	//TODO: assignment operator not mocked
	ImageData& operator=(const ImageData & other);
	//TODO: static function not mocked
    static ImageData fromPixels(const unsigned char* sourceBuffer, PixelFormat::Type format, int width, int height, int sourceBytesPerLine)
    	{ return ImageData(PixelFormat::RGBX, 0, 0); }

	bool isValid() const { return mock()->isValid(); }
	PixelFormat::Type format() const { return mock()->format(); }
	int width() const { return mock()->width(); }
	int height() const { return mock()->height(); }
	int bytesPerLine() const { return mock()->bytesPerLine(); }
	unsigned char * pixels() { return mock()->pixels(); }
	const unsigned char * pixels() const { return mock()->pixels(); }
	const unsigned char * constPixels() const { return mock()->constPixels(); }
};

} /* namespace bb */

#endif /* BB_CORE_IMAGEDATA_HPP_ */
