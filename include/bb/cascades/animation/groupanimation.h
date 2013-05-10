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
#ifndef cascades_groupanimation_h
#define cascades_groupanimation_h
#include "gmock/gmock.h"
#include <QtDeclarative/QtDeclarative>
#include <QtDeclarative/QDeclarativeListProperty> 
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/animation/abstractanimation.h>
namespace bb {
    namespace cascades {
class VisualNode;
class GroupAnimationPrivate;
class GroupAnimation : public AbstractAnimation {
public:
    virtual ~GroupAnimation() { }
public:

    MOCK_METHOD1(add, void(AbstractAnimation *animation));

    typedef GroupAnimation ThisClass;  
    typedef AbstractAnimation BaseClass; 
    template <typename BuilderType, typename BuiltType>                                
    class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {              
    protected:                                                                         
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {  
        }                                                                                
    public:                                                                            
        BuilderType& add(AbstractAnimation *animation) {
            this->instance().add(animation);
            return this->builder();
        }
    };
};
}
}
#endif 
