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
#ifndef cascades_abstractshortcut_h
#define cascades_abstractshortcut_h

// begin mock includes
#include <gmock/gmock.h>
#include <QSharedPointer>
// end mock includes

#include <bb/cascades/UIObject>
namespace bb {
    namespace cascades {
        class AbstractShortcutPrivate;

        class AbstractShortcutMock : public UIObjectMock {
        public:
            MOCK_METHOD1(setEnabled,  void(bool enabled));
            MOCK_METHOD0(resetEnabled,  void());
            MOCK_CONST_METHOD0(isEnabled, bool());
            MOCK_METHOD2(ctor, void(AbstractShortcutPrivate& _d_ptr, UIObject* parent));
        };

        class AbstractShortcut : public UIObject {
            Q_OBJECT
            Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled RESET resetEnabled NOTIFY enabledChanged FINAL)
        public:
            virtual ~AbstractShortcut() {};
            Q_SLOT void setEnabled(bool enabled) { mock<AbstractShortcutMock>()->setEnabled(enabled); };
            Q_SLOT void resetEnabled() { mock<AbstractShortcutMock>()->resetEnabled(); };
            bool isEnabled() const { return mock<AbstractShortcutMock>()->isEnabled(); };
        Q_SIGNALS:
            void enabledChanged(bool enabled);
            void triggered();
        protected:
            AbstractShortcut(AbstractShortcutPrivate &_d_ptr, UIObject *parent = 0) : UIObject(parent) {
                mock<AbstractShortcutMock>()->ctor(_d_ptr, parent);
            };
        private:
            Q_DECLARE_PRIVATE(AbstractShortcut)
            Q_DISABLE_COPY(AbstractShortcut)
        public:
            typedef AbstractShortcut ThisClass;
            typedef BaseObject BaseClass;
            template <typename BuilderType, typename BuiltType>
            class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
            {
            protected:
                TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
                {
                }
            public:
                BuilderType& enable(bool enabled)
                {
                    this->instance().setEnabled(enabled);
                    return this->builder();
                }
                BuilderType& onTriggered(const QObject* receiver, const char *method) {
                    this->connect(SIGNAL(triggered()), receiver, method);
                    return this->builder();
                }
            };
        };
    }
}
QML_DECLARE_TYPE(bb::cascades::AbstractShortcut)
#endif
