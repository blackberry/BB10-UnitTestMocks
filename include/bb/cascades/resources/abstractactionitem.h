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
#ifndef cascades_abstractactionitem_h
#define cascades_abstractactionitem_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/resources/image.h>
namespace bb {
    namespace cascades {
        class AbstractActionItemPrivate;
        class AbstractActionItem : public UIObject
        {
public:
            virtual ~AbstractActionItem();
            MOCK_METHOD1(setTitle, void (const QString& title));
            MOCK_METHOD0(resetTitle, void ());
            MOCK_CONST_METHOD0(title, const QString ());
            MOCK_CONST_METHOD0(isEnabled, bool ());
            MOCK_METHOD1(setEnabled, void (bool enabled));
            MOCK_METHOD0(resetEnabled, void ());
            MOCK_CONST_METHOD0(image, bb::cascades::Image ());
            MOCK_METHOD1(setImage, void (const bb::cascades::Image& image));
            MOCK_METHOD0(resetImage, void ());
           MOCK_CONST_METHOD0(imageSource, QUrl ());
           MOCK_METHOD1(setImageSource, void (const QUrl &source));
           MOCK_METHOD0(resetImageSource, void ());
            MOCK_METHOD1(titleChanged, void (const QString& title));
            MOCK_METHOD0(triggered, void ());
            MOCK_METHOD1(enabledChanged, void (bool enabled));
            MOCK_METHOD1(imageChanged, void (const bb::cascades::Image& image));
            MOCK_METHOD1(imageSourceChanged, void (const QUrl& imageSource));
            MOCK_METHOD1(imageChanged, void (const QVariant& image));
public:
            typedef AbstractActionItem ThisClass;
            typedef UIObject BaseClass;
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
            {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
                {
                }
            public:
                BuilderType& title(const QString & title)
                {
                    this->instance().setTitle(title);
                    return this->builder();
                }          
                BuilderType& enabled(bool enabled)
                {
                    this->instance().setEnabled(enabled);
                    return this->builder();
                } 
                BuilderType& image(const bb::cascades::Image& image)
                {
                    this->instance().setImage(image);
                    return this->builder();
                } 
                BuilderType& imageSource(const QUrl &imageSource) {
                  return image(Image(imageSource));
                }
                BuilderType& onTriggered(const QObject* receiver, const char *method) {
                    this->connect(SIGNAL(triggered()), receiver, method);
                    return this->builder();
                }
            };
        };
    } 
}
#endif	
