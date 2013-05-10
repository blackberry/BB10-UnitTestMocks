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
#ifndef cascades_option_h
#define cascades_option_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/image.h>
#include <bb/cascades/controls/control.h>
namespace bb {
    namespace cascades {
    class OptionPrivate;
    class Option : public UIObject {
public:
        Option(Control *parent = 0);
        virtual ~Option();
        MOCK_CONST_METHOD0(image, Image ());
        MOCK_METHOD1(setImage, void (const Image& image));
        MOCK_METHOD0(resetImage, void ());
        MOCK_CONST_METHOD0(imageSource, QUrl ());
        MOCK_METHOD1(setImageSource, void (const QUrl &source));
        MOCK_METHOD0(resetImageSource, void ());
        MOCK_CONST_METHOD0(text, const QString ());
        MOCK_METHOD1(setText, void (const QString & text));
        MOCK_METHOD0(resetText, void ());
        MOCK_CONST_METHOD0(description, const QString ());
        MOCK_METHOD1(setDescription, void (const QString & description));
        MOCK_METHOD0(resetDescription, void ());
        MOCK_CONST_METHOD0(value, const QVariant ());
        MOCK_METHOD1(setValue, void (const QVariant & value));
        MOCK_METHOD0(resetValue, void ());
        MOCK_CONST_METHOD0(isSelected, bool ());
        MOCK_METHOD1(setSelected, void (bool selected));
        MOCK_METHOD0(resetSelected, void ());
        MOCK_CONST_METHOD0(isEnabled, bool ());
        MOCK_METHOD1(setEnabled, void (bool enabled));
        MOCK_METHOD0(resetEnabled, void ());
        MOCK_METHOD1(imageChanged, void (const bb::cascades::Image& image));
        MOCK_METHOD1(imageSourceChanged, void (const QUrl& imageSource));
        MOCK_METHOD1(imageChanged, void (const QVariant& image));
        MOCK_METHOD1(textChanged, void (QString text));
        MOCK_METHOD1(descriptionChanged, void (QString description));
        MOCK_METHOD1(valueChanged, void (QVariant value));
        MOCK_METHOD1(selectedChanged, void (bool selected));
        MOCK_METHOD1(enabledChanged, void (bool enabled));
        typedef Option ThisClass;
        typedef UIObject BaseClass;
    public:
        template <typename BuilderType, typename BuiltType> 
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) :
                     BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& image(const Image& image) {
                this->instance().setImage(image);
                return this->builder();
            }
            BuilderType& imageSource(const QUrl &url) {
                return image(Image(url));
            }
            BuilderType& text(const QString &text)
            {
                this->instance().setText(text);
                return this->builder();
            }
            BuilderType& description(const QString &description) 
            {
                this->instance().setDescription(description);
                return this->builder();
            }
            BuilderType& value(const QVariant &value) 
            {
                this->instance().setValue(value);
                return this->builder();
            }
            BuilderType& selected(bool selected)
            {
                this->instance().setSelected(selected);
                return this->builder();
            }
            BuilderType& enabled(bool enabled) {
                this->instance().setEnabled(enabled);
                return this->builder();
            }
            BuilderType& onSelectedChanged(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(selectedChanged(bool)), receiver, method);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Option>
        {
        public:
            Builder() : TBuilder<Builder, Option>(new Option())
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
