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
#ifndef cascades_imageview_h
#define cascades_imageview_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/resources/image.h>
#include <bb/cascades/controls/scalingmethod.h>
namespace bb {
    namespace cascades {
        class Container;
        class ImageViewPrivate;
        class ImageView : public Control {
public:
            ImageView(Container * parent = 0) { }
            virtual ~ImageView() { }
            MOCK_CONST_METHOD0(image, Image ());
            MOCK_METHOD1(setImage, void (const Image& image));
            MOCK_METHOD0(resetImage, void ());       
            MOCK_CONST_METHOD0(imageSource, QUrl ());
            MOCK_METHOD1(setImageSource, void (const QUrl &source));
            MOCK_METHOD0(resetImageSource, void ());
            MOCK_CONST_METHOD0(scalingMethod, bb::cascades::ScalingMethod::Type ());
            MOCK_METHOD1(setScalingMethod, void (bb::cascades::ScalingMethod::Type scalingMethod));
            MOCK_METHOD0(resetScalingMethod, void ());
            MOCK_METHOD1(imageChanged, void (const bb::cascades::Image image));
            MOCK_METHOD1(imageSourceChanged, void (const QUrl& imageSource));
            MOCK_METHOD1(imageChanged, void (QVariant image));
            MOCK_METHOD1(scalingMethodChanged, void (bb::cascades::ScalingMethod::Type newScalingMethod));
            typedef ImageView ThisClass;  
            typedef Control BaseClass; 
       public:
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
            public:
                BuilderType& image(const Image& image) {
                    this->instance().setImage(image);
                    return this->builder();
                }
                BuilderType& imageSource(const QUrl &imageSource) {
                    return image(Image(imageSource));
                }
                BuilderType& scalingMethod(bb::cascades::ScalingMethod::Type scalingMethod) {
                    this->instance().setScalingMethod(scalingMethod);
                    return this->builder();
                }
            };
             class Builder : public TBuilder<Builder, ImageView> {
             public:
               Builder() : TBuilder<Builder, ImageView>(new ImageView()) {}
             };
             static Builder create() {
               return Builder();
             }
            static Builder create(const QString & filePath) {
                return Builder().imageSource(filePath);
            }
        };
    }
}
#endif	
