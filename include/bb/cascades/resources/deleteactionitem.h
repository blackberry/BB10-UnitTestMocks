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
#ifndef cascades_deleteactionitem_h
#define cascades_deleteactionitem_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/abstractactionitem.h>
namespace bb {
    namespace cascades {
        class DeleteActionItemPrivate;
        class DeleteActionItem : public AbstractActionItem
        {        
public:
            DeleteActionItem();
            virtual ~DeleteActionItem();
            typedef DeleteActionItem ThisClass;
            typedef AbstractActionItem BaseClass;
        public:
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
            {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
            public:
            };
            class Builder : public TBuilder<Builder, DeleteActionItem>
            {
            public:
                Builder() : TBuilder<Builder, DeleteActionItem>(new DeleteActionItem()) {}
            };
          static Builder create() {
                return Builder();
            } 
        };
    } 
}
#endif  
