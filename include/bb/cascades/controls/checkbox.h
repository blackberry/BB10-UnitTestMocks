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
#ifndef cascades_checkbox_h
#define cascades_checkbox_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/abstracttogglebutton.h>
namespace bb {
  namespace cascades {
    class CheckBoxPrivate;
    class Container;
    class CheckBox : public AbstractToggleButton
    {
public:
      CheckBox(Container * parent = 0);
      virtual ~CheckBox();
      MOCK_CONST_METHOD0(text, QString ());
      MOCK_METHOD1(setText, void (const QString & text));
      MOCK_METHOD0(resetText, void ());
      MOCK_METHOD1(textChanged, void (QString text));
        typedef CheckBox ThisClass;
        typedef AbstractToggleButton BaseClass;
    public:
      template <typename BuilderType, typename BuiltType>
      class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
      protected:
        TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
      public:
          BuilderType& text(const QString &text) {
              this->instance().setText(text);
              return this->builder();
          }
      };
      class Builder : public TBuilder<Builder, CheckBox>
      {
      public:
        Builder() : TBuilder<Builder, CheckBox>(new CheckBox()) {}
      };
    static Builder create()
      {
        return Builder();
      }
    static Builder create(const QString & text) {
          return Builder().text(text);
      }
    };
  }
}
#endif
