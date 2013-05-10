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
#ifndef cascades_focuspolicy_h
#define cascades_focuspolicy_h
#include "gmock/gmock.h"
#include <QObject>
namespace bb {
  namespace cascades {
    class FocusPolicy : public QObject
    {
public:
      enum Type
      {
        Default = 0x0,
        None = 0x1,
        Touch = 0x2,
        Key = 0x4,
        KeyAndTouch = Touch | Key
      };
    };
  }
}
#endif 
