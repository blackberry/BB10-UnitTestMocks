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

#ifndef BB_CASCADES_CONTROLS_LABEL_H
#define BB_CASCADES_CONTROLS_LABEL_H

#include <QtCore/QString>

#include <bb/cascades/controls/abstracttextcontrol.h>
#include "gmock/gmock.h"
#include <bb/cascades/controls/container.h>
#include <bb/cascades/controls/labelmock.h>

namespace bb {
namespace cascades {

    class Label : public bb::cascades::AbstractTextControl
    {
    public:
        // CTORs/DTORs
        Label(bb::cascades::Container * parent = 0): AbstractTextControl(parent) { };
        virtual ~Label() { };

        //label.h
        bool isMultiline() { return mock<LabelMock>()->isMultiline(); }
        void setMultiline(bool multiline) { mock<LabelMock>()->setMultiline( multiline); }
        void resetMultiline() { mock<LabelMock>()->resetMultiline(); }
        void multilineChanged(bool multiline) { mock<LabelMock>()->multilineChanged( multiline); }

        typedef Label ThisClass;
        typedef bb::cascades::AbstractTextControl BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        public:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            };
        };
        class Builder : public TBuilder<Builder, Label>
        {
        public:
            explicit Builder(Container * parent = 0) : TBuilder<Builder, Label>(new Label(parent))
            {
            };
        };
        static Builder create()
        {
            qDebug() << "Got to here in default creator";
            return Builder();
        };
        static Builder create(const QString & text)
        {
            qDebug() << "Got to here in text creator";
            return Builder().text(text);
        };
    };
}
}

#endif  // BB_CASCADES_CONTROLS_LABEL_H
