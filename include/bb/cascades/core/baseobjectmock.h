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
#ifndef BB_CASCADES_BASEOBJECTMOCK_H
#define BB_CASCADES_BASEOBJECTMOCK_H
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
#include <QtDeclarative/QDeclarativeParserStatus>
#include <QString>
#include <QScopedPointer>
#include <QDebug>
namespace bb {
namespace cascades {
class BaseObjectPrivate;
class BaseObjectMock : public QObject, public QDeclarativeParserStatus {
public:
	BaseObjectMock() {}
	virtual ~BaseObjectMock(){}
    MOCK_METHOD1(setObjectName, void (const QString &name));
    MOCK_CONST_METHOD0(toDebugString, QString ());
    MOCK_METHOD0(classBegin, void ());
    MOCK_METHOD0(componentComplete, void ());
    MOCK_METHOD0(creationCompleted, void ());
    MOCK_METHOD1(objectNameChanged, void (const QString &objectName));
public:
    template <typename BuilderType, typename BuiltType>
    class TBuilder {
        BuiltType& m_instance;
    public:
        operator BuiltType*() {
            m_instance.componentComplete();
            return &m_instance;
        }
        BuilderType& parent(QObject *newParent) {
            this->instance().setParent(newParent);
            return this->builder();
        }
        BuilderType& objectName(const QString &name) {
            this->instance().setObjectName(name);
            return this->builder();
        }
        BuilderType& connect(const char *signal, const QObject* receiver, const char *method) {
            bool res = QObject::connect(&this->instance(), signal, receiver, method);
            return this->builder();
        }
    protected:
        TBuilder(BuiltType* _instance) : m_instance(*_instance) {
            m_instance.classBegin();
        }
        BuiltType& instance() {
            return m_instance;
        }
        BuilderType& builder() {
            return  *static_cast<BuilderType*>(this);
        }
    };
};
}
}
#endif	
