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
#ifndef cascades_image_h
#define cascades_image_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QDebug>
#include <bb/ImageData>
#include <bb/cascades/resources/resource.h>
namespace bb {
    namespace cascades {
        class ImagePrivate;
        class Image : public Resource {
public:
            Image() { }
            Image(const QUrl& source) { }
            Image(const Image &other) { }
            Image(const ImageData& imageData) { }
            virtual ~Image() { }

            Image& operator=(const Image &other){ return mockedAssignment(other); };
            MOCK_METHOD1(mockedAssignment, Image&(const Image&));

            MOCK_CONST_METHOD0(source, QUrl ());
            MOCK_CONST_METHOD0(nineSliceMarginLeft, int ());
            MOCK_CONST_METHOD0(nineSliceMarginRight, int ());
            MOCK_CONST_METHOD0(nineSliceMarginTop, int ());
            MOCK_CONST_METHOD0(nineSliceMarginBottom, int ());
};
    }
}
#endif    
