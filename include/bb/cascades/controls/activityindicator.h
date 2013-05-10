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
#ifndef cascades_activityindicator_h
#define cascades_activityindicator_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
namespace bb {
    namespace cascades {
    class ActivityIndicatorPrivate;
    class Container;
    class ActivityIndicator : public Control
    {
public:
        ActivityIndicator(Container * parent = 0) { }
        virtual ~ActivityIndicator() { }
        MOCK_METHOD0(start, void ());
        MOCK_METHOD0(stop, void ());
        MOCK_CONST_METHOD0(isRunning, bool ());
        MOCK_METHOD1(setRunning, void (bool running));
        MOCK_METHOD0(resetRunning, void ());
        MOCK_METHOD0(started, void ());
        MOCK_METHOD0(stopped, void ());
        MOCK_METHOD0(stopping, void ());
        MOCK_METHOD1(runningChanged, void (bool running));
        typedef ActivityIndicator ThisClass;
        typedef Control BaseClass;
    public:
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        };
        class Builder : public TBuilder<Builder, ActivityIndicator>
        {
        public:
            Builder() : TBuilder<Builder, ActivityIndicator>(new ActivityIndicator())
            {
            }
        };
      static Builder create()
        {
            return Builder();
        }
    };
}
}
#endif
