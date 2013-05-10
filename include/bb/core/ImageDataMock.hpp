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

#ifndef BB_CORE_IMAGEDATAMOCK_HPP_
#define BB_CORE_IMAGEDATAMOCK_HPP_

#include <gmock/gmock.h>

#include <bb/PixelFormat>

namespace bb
{

//class ImageData;

class ImageDataMock
{
public:
	ImageDataMock() {};
	~ImageDataMock() {};
	MOCK_CONST_METHOD0(isValid, bool());
    MOCK_CONST_METHOD0(format, PixelFormat::Type());
    MOCK_CONST_METHOD0(width, int());
    MOCK_CONST_METHOD0(height, int());
    MOCK_CONST_METHOD0(bytesPerLine, int());
    MOCK_METHOD0(pixels, unsigned char*());
    MOCK_CONST_METHOD0(pixels, const unsigned char*());
    MOCK_CONST_METHOD0(constPixels, const unsigned char*());
};

} /* namespace bb */

#endif /* BB_CORE_IMAGEDATAMOCK_HPP_ */
