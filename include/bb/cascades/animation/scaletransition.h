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
#ifndef cascades_scaletransition_h
#define cascades_scaletransition_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/animation/abstracttransition.h>
namespace bb {
  namespace cascades {
class XyzTransitionPrivate;
class ScaleTransition : public AbstractTransition {
public:
    ScaleTransition();
    virtual ~ScaleTransition();
    MOCK_CONST_METHOD0(fromX, float ());
    MOCK_METHOD1(setFromX, void (float value));
    MOCK_METHOD0(resetFromX, void ());
    MOCK_CONST_METHOD0(toX, float ());
    MOCK_METHOD1(setToX, void (float value));
    MOCK_METHOD0(resetToX, void ());
    MOCK_CONST_METHOD0(fromY, float ());
    MOCK_METHOD1(setFromY, void (float value));
    MOCK_METHOD0(resetFromY, void ());
    MOCK_CONST_METHOD0(toY, float ());
    MOCK_METHOD1(setToY, void (float value));
    MOCK_METHOD0(resetToY, void ());
    MOCK_CONST_METHOD0(isToXSet, bool ());
    MOCK_CONST_METHOD0(isFromXSet, bool ());
    MOCK_CONST_METHOD0(isToYSet, bool ());
    MOCK_CONST_METHOD0(isFromYSet, bool ());
    MOCK_METHOD1(fromXChanged, void (float fromX));
    MOCK_METHOD1(toXChanged, void (float toX));
    MOCK_METHOD1(fromYChanged, void (float fromY));
    MOCK_METHOD1(toYChanged, void (float toY));
public:
    typedef ScaleTransition ThisClass;  
    typedef AbstractTransition BaseClass; 
    template <typename BuilderType, typename BuiltType>                                
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {              
    protected:                                                                         
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {  
        }                                                                                
    public:                                                                            
        BuilderType& fromX(float value) {
            this->instance().setFromX(value);
            return  this->builder();
        }
        BuilderType& toX(float value) {
            this->instance().setToX(value);
            return  this->builder();
        }
        BuilderType& fromY(float value) {
            this->instance().setFromY(value);
            return  this->builder();
        }
        BuilderType& toY(float value) {
            this->instance().setToY(value);
            return  this->builder();
        }
        BuilderType& fromScale(float scale) {
            this->instance().setFromX(scale);
            this->instance().setFromY(scale);
            return  this->builder();
        }
        BuilderType& toScale(float scale) {
            this->instance().setToX(scale);
            this->instance().setToY(scale);
            return  this->builder();
        }
    };
    class Builder : public TBuilder<Builder, ScaleTransition> {
    public:
        Builder() : TBuilder<Builder, ScaleTransition>(new ScaleTransition()) {}
    };
  static Builder create(VisualNode *target = 0) {
        return Builder().target(target);
    }
};
}
}
#endif 
