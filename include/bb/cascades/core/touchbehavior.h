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
#ifndef cascades_touchbehavior_h
#define cascades_touchbehavior_h
#include "gmock/gmock.h"
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/core/touchtype.h>
#include <bb/cascades/core/propagationphase.h>
#include <bb/cascades/core/touchresponse.h>
#include <bb/cascades/core/eventreaction.h>
#include <bb/cascades/core/touchreaction.h>
namespace bb {
    namespace cascades {
class TouchBehaviorPrivate;
class TouchBehavior : public UIObject {
public:
    TouchBehavior() { }
    virtual ~TouchBehavior() { }
public:

    MOCK_METHOD1(addEventReaction, void(EventReaction* eventReaction));

    typedef UIObject BaseClass;
    template <typename BuilderType, typename BuiltType>
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
    {
    protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
        }
    public:
        BuilderType& addEventReaction(EventReaction* eventReaction)
        {
            this->instance().addEventReaction(eventReaction);
            return this->builder();
        }
        BuilderType& addTouchReaction(TouchType::Type touchType, PropagationPhase::Type phase, TouchResponse::Type response)
        {
            this->instance().addEventReaction(TouchReaction::create(touchType, phase, response));
            return this->builder();
        }
    };
    class Builder : public TBuilder<Builder, TouchBehavior>
    {
    public:
        Builder() : TBuilder<Builder, TouchBehavior>(new TouchBehavior())
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
