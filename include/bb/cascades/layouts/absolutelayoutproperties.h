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
#ifndef cascades_absolutelayoutproperties_h
#define cascades_absolutelayoutproperties_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/layoutproperties.h>
namespace bb {
    namespace cascades {
    class AbsoluteLayoutPropertiesPrivate;
    class Control;
    class AbsoluteLayoutProperties : public LayoutProperties {
public:
        AbsoluteLayoutProperties() { }
        virtual ~AbsoluteLayoutProperties() { }
        MOCK_CONST_METHOD0(positionX, float ());
        MOCK_METHOD1(setPositionX, void (float posX));
        MOCK_METHOD0(resetPositionX, void ());
        MOCK_CONST_METHOD0(positionY, float ());
        MOCK_METHOD1(setPositionY, void (float posY));
        MOCK_METHOD0(resetPositionY, void ());
        MOCK_METHOD1(positionXChanged, void (float positionX));
        MOCK_METHOD1(positionYChanged, void (float positionY));
public:
        typedef AbsoluteLayoutProperties ThisClass;
        typedef LayoutProperties BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& x(float posX) {
                this->instance().setPositionX(posX);
                return this->builder();
            }
            BuilderType& y(float posY) {
                this->instance().setPositionY(posY);
                return this->builder();
            }
            BuilderType& position(float posX, float posY) {
              this->instance().setPositionX(posX);
              this->instance().setPositionY(posY);
              return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, AbsoluteLayoutProperties> {
        public:
            Builder(QObject *parent, AbsoluteLayoutProperties *pInstance = new AbsoluteLayoutProperties()) : TBuilder<Builder, AbsoluteLayoutProperties>(pInstance) {
                if (!pInstance->parent())
                {
                    pInstance->setParent(parent);
                }
            }
        };
      static Builder create(QObject *parent = 0) {
            return Builder(parent);
        }
        Builder updateFor(Control *targetControl);
    }; 
} 
} 
#endif	
