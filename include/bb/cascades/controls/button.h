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
#ifndef cascades_button_h
#define cascades_button_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstractbutton.h>
#include <bb/cascades/resources/image.h>
#include <bb/cascades/controls/buttonmock.h>
#include <bb/cascades/controls/container.h>
#include <bb/testing/proxybase.h>

namespace bb {
    namespace cascades {
    class ButtonPrivate;
    class Button : public AbstractButton {
public:
    	Button(bb::cascades::Container * parent = 0): AbstractButton(parent) { };

    	virtual ~Button(){}
    	const QString text(){return mock<ButtonMock>()->text();}
        void setText(const QString& text){mock<ButtonMock>()->setText(text);}
        void resetText(){mock<ButtonMock>()->resetText();}
        Image image(){return mock<ButtonMock>()->image();}
        void setImage(const bb::cascades::Image& image){mock<ButtonMock>()->setImage(image);}
        void resetImage(){mock<ButtonMock>()->resetImage();}
        QUrl imageSource(){return mock<ButtonMock>()->imageSource();}
        void setImageSource(const QUrl& source){mock<ButtonMock>()->setImageSource(source);}
        void resetImageSource(){mock<ButtonMock>()->resetImageSource();}
        void textChanged(QString text){mock<ButtonMock>()->textChanged(text);}
        void imageChanged(const bb::cascades::Image& image){mock<ButtonMock>()->imageChanged(image);}
        void imageSourceChanged(const QUrl& image){mock<ButtonMock>()->imageSourceChanged(image);}
        void imageChanged(const QVariant& image){mock<ButtonMock>()->imageChanged(image);}
public:
        typedef Button ThisClass;  
        typedef AbstractButton BaseClass; 
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
        class Builder : public TBuilder<Builder, Button> {
        public:
            Builder() : TBuilder<Builder, Button>(new Button()) {}
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
