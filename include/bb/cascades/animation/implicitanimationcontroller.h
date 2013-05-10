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
#ifndef cascades_implicitanimationcontroller_h
#define cascades_implicitanimationcontroller_h
#include "gmock/gmock.h"
#include <QMetaType>
#include <QExplicitlySharedDataPointer>
#include <bb/cascades/bbcascades_global.h>
namespace bb {
    namespace cascades {
    class VisualNode;
    //class ImplicitAnimationControllerPrivate;
    class ImplicitAnimationController {
public:
        ImplicitAnimationController() {}
        ImplicitAnimationController(const ImplicitAnimationController& aCopy) {}
        ImplicitAnimationController& operator=(const ImplicitAnimationController& other) { return *this; }
        ~ImplicitAnimationController() {}
public:
        class Builder {
        private:
            //QExplicitlySharedDataPointer<ImplicitAnimationControllerPrivate> d;
            friend class ImplicitAnimationController;
            Builder& init(VisualNode *target, const QString &propertyName) { return *this; }
        public:
            Builder() {}
            ~Builder() {}
            Builder& operator=(const Builder& other);
            Builder(const Builder& aCopy) {}
            operator ImplicitAnimationController() { ImplicitAnimationController c; return c; }
            Builder& enabled(bool enabled) { return *this; }
        };
      static Builder create(VisualNode *target, const QString &propertyName = QString::null) {
            Builder b;
            return b.init(target, propertyName);
        }
    };
}
}
#endif	
