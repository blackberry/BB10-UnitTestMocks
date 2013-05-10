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
#ifndef cascades_buttonmock_h
#define cascades_buttonmock_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractbuttonmock.h>
#include <bb/cascades/resources/image.h>
namespace bb {
    namespace cascades {
    class Container;
    class ButtonMock : public AbstractButtonMock {
public:
		ButtonMock(Container * parent = 0){}
		virtual ~ButtonMock(){}
        MOCK_CONST_METHOD0(text, const QString ());
        MOCK_METHOD1(setText, void (const QString & text));
        MOCK_METHOD0(resetText, void ());
        MOCK_CONST_METHOD0(image, Image ());
        MOCK_METHOD1(setImage, void (const bb::cascades::Image& image));
        MOCK_METHOD0(resetImage, void ());
        MOCK_CONST_METHOD0(imageSource, QUrl ());
        MOCK_METHOD1(setImageSource, void (const QUrl &source));
        MOCK_METHOD0(resetImageSource, void ());
        MOCK_METHOD1(textChanged, void (QString text));
        MOCK_METHOD1(imageChanged, void (const bb::cascades::Image& image));
        MOCK_METHOD1(imageSourceChanged, void (const QUrl& image));
        MOCK_METHOD1(imageChanged, void (const QVariant& image));
public:
        typedef ButtonMock ThisClass;
        typedef AbstractButtonMock BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        public:
            BuilderType& text(const QString &text) {
                this->instance().setText(text);
                return this->builder();
            }
            BuilderType& image(const Image& image) {
                this->instance().setImage(image);
                return this->builder();
            }
            BuilderType& imageSource(const QUrl &url) {
                return image(Image(url));
            }
            BuilderType& onClicked(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(clicked()), receiver, method);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, ButtonMock> {
        public:
            Builder() : TBuilder<Builder, ButtonMock>(new ButtonMock()) {}
        };
      static Builder create() {
            return Builder();
        }
      static Builder create(const QString & text) {
            return Builder().text(text);
        }
	};
}
}
#endif
