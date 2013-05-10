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
#ifndef cascades_pinchevent_h
#define cascades_pinchevent_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QDebug>
#include <bb/cascades/core/abstractgestureevent.h>
namespace bb {
    namespace cascades {
    class PinchEventPrivate;
    class PinchEvent: public AbstractGestureEvent
    {
public:
        PinchEvent(float midPointX, float midPointY, float pinchRatio, float rotation, float distance);
        virtual ~PinchEvent();
        MOCK_METHOD0(type, QEvent::Type ());
        MOCK_CONST_METHOD0(midPointX, float ());
        MOCK_CONST_METHOD0(midPointY, float ());
        MOCK_CONST_METHOD0(pinchRatio, float ());
        MOCK_CONST_METHOD0(rotation, float ());
        MOCK_CONST_METHOD0(distance, float ());
        MOCK_CONST_METHOD1(touchPointX, float (int pointIndex));
        MOCK_CONST_METHOD1(touchPointY, float (int pointIndex));
        MOCK_CONST_METHOD0(toDebugString, QString ());
};
}
}
#endif 
