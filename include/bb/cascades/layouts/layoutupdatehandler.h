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
#ifndef cascades_layoutupdatehandler_h
#define cascades_layoutupdatehandler_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
#include <QRectF>
#include <bb/cascades/BaseObject>
namespace bb {
namespace cascades {
    class Control;
    class LayoutUpdateHandlerPrivate;
    class LayoutUpdateHandler : public BaseObject {
public:
        LayoutUpdateHandler() { }
        LayoutUpdateHandler(Control *target) { }
        virtual ~LayoutUpdateHandler() { }
        MOCK_CONST_METHOD0(layoutFrame, QRectF ());
        MOCK_METHOD1(layoutFrameChanged, void (const QRectF &layoutFrame));

        class Builder {
        public:
            Builder(Control *target) { }
            ~Builder() { }
            //operator LayoutUpdateHandler*() { }
            Builder& onLayoutFrameChanged(QObject *receiver, const char* method) {
            	return *(new Builder(NULL));
            }
        };
        static Builder create(Control *target) {
            return Builder(target);
        }
    };
}
}
#endif	
