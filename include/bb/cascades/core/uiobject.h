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
#ifndef cascades_uiobject_h
#define cascades_uiobject_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/core/uiobjectmock.h>
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
#include <QtDeclarative/QDeclarativeListProperty>
#include <QtCore/QDebug>
#include <bb/cascades/BaseObject>
namespace bb {
    namespace cascades {
    class Event;
    class UIObjectPrivate;
    class UIObject : public BaseObject {
public:
        virtual ~UIObject(){}
        bool event(QEvent *event) { return mock<UIObjectMock>()->event(event); }
protected:
        UIObject(QObject *parent = 0): BaseObject(parent) {}
};
}
}
#endif	
