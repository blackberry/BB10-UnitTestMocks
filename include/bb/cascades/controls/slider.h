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
#ifndef cascades_slider_h
#define cascades_slider_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
namespace bb {
    namespace cascades {
    class SliderPrivate;
    class Container;
    class Slider : public Control {
public:
		Slider(Container *parent = 0){}
		virtual ~Slider(){}
        MOCK_CONST_METHOD0(fromValue, float ());
        MOCK_METHOD1(setFromValue, void (float from));
        MOCK_METHOD0(resetFromValue, void ());
        MOCK_CONST_METHOD0(toValue, float ());
        MOCK_METHOD1(setToValue, void (float to));
        MOCK_METHOD0(resetToValue, void ());
        MOCK_METHOD2(setRange, void (float from, float to));
        MOCK_METHOD0(resetRange, void ());
        MOCK_CONST_METHOD0(value, float ());
        MOCK_METHOD1(setValue, void (float value));
        MOCK_METHOD0(resetValue, void ());
        MOCK_CONST_METHOD0(immediateValue, float ());
        MOCK_METHOD1(valueChanged, void (float value));
        MOCK_METHOD1(immediateValueChanged, void (float immediateValue));
        MOCK_METHOD1(toValueChanged, void (float toValue));
        MOCK_METHOD1(fromValueChanged, void (float fromValue));
public:
        typedef Slider ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& value(float value)
            {
                this->instance().setValue(value);
                return this->builder();
            }
            BuilderType& to(float to)
            {
                this->instance().setToValue(to);
                return this->builder();
            }
            BuilderType& from(float from)
            {
                this->instance().setFromValue(from);
                return this->builder();
            }
            BuilderType& onValueChanged(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(valueChanged(float)), receiver, method);
                return this->builder();
            }
            BuilderType& onImmediateValueChanged(const QObject* receiver, const char *method) {
                this->connect(SIGNAL(immediateValueChanged(float)), receiver, method);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Slider>
        {
        public:
            Builder() : TBuilder<Builder, Slider>(new Slider())
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
