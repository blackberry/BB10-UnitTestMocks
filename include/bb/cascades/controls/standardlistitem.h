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
#ifndef cascades_standardlistitem_h
#define cascades_standardlistitem_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtCore/QVariant>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/resources/image.h>
#include <bb/cascades/controls/listitemlistener.h>
namespace bb {
    namespace cascades {
    class Container;
    class StandardListItemPrivate;
    class StandardListItem : public Control, public ListItemListener
    {
public:
        StandardListItem(Container * parent = 0) { }
        virtual ~StandardListItem() { }
        MOCK_CONST_METHOD0(image, Image ());
        MOCK_METHOD1(setImage, void (const Image& image));
        MOCK_METHOD0(resetImage, void ());
        MOCK_CONST_METHOD0(imageSource, QUrl ());
        MOCK_METHOD1(setImageSource, void (const QUrl &source));
        MOCK_METHOD0(resetImageSource, void ());
        MOCK_CONST_METHOD0(title, const QString ());
        MOCK_METHOD1(setTitle, void (const QString & title));
        MOCK_METHOD0(resetTitle, void ());
        MOCK_CONST_METHOD0(status, const QString ());
        MOCK_METHOD1(setStatus, void (const QString & status));
        MOCK_METHOD0(resetStatus, void ());
        MOCK_CONST_METHOD0(description, const QString ());
        MOCK_METHOD1(setDescription, void (const QString & description));
        MOCK_METHOD0(resetDescription, void ());
        MOCK_CONST_METHOD0(isImageSpaceReserved, bool ());
        MOCK_METHOD1(setImageSpaceReserved, void (bool imageSpaceReserved));
        MOCK_METHOD0(resetImageSpaceReserved, void ());
        MOCK_METHOD1(imageChanged, void (const bb::cascades::Image& image));
        MOCK_METHOD1(imageSourceChanged, void (const QUrl& imageSource));
        MOCK_METHOD1(imageChanged, void (QVariant image));
        MOCK_METHOD1(titleChanged, void (QString title));
        MOCK_METHOD1(statusChanged, void (QString status));
        MOCK_METHOD1(descriptionChanged, void (QString description));
        MOCK_METHOD1(imageSpaceReservedChanged, void (bool imageSpaceReserved));
public:
        typedef StandardListItem ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType> 
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) :
                     BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
    public:
        BuilderType& image(const Image& image)
        {
            this->instance().setImage(image);
            return this->builder();
        }
        BuilderType& imageSource(const QUrl &imageSource)
        {
            this->instance().setImage(Image(imageSource));
            return this->builder();
        }
        BuilderType& title(const QString &title)
        {
            this->instance().setTitle(title);
            return this->builder();
        }
        BuilderType& status(const QString &status)
        {
            this->instance().setStatus(status);
            return this->builder();
        }
        BuilderType& description(const QString &description) 
        {
            this->instance().setDescription(description);
            return this->builder();
        }
    };
    class Builder : public TBuilder<Builder, StandardListItem> {
        public:
           Builder() : TBuilder<Builder, StandardListItem>(new StandardListItem())
           {}
        };
      static Builder create()
        {
            return Builder();
        }
    };
}
}
#endif    
