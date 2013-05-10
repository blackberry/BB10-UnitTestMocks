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
#ifndef cascades_touchreaction_h
#define cascades_touchreaction_h
#include "gmock/gmock.h"
#include <QObject>
#include <QtDeclarative/QtDeclarative>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/touchtype.h>
#include <bb/cascades/core/touchresponse.h>
#include <bb/cascades/core/propagationphase.h>
#include <bb/cascades/core/eventreaction.h>
namespace bb {
    namespace cascades {
class TouchReactionPrivate;
class TouchReaction : public EventReaction {
public:
    virtual ~TouchReaction() { }
public:

    MOCK_METHOD1(setEventType, void(TouchType::Type touchType));
    MOCK_METHOD1(setPhase, void(PropagationPhase::Type phase));
    MOCK_METHOD1(setResponse, void(TouchResponse::Type touchResponse));

    typedef EventReaction BaseClass;
    template <typename BuilderType, typename BuiltType>
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
    {
    protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
        {
        }
    public:
        BuilderType& event(TouchType::Type touchType)
        {
            this->instance().setEventType(touchType);
            return this->builder();
        }
        BuilderType& phase(PropagationPhase::Type phase)
        {
            this->instance().setPhase(phase);
            return this->builder();
        }
        BuilderType& response(TouchResponse::Type touchResponse)
        {
            this->instance().setResponse(touchResponse);
            return this->builder();
        }
    };
    class Builder : public TBuilder<Builder, TouchReaction>
    {
    public:
        Builder() : TBuilder<Builder, TouchReaction>(new TouchReaction())
        {
        }
    };
  static Builder create(TouchType::Type touchType, PropagationPhase::Type phase, TouchResponse::Type response)
    {
        return Builder().event(touchType).phase(phase).response(response);
    }
};
}
}
#endif 
