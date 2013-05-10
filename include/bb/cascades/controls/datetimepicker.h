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
#ifndef cascades_datetimepicker_h
#define cascades_datetimepicker_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/controls/datetimepickermode.h>
namespace bb {
    namespace cascades {
    class DateTimePickerPrivate;
    class Container;
    class DateTimePicker : public Control
    {
public:
        DateTimePicker(Container* parent = 0, bb::cascades::DateTimePickerMode::Type mode = bb::cascades::DateTimePickerMode::Date);
        virtual ~DateTimePicker();
        MOCK_CONST_METHOD0(isExpanded, bool ());
        MOCK_METHOD1(dateFromTime, QDateTime (const QTime& time));
        MOCK_METHOD1(setTitle, void (const QString& title));
        MOCK_CONST_METHOD0(title, QString ());
        MOCK_METHOD0(resetTitle, void ());
        MOCK_METHOD1(setMode, void (bb::cascades::DateTimePickerMode::Type mode));
        MOCK_CONST_METHOD0(mode, bb::cascades::DateTimePickerMode::Type ());
        MOCK_METHOD0(resetMode, void ());
        MOCK_METHOD1(setValue, void (const QDateTime& value));
        MOCK_CONST_METHOD0(value, QDateTime ());
        MOCK_METHOD0(resetValue, void ());
        MOCK_METHOD1(setMinimum, void (const QDateTime& value));
        MOCK_CONST_METHOD0(minimum, QDateTime ());
        MOCK_METHOD0(resetMinimum, void ());
        MOCK_METHOD1(setMaximum, void (const QDateTime& value));
        MOCK_CONST_METHOD0(maximum, QDateTime ());
        MOCK_METHOD0(resetMaximum, void ());
        MOCK_METHOD1(setMinuteInterval, void (int minuteInterval));
        MOCK_CONST_METHOD0(minuteInterval, int ());
        MOCK_METHOD0(resetMinuteInterval, void ());
        MOCK_METHOD1(setExpanded, void (bool expanded));
        MOCK_METHOD0(resetExpanded, void ());
        MOCK_METHOD1(titleChanged, void (QString title));
        MOCK_METHOD1(modeChanged, void (bb::cascades::DateTimePickerMode::Type newMode));
        MOCK_METHOD1(valueChanged, void (QDateTime value));
        MOCK_METHOD1(minimumChanged, void (QDateTime value));
        MOCK_METHOD1(maximumChanged, void (QDateTime value));
        MOCK_METHOD1(minuteIntervalChanged, void (int minuteInterval));
        MOCK_METHOD1(expandedChanged, void (bool expanded));
        typedef DateTimePicker ThisClass;
        typedef Control BaseClass;
    public:
          template <typename BuilderType, typename BuiltType>
          class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
          {
          protected:
              TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
          public:
              BuilderType& title(const QString& title)
              {
                  this->instance().setTitle(title);
                  return this->builder();
              }
              BuilderType& mode(bb::cascades::DateTimePickerMode::Type mode)
              {
                  this->instance().setMode(mode);
                  return this->builder();
              }
              BuilderType& value(const QDateTime& value)
              {
                  this->instance().setValue(value);
                  return this->builder();
              }
              BuilderType& minimum(const QDateTime& value)
              {
                  this->instance().setMinimum(value);
                  return this->builder();
              }
              BuilderType& maximum(const QDateTime& value)
              {
                  this->instance().setMaximum(value);
                  return this->builder();
              }
              BuilderType&  minuteInterval(int minuteInterval)
              {
                  this->instance().setMinuteInterval(minuteInterval);
                  return this->builder();
              }
              BuilderType& expanded(bool expanded)
              {
                  this->instance().setExpanded(expanded);
                  return this->builder();
              }
          };
          class Builder : public TBuilder<Builder, DateTimePicker>
          {
          public:
              Builder() : TBuilder<Builder, DateTimePicker>(new DateTimePicker()) {}
          };
        static Builder create()
          {
              return Builder();
          }
    };
}
}
#endif
