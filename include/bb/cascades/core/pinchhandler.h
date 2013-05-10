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
#ifndef cascades_pinchhandler_h
#define cascades_pinchhandler_h
#include "gmock/gmock.h"
#include <bb/cascades/core/gesturehandler.h>
namespace bb {
    namespace cascades {
class PinchHandlerPrivate;
class PinchEvent;
class PinchHandler : public GestureHandler {
public:
    PinchHandler(bb::cascades::UIObject* parent = 0);
    virtual ~PinchHandler();
    MOCK_METHOD1(pinchStarted, void (bb::cascades::PinchEvent *event));
    MOCK_METHOD1(pinchUpdated, void (bb::cascades::PinchEvent *event));
    MOCK_METHOD1(pinchEnded, void (bb::cascades::PinchEvent *event));
    MOCK_METHOD0(pinchCancelled, void ());
public:
    typedef GestureHandler BaseClass;
    template <typename BuilderType, typename BuiltType>
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
    {
    protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
        }
    public:
        BuilderType& onPinch(const QObject* receiver,
                             const char *onStarted,
                             const char *onUpdated,
                             const char *onEnded,
                             const char *onCancelled)
        {
            if (onStarted) {
                this->connect(SIGNAL(pinchStarted(bb::cascades::PinchEvent*)), receiver, onStarted);
            }
            if (onUpdated) {
                this->connect(SIGNAL(pinchUpdated(bb::cascades::PinchEvent*)), receiver, onUpdated);
            }
            if (onEnded) {
                this->connect(SIGNAL(pinchEnded(bb::cascades::PinchEvent*)), receiver, onEnded);
            }
            if (onCancelled) {
                this->connect(SIGNAL(pinchCancelled()), receiver, onCancelled);
            }
            return this->builder();
        }
    };
    class Builder : public TBuilder<Builder, PinchHandler> {
    public:
        Builder() : TBuilder<Builder, PinchHandler>(new PinchHandler()) {}
    };
  static Builder create() {
        return Builder();
    }
};
}
}
#endif 
