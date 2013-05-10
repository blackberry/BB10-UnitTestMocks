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
#ifndef cascades_imagetracker_h
#define cascades_imagetracker_h
#include "gmock/gmock.h"
#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtCore/QSize>
#include <QtCore/QVariant>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/resourcetracker.h>
#include <bb/cascades/resources/image.h>
namespace bb {
    namespace cascades {
        class ImageTrackerPrivate;
        class ImageTracker : public ResourceTracker {
public:
            ImageTracker(QObject *parent = 0);
            ImageTracker(const QUrl& source, QObject *parent = 0);
            virtual ~ImageTracker();
            MOCK_METHOD1(setImageSource, void (const QUrl& source));
            MOCK_CONST_METHOD0(imageSource, QUrl ());
            MOCK_METHOD1(setImage, void (const Image& image));
            MOCK_CONST_METHOD0(image, Image ());
            MOCK_CONST_METHOD0(width, int ());
            MOCK_CONST_METHOD0(height, int ());
            MOCK_CONST_METHOD0(nineSliceMarginLeft, int ());
            MOCK_CONST_METHOD0(nineSliceMarginRight, int ());
            MOCK_CONST_METHOD0(nineSliceMarginTop, int ());
            MOCK_CONST_METHOD0(nineSliceMarginBottom, int ());
            MOCK_METHOD1(imageChanged, void (const QVariant& image));
            MOCK_METHOD1(imageSourceChanged, void (const QUrl& source));
            MOCK_METHOD2(sizeChanged, void (int width, int height));
            MOCK_METHOD1(widthChanged, void (int width));
            MOCK_METHOD1(heightChanged, void (int height));
            MOCK_METHOD4(nineSliceMarginsChanged, void (int left, int right, int top, int bottom));
            MOCK_METHOD1(nineSliceMarginLeftChanged, void (int margin));
            MOCK_METHOD1(nineSliceMarginTopChanged, void (int margin));
            MOCK_METHOD1(nineSliceMarginRightChanged, void (int margin));
            MOCK_METHOD1(nineSliceMarginBottomChanged, void (int margin));
        };
    }
}
#endif 
