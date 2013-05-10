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
#ifndef cascades_rotatetransition_h
#define cascades_rotatetransition_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/animation/abstracttransition.h>
namespace bb {
    namespace cascades {
class XyzTransitionPrivate;
class RotateTransition : public AbstractTransition {
public:
    RotateTransition();
    virtual ~RotateTransition();
    MOCK_CONST_METHOD0(fromAngleZ, float ());
    MOCK_METHOD1(setFromAngleZ, void (float value));
    MOCK_METHOD0(resetFromAngleZ, void ());
    MOCK_CONST_METHOD0(toAngleZ, float ());
    MOCK_METHOD1(setToAngleZ, void (float value));
    MOCK_METHOD0(resetToAngleZ, void ());
    MOCK_CONST_METHOD0(isToAngleZSet, bool ());
    MOCK_CONST_METHOD0(isFromAngleZSet, bool ());
    MOCK_METHOD1(fromAngleZChanged, void (float fromAngleZ));
    MOCK_METHOD1(toAngleZChanged, void (float toAngleZ));
public:
    typedef RotateTransition ThisClass;  
    typedef AbstractTransition BaseClass; 
    template <typename BuilderType, typename BuiltType>                                
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {              
    protected:                                                                         
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {  
        }                                                                                
    public:                                                                            
        BuilderType& fromAngleZ(float value) {
            this->instance().setFromAngleZ(value);
            return  this->builder();
        }
        BuilderType& toAngleZ(float value) {
            this->instance().setToAngleZ(value);
            return  this->builder();
        }
    };
    class Builder : public TBuilder<Builder, RotateTransition> {
    public:
        Builder() : TBuilder<Builder, RotateTransition>(new RotateTransition()) {}
    };
  static Builder create(VisualNode *target = 0) {
        return Builder().target(target);
    }     
};    
}
}
#endif 
