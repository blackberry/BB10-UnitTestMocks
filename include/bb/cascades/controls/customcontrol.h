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
#ifndef cascades_customcontrol_h
#define cascades_customcontrol_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/customcontrolmock.h>
#include <bb/cascades/controls/container.h>
#include <bb/cascades/controls/control.h>
namespace bb {
    namespace cascades {
    class VisualNode;
    class CustomControl : public Control
    {
public:
      virtual ~CustomControl() {}

protected:
      bb::cascades::VisualNode* root() const { return mock<CustomControlMock>()->root(); }
	  void setRoot(bb::cascades::VisualNode *root)  { mock<CustomControlMock>()->setRoot(root); }

      CustomControl(Container *parent = 0): Control(parent) {}
    };
} 
}
#endif 
