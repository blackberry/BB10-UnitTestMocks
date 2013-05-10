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
#ifndef cascades_imagebutton_h
#define cascades_imagebutton_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractbutton.h>
#include <bb/cascades/resources/image.h>
namespace bb {
  namespace cascades {
    class ImageButtonPrivate;
    class Container;
    class ImageButton : public AbstractButton {
public:
      ImageButton(Container * parent = 0);
      virtual ~ImageButton();
      MOCK_CONST_METHOD0(defaultImage, Image ());
      MOCK_METHOD1(setDefaultImage, void (const bb::cascades::Image& image));
      MOCK_METHOD0(resetDefaultImage, void ());
      MOCK_CONST_METHOD0(defaultImageSource, QUrl ());
      MOCK_METHOD1(setDefaultImageSource, void (const QUrl& source));
      MOCK_METHOD0(resetDefaultImageSource, void ());
      MOCK_CONST_METHOD0(pressedImage, Image ());
      MOCK_METHOD1(setPressedImage, void (const bb::cascades::Image& image));
      MOCK_METHOD0(resetPressedImage, void ());
      MOCK_CONST_METHOD0(pressedImageSource, QUrl ());
      MOCK_METHOD1(setPressedImageSource, void (const QUrl& source));
      MOCK_METHOD0(resetPressedImageSource, void ());
      MOCK_CONST_METHOD0(disabledImage, Image ());
      MOCK_METHOD1(setDisabledImage, void (const bb::cascades::Image& image));
      MOCK_METHOD0(resetDisabledImage, void ());
      MOCK_CONST_METHOD0(disabledImageSource, QUrl ());
      MOCK_METHOD1(setDisabledImageSource, void (const QUrl& source));
      MOCK_METHOD0(resetDisabledImageSource, void ());
      MOCK_METHOD1(defaultImageChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(defaultImageSourceChanged, void (const QUrl& source));
      MOCK_METHOD1(pressedImageChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(pressedImageSourceChanged, void (const QUrl& source));
      MOCK_METHOD1(disabledImageChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(disabledImageSourceChanged, void (const QUrl& source));
      MOCK_METHOD1(defaultImageChanged, void (const QVariant& image));
      MOCK_METHOD1(pressedImageChanged, void (const QVariant& image));
      MOCK_METHOD1(disabledImageChanged, void (const QVariant& image));
      typedef ImageButton ThisClass;
      typedef AbstractButton BaseClass;
    protected:
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
      protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
      public:
        BuilderType& defaultImage(const bb::cascades::Image& image) {
          this->instance().setDefaultImage(image);
          return this->builder();
        }
        BuilderType& pressedImage(const bb::cascades::Image& image) {
          this->instance().setPressedImage(image);
          return this->builder();
        }
        BuilderType& disabledImage(const bb::cascades::Image& image) {
          this->instance().setDisabledImage(image);
          return this->builder();
        }
        BuilderType& defaultImage(const QUrl& source) {
          return defaultImage(Image(source));
        }
        BuilderType& pressedImage(const QUrl& source) {
          return pressedImage(Image(source));
        }
        BuilderType& disabledImage(const QUrl& source) {
          return disabledImage(Image(source));
        }
      };
    public:
      class Builder : public TBuilder<Builder, ImageButton> {
      public:
        Builder() : TBuilder<Builder, ImageButton>(new ImageButton()) {}
      };
    static Builder create() {
        return Builder();
      }
    };
  }
}
#endif 
