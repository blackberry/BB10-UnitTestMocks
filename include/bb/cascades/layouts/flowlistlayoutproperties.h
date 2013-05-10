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
#ifndef cascades_flowlayoutproperties_h
#define cascades_flowlayoutproperties_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/layoutproperties.h>
namespace bb {
    namespace cascades {
    class FlowListLayoutPropertiesPrivate;
    class Control;
    class FlowListLayoutProperties : public LayoutProperties {
public:
		FlowListLayoutProperties(){}
		virtual ~FlowListLayoutProperties(){}
        MOCK_CONST_METHOD0(aspectRatio, float ());
        MOCK_METHOD1(setAspectRatio, void (float aspectRatio));
        MOCK_METHOD0(resetAspectRatio, void ());
        MOCK_CONST_METHOD0(fillRatio, float ());
        MOCK_METHOD1(setFillRatio, void (float fillRatio));
        MOCK_METHOD0(resetFillRatio, void ());
        MOCK_METHOD1(aspectRatioChanged, void (float aspectRatio));
        MOCK_METHOD1(fillRatioChanged, void (float fillRatio));
public:
        typedef FlowListLayoutProperties ThisClass;
        typedef LayoutProperties BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& aspectRatio(float _aspectRatio) {
                this->instance().setAspectRatio(_aspectRatio);
                return this->builder();
            }
            BuilderType& fillRatio(float _fillRatio) {
                this->instance().setFillRatio(_fillRatio);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, FlowListLayoutProperties> {
        public:
            Builder(QObject *parent, FlowListLayoutProperties *pInstance = new FlowListLayoutProperties()) : TBuilder<Builder, FlowListLayoutProperties>(pInstance) {
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
