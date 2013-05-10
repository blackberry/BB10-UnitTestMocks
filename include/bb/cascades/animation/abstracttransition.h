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
#ifndef cascades_abstracttransition_h
#define cascades_abstracttransition_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/animation/abstractanimation.h>
namespace bb {
    namespace cascades {
class AbstractTransitionPrivate;
class EasingCurve;
class AbstractTransition : public AbstractAnimation {
public:
    MOCK_CONST_METHOD0(duration, int ());
    MOCK_METHOD1(setDuration, void (int duration));
    MOCK_METHOD0(resetDuration, void ());
    MOCK_METHOD1(setEasingCurve, void (const bb::cascades::EasingCurve &curve));
    MOCK_CONST_METHOD0(easingCurve, QVariant ());
    MOCK_METHOD0(resetEasingCurve, void ());
    virtual ~AbstractTransition() { }
    MOCK_METHOD1(durationChanged, void (int duration));
    MOCK_METHOD1(easingCurveChanged, void (const QVariant &easingCurve));
public:
    typedef AbstractTransition ThisClass;
    typedef AbstractAnimation BaseClass;
    template <typename BuilderType, typename BuiltType>                                
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {              
    protected:                                                                         
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {  
        }                                                                                
    public:                                                                            
        BuilderType& duration(int duration) {
            this->instance().setDuration(duration);
            return  this->builder();
        }
        BuilderType& easingCurve(const bb::cascades::EasingCurve &curve) {
            this->instance().setEasingCurve(curve);
            return this->builder();
        }
    };
};
}
}
#endif 
