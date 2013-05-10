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
#ifndef cascades_qmldocument_h
#define cascades_qmldocument_h
#include <gmock/gmock.h>
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtDeclarative/QDeclarativeError>
#include <QtDeclarative/QDeclarativeContext>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/BaseObject>
#include <bb/testing/proxybase.h>

class QDeclarativeContext;
class QUrl;
class QDeclarativeEngine;
class QDeclarativeComponent;

namespace bb {
    namespace cascades {
        class QmlDocumentPrivate;
        class Control;

        class QmlDocumentMock {
            public:
                MOCK_METHOD1(ctor, void(const QUrl &source));
                MOCK_METHOD1(createRootObject, QObject*(QDeclarativeContext *context));
                MOCK_METHOD0(load, bool ());
                MOCK_METHOD2(setContextProperty, void (const QString &propertyName, QObject *object));
                MOCK_METHOD0(documentContext, QDeclarativeContext * ());
                MOCK_METHOD0(hasErrors, bool ());
                MOCK_METHOD0(errors, QList<QDeclarativeError> ());
                MOCK_CONST_METHOD0(source, QUrl ());
                MOCK_METHOD0(defaultDeclarativeEngine, QDeclarativeEngine * ());
        };

        class QmlDocument : public QObject , public bb::testing::ProxyBase<QmlDocumentMock>{
            Q_OBJECT

        public:
            QmlDocument(const QUrl &source) {mock()->ctor(source);};
            virtual ~QmlDocument() {};

            template <class T> T* createRootObject(QDeclarativeContext *context = 0) {return qobject_cast<T*>(mock()->createRootObject(context));}
            bool load() {return mock()->load();};
            void setContextProperty(const QString &propertyName, QObject *object) {mock()->setContextProperty(propertyName, object);};
            QDeclarativeContext * documentContext() {return mock()->documentContext();};
            bool hasErrors() {return mock()->hasErrors();};
            QList<QDeclarativeError> errors() {return mock()->errors();};
            QUrl source() const {return mock()->source();};
            QDeclarativeEngine * defaultDeclarativeEngine() {return mock()->defaultDeclarativeEngine();};

        public:
            class Builder {
                private:
                    QmlDocument& m_instance;
                    const bool m_autoLoad;
                protected:
                    QmlDocument& instance() {
                        return m_instance;
                    }
                public:
                    Builder(const QUrl &source, bool autoLoad = true)
                        : m_instance(*new QmlDocument(source)), m_autoLoad(autoLoad) {}
                    operator QmlDocument*() {
                        if (m_autoLoad) {
                            m_instance.load();
                        }
                        return &m_instance;
                    }
                    Builder& property(const QString &propertyName, QObject *object) {
                        m_instance.setContextProperty(propertyName, object);
                        return *this;
                    }
                    Builder& parent(QObject *newParent) {
                        m_instance.setParent(newParent);
                        return *this;
                    }
                    Builder& objectName(const QString &name) {
                        m_instance.setObjectName(name);
                        return *this;
                    }
            };
            static Builder create(const QString &qmlAsset, bool autoLoad = true) {
                return create(QUrl(qmlAsset),autoLoad);
            }
            static Builder create(const QUrl &source, bool autoLoad = true) {
                return Builder(source,autoLoad);
            }
        };
    }
}
#endif
