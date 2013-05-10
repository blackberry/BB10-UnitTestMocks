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
#ifndef cascades_labelmock_h
#define cascades_labelmock_h
#include "gmock/gmock.h"
#include <QtCore/QString>
#include <bb/cascades/bbcascades_global.h>
#include "bb/cascades/controls/abstracttextcontrolmock.h"

namespace bb {
    namespace cascades {
    class LabelPrivate;
    class Container;
    class LabelMock : public AbstractTextControlMock
    {
public:
        LabelMock(Container * parent = 0){}
        virtual ~LabelMock(){}
        MOCK_CONST_METHOD0(isMultiline, bool ());        
        MOCK_METHOD1(setMultiline, void (bool multiline));
        MOCK_METHOD0(resetMultiline, void ());
        MOCK_METHOD1(multilineChanged, void (bool multiline));
        typedef LabelMock ThisClass;
        typedef AbstractTextControlMock BaseClass;
   public:
        template <typename BuilderType, typename BuiltType>                                
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> 
        {
        protected:                                                                         
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) 
            {  
            }             
        public:
          BuilderType& multiline(bool multiline)
          {
              this->instance().setMultiline(multiline);
              return this->builder();
          }
        };
        class Builder : public TBuilder<Builder, LabelMock>
        {
        public:
            Builder(Container * parent = 0) : TBuilder<Builder, LabelMock>(new LabelMock(parent))
            {
            }
        };
        static Builder create()
        {
            return Builder();
        }
        static Builder create(const QString & text)
        {
            return Builder().text(text);
        }
   };
}
}
#endif	
