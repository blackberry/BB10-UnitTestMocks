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
#ifndef cascades_fadetransition_h
#define cascades_fadetransition_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/animation/abstracttransition.h>
namespace bb {
    namespace cascades {
class FadeTransitionPrivate;
class FadeTransition : public AbstractTransition {
public:
    FadeTransition() { }
    virtual ~FadeTransition() { }
    MOCK_CONST_METHOD0(fromOpacity, float ());
    MOCK_METHOD1(setFromOpacity, void (float value));
    MOCK_METHOD0(resetFromOpacity, void ());
    MOCK_CONST_METHOD0(toOpacity, float ());
    MOCK_METHOD1(setToOpacity, void (float value));
    MOCK_METHOD0(resetToOpacity, void ());
    MOCK_CONST_METHOD0(isToOpacitySet, bool ());
    MOCK_CONST_METHOD0(isFromOpacitySet, bool ());
    MOCK_METHOD1(fromOpacityChanged, void (float fromOpacity));
    MOCK_METHOD1(toOpacityChanged, void (float toOpacity));
public:
    typedef FadeTransition ThisClass;  
    typedef AbstractTransition BaseClass; 
    template <typename BuilderType, typename BuiltType>                                
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {              
    protected:                                                                         
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {  
        }                                                                                
    public:                                                                            
        BuilderType& from(float value) {
            this->instance().setFromOpacity(value);
            return  this->builder();
        }
        BuilderType& to(float value) {
            this->instance().setToOpacity(value);
            return  this->builder();
        }
    };
    class Builder : public TBuilder<Builder, FadeTransition> {
    public:
        Builder() : TBuilder<Builder, FadeTransition>(new FadeTransition()) {}
    };
  static Builder create(VisualNode *target = 0) {
        return Builder().target(target);
    }
};
}
}
#endif 
