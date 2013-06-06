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
#ifndef cascades_abstractanimation_h
#define cascades_abstractanimation_h
#include "gmock/gmock.h"
#include <QtDeclarative/QtDeclarative>
#include <QtDeclarative/QDeclarativeListProperty> 
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/core/visualnode.h>
#include <bb/cascades/animation/animationstate.h>
namespace bb {
    namespace cascades {
class AbstractAnimationPrivate;
class AbstractAnimation : public UIObject {
public:
    virtual ~AbstractAnimation() { }
    MOCK_CONST_METHOD0(target, bb::cascades::VisualNode *());
    MOCK_METHOD1(setTarget, void (bb::cascades::VisualNode * target));
    MOCK_METHOD0(resetTarget, void ());
    MOCK_CONST_METHOD0(state, bb::cascades::AnimationState::Type ());
    MOCK_CONST_METHOD0(isStarted, bool ());
    MOCK_CONST_METHOD0(isPlaying, bool ());
    MOCK_CONST_METHOD0(isStopped, bool ());
    MOCK_CONST_METHOD0(isEnded, bool ());
    MOCK_CONST_METHOD0(delay, int ());
    MOCK_METHOD1(setDelay, void (int delay));
    MOCK_METHOD0(resetDelay, void ());
    MOCK_CONST_METHOD0(repeatCount, int ());
    MOCK_METHOD1(setRepeatCount, void (int repeatCount));
    MOCK_METHOD0(resetRepeatCount, void ());
    static const int RepeatForever;
    MOCK_METHOD0(play, void ());
    MOCK_METHOD0(stop, void ());
    MOCK_METHOD0(started, void ());
    MOCK_METHOD0(stopped, void ());
    MOCK_METHOD0(ended, void ());
    MOCK_METHOD1(targetChanged, void (bb::cascades::VisualNode *target));
    MOCK_METHOD1(delayChanged, void (int delay));
    MOCK_METHOD1(repeatCountChanged, void (int repeatCount));
    MOCK_METHOD1(stateChanged, void (bb::cascades::AnimationState::Type state));
    MOCK_METHOD1(setAutoDeleted, void (bool));
public:
    typedef AbstractAnimation ThisClass;
    typedef UIObject BaseClass;
    template <typename BuilderType, typename BuiltType>                                
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {              
    protected:                                                                         
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {  
        }                                                                                
    public:                                                                            
        BuilderType& target(VisualNode *target) {
            this->instance().setTarget(target);
            return this->builder();
        }
        BuilderType& delay(int delay) {
            this->instance().setDelay(delay);
            return this->builder();
        }
        BuilderType& repeatCount(int repeatCount) {
            this->instance().setRepeatCount(repeatCount);
            return this->builder();
        }
        BuilderType& autoDeleted(bool autoDeleted = true) {
            this->instance().setAutoDeleted(autoDeleted);
            return this->builder();
        }
    };
};
}
}
#endif 
