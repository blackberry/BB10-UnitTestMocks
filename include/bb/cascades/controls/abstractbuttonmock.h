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
#ifndef cascades_abstractbuttonmock_h
#define cascades_abstractbuttonmock_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
namespace bb {
    namespace cascades {
    class AbstractButtonPrivate;
    class Container;
    class AbstractButtonMock : public ControlMock {
public:
		virtual ~AbstractButtonMock(){}
        MOCK_METHOD0(clicked, void ());
    };
}
}
#endif
