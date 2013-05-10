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
#ifndef cascades_stacklayoutproperties_h
#define cascades_stacklayoutproperties_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/layoutproperties.h>
namespace bb {
    namespace cascades {
    class StackLayoutPropertiesPrivate;
    class Control;
    class StackLayoutProperties : public LayoutProperties {
public:
        StackLayoutProperties() {}
        virtual ~StackLayoutProperties() {}
        MOCK_CONST_METHOD0(spaceQuota, float ());
        MOCK_METHOD1(setSpaceQuota, void (float spaceQuota));
        MOCK_METHOD0(resetSpaceQuota, void ());
        MOCK_METHOD1(spaceQuotaChanged, void (float spaceQuota));
public:
        typedef StackLayoutProperties ThisClass;
        typedef LayoutProperties BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& spaceQuota(float _spaceQuota) {
                this->instance().setSpaceQuota(_spaceQuota);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, StackLayoutProperties> {
        public:
            Builder(QObject *parent, StackLayoutProperties *pInstance = new StackLayoutProperties()) : TBuilder<Builder, StackLayoutProperties>(pInstance) {
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
