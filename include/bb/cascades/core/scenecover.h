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
#ifndef cascades_scenecover_h
#define cascades_scenecover_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobject.h>
#include <bb/cascades/core/abstractcover.h>
namespace bb {
    namespace cascades {
    class Control;
    class SceneCoverPrivate;
    class SceneCover : public AbstractCover {
public:
        SceneCover(QObject* parent = 0);
        virtual ~SceneCover();
        MOCK_CONST_METHOD0(content, bb::cascades::Control* ());
        MOCK_METHOD1(setContent, void (bb::cascades::Control* content));
        MOCK_METHOD1(contentChanged, void (bb::cascades::Control* content));
public:
        typedef SceneCover ThisClass;  
        typedef AbstractCover BaseClass; 
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
            protected:
              TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
              }
            public:
              BuilderType& content(bb::cascades::Control* content) {
                this->instance().setContent(content);
                return this->builder();
              }
            };
            class Builder : public TBuilder<Builder, SceneCover>
            {
            public:
              Builder() : TBuilder<Builder, SceneCover>(new SceneCover()) {
              }
            };
          static Builder create() {
              return Builder();
            }
        };
    }
}
#endif 
