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
#ifndef cascades_taphandler_h
#define cascades_taphandler_h
#include "gmock/gmock.h"
#include <bb/cascades/core/gesturehandler.h>
namespace bb {
    namespace cascades {
class TapHandlerPrivate;
class TapEvent;
class TapHandler : public GestureHandler {
public:
    TapHandler(bb::cascades::UIObject* parent = 0) { }
    virtual ~TapHandler() { }
    MOCK_METHOD1(tapped, void (bb::cascades::TapEvent *event));
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
        BuilderType& onTapped(const QObject* receiver, const char *method) {
            this->connect(SIGNAL(tapped(bb::cascades::TapEvent*)), receiver, method);
            return this->builder();
        }
    };
    class Builder : public TBuilder<Builder, TapHandler> {
    public:
        Builder() : TBuilder<Builder, TapHandler>(new TapHandler()) {}
    };
    static Builder create() {
        return Builder();
    }
};
}
}
#endif 
