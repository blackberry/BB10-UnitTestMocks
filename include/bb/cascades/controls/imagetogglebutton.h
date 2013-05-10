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
#ifndef cascades_imagetogglebutton_h
#define cascades_imagetogglebutton_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstracttogglebutton.h>
#include <bb/cascades/resources/image.h>
namespace bb {
  namespace cascades {
    class ImageToggleButtonPrivate;
    class Container;
    class ImageToggleButton : public AbstractToggleButton
    {
public:
      ImageToggleButton(Container * parent = 0);
      virtual ~ImageToggleButton();
      MOCK_CONST_METHOD0(imageDefault, Image ());
      MOCK_METHOD1(setImageDefault, void (const Image& image));
      MOCK_METHOD0(resetImageDefault, void ());       
      MOCK_CONST_METHOD0(imageSourceDefault, QUrl ());
      MOCK_METHOD1(setImageSourceDefault, void (const QUrl &source));
      MOCK_METHOD0(resetImageSourceDefault, void ());
      MOCK_CONST_METHOD0(imageChecked, Image ());
      MOCK_METHOD1(setImageChecked, void (const Image& image));
      MOCK_METHOD0(resetImageChecked, void ());       
      MOCK_CONST_METHOD0(imageSourceChecked, QUrl ());
      MOCK_METHOD1(setImageSourceChecked, void (const QUrl &source));
      MOCK_METHOD0(resetImageSourceChecked, void ());
      MOCK_CONST_METHOD0(imageDisabledUnchecked, Image ());
      MOCK_METHOD1(setImageDisabledUnchecked, void (const Image& image));
      MOCK_METHOD0(resetImageDisabledUnchecked, void ());       
      MOCK_CONST_METHOD0(imageSourceDisabledUnchecked, QUrl ());
      MOCK_METHOD1(setImageSourceDisabledUnchecked, void (const QUrl &source));
      MOCK_METHOD0(resetImageSourceDisabledUnchecked, void ());
      MOCK_CONST_METHOD0(imageDisabledChecked, Image ());
      MOCK_METHOD1(setImageDisabledChecked, void (const Image& image));
      MOCK_METHOD0(resetImageDisabledChecked, void ());       
      MOCK_CONST_METHOD0(imageSourceDisabledChecked, QUrl ());
      MOCK_METHOD1(setImageSourceDisabledChecked, void (const QUrl &source));
      MOCK_METHOD0(resetImageSourceDisabledChecked, void ());
      MOCK_CONST_METHOD0(imagePressedUnchecked, Image ());
      MOCK_METHOD1(setImagePressedUnchecked, void (const Image& image));
      MOCK_METHOD0(resetImagePressedUnchecked, void ());       
      MOCK_CONST_METHOD0(imageSourcePressedUnchecked, QUrl ());
      MOCK_METHOD1(setImageSourcePressedUnchecked, void (const QUrl &source));
      MOCK_METHOD0(resetImageSourcePressedUnchecked, void ());
      MOCK_CONST_METHOD0(imagePressedChecked, Image ());
      MOCK_METHOD1(setImagePressedChecked, void (const Image& image));
      MOCK_METHOD0(resetImagePressedChecked, void ());       
      MOCK_CONST_METHOD0(imageSourcePressedChecked, QUrl ());
      MOCK_METHOD1(setImageSourcePressedChecked, void (const QUrl &source));
      MOCK_METHOD0(resetImageSourcePressedChecked, void ());
      MOCK_METHOD1(imageDefaultChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(imageSourceDefaultChanged, void (const QUrl& imageSource));
      MOCK_METHOD1(imageDefaultChanged, void (QVariant image));
      MOCK_METHOD1(imageCheckedChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(imageSourceCheckedChanged, void (const QUrl& imageSource));
      MOCK_METHOD1(imageCheckedChanged, void (QVariant image));
      MOCK_METHOD1(imageDisabledUncheckedChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(imageSourceDisabledUncheckedChanged, void (const QUrl& imageSource));
      MOCK_METHOD1(imageDisabledUncheckedChanged, void (QVariant image));
      MOCK_METHOD1(imageDisabledCheckedChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(imageSourceDisabledCheckedChanged, void (const QUrl& imageSource));
      MOCK_METHOD1(imageDisabledCheckedChanged, void (QVariant image));
      MOCK_METHOD1(imagePressedUncheckedChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(imageSourcePressedUncheckedChanged, void (const QUrl& imageSource));
      MOCK_METHOD1(imagePressedUncheckedChanged, void (QVariant image));
      MOCK_METHOD1(imagePressedCheckedChanged, void (const bb::cascades::Image& image));
      MOCK_METHOD1(imageSourcePressedCheckedChanged, void (const QUrl& imageSource));
      MOCK_METHOD1(imagePressedCheckedChanged, void (QVariant image));
      typedef ImageToggleButton ThisClass;
      typedef AbstractToggleButton BaseClass;
      const QVariant imageQmlDefault() const;
      void setImageQmlDefault(const QVariant & image);
      const QVariant imageQmlChecked() const;
      void setImageQmlChecked(const QVariant & image);
      const QVariant imageQmlDisabledUnchecked() const;
      void setImageQmlDisabledUnchecked(const QVariant & image);
      const QVariant imageQmlDisabledChecked() const;
      void setImageQmlDisabledChecked(const QVariant & image);
      const QVariant imageQmlPressedUnchecked() const;
      void setImageQmlPressedUnchecked(const QVariant & image);
      const QVariant imageQmlPressedChecked() const;
      void setImageQmlPressedChecked(const QVariant & image);
    public:
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
      {
      protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
        }
      public:
        BuilderType& imageDefault(const Image& image) {
          this->instance().setImageDefault(image);
          return this->builder();
        }
        BuilderType& imageDefault(const QUrl &imageFilePath) {
          return imageDefault(Image(imageFilePath));
        }
        BuilderType& imageChecked(const Image& image) {
          this->instance().setImageChecked(image);
          return this->builder();
        }
        BuilderType& imageChecked(const QUrl &imageFilePath) {
          return imageChecked(Image(imageFilePath));
        }
        BuilderType& imageDisabledUnchecked(const Image& image) {
          this->instance().setImageDisabledUnchecked(image);
          return this->builder();
        }
        BuilderType& imageDisabledUnchecked(const QUrl &imageFilePath) {
          return imageDisabledUnchecked(Image(imageFilePath));
        }
        BuilderType& imageDisabledChecked(const Image& image) {
          this->instance().setImageDisabledChecked(image);
          return this->builder();
        }
        BuilderType& imageDisabledChecked(const QUrl &imageFilePath) {
          return imageDisabledChecked(Image(imageFilePath));
        }
        BuilderType& imagePressedUnchecked(const Image& image) {
          this->instance().setImagePressedUnchecked(image);
          return this->builder();
        }
        BuilderType& imagePressedUnchecked(const QUrl &imageFilePath) {
          return imagePressedUnchecked(Image(imageFilePath));
        }
        BuilderType& imagePressedChecked(const Image& image) {
          this->instance().setImagePressedChecked(image);
          return this->builder();
        }
        BuilderType& imagePressedChecked(const QUrl &imageFilePath) {
          return imagePressedChecked(Image(imageFilePath));
        }
      };
      class Builder : public TBuilder<Builder, ImageToggleButton>
      {
      public:
        Builder() : TBuilder<Builder, ImageToggleButton>(new ImageToggleButton())
        {
        }
      };
    static Builder create()
      {
        return Builder();
      }
    };
  }
}
#endif
