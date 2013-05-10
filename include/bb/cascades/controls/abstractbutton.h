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
#ifndef cascades_abstractbutton_h
#define cascades_abstractbutton_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/controls/container.h>
#include <bb/cascades/controls/abstractbuttonmock.h>
namespace bb {
    namespace cascades {
    class AbstractButtonPrivate;
    class AbstractButton : public Control {
public:
    	AbstractButton(bb::cascades::Container * parent = 0): Control(parent) { };

		virtual ~AbstractButton(){}
		void clicked(){mock<AbstractButtonMock>()->clicked();}
public:
        typedef AbstractButton ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        };
    };
    }
}
#endif
