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
#ifndef cascades_touchevent_h
#define cascades_touchevent_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QDebug>
#include <bb/cascades/core/event.h>
#include <bb/cascades/core/touchtype.h>
namespace bb {
    namespace cascades {
    class TouchEventPrivate;
    class VisualNode;
    class TouchEvent: public Event
    {
public:
        TouchEvent(TouchType::Type touchType, float screenX, float screenY, float windowX, float windowY, float localX, float localY, VisualNode* target);
        virtual ~TouchEvent();
        MOCK_METHOD0(type, QEvent::Type ());
        MOCK_CONST_METHOD0(screenX, float ());
        MOCK_CONST_METHOD0(screenY, float ());
        MOCK_CONST_METHOD0(windowX, float ());
        MOCK_CONST_METHOD0(windowY, float ());
        MOCK_CONST_METHOD0(localX, float ());
        MOCK_CONST_METHOD0(localY, float ());        
        MOCK_CONST_METHOD0(target, bb::cascades::VisualNode* ());
        MOCK_CONST_METHOD0(touchType, bb::cascades::TouchType::Type ());
        MOCK_CONST_METHOD0(isMove, bool ());
        MOCK_CONST_METHOD0(isUp, bool ());
        MOCK_CONST_METHOD0(isDown, bool ());
        MOCK_CONST_METHOD0(isCancel, bool ());
        MOCK_CONST_METHOD0(toDebugString, QString ());
};
}
}
#endif 
