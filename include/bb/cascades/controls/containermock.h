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
/*
 * containermock.h
 *
 *  Created on: Oct 4, 2012
 *      Author: bizhou
 */

#ifndef CONTAINERMOCK_H_
#define CONTAINERMOCK_H_

#include "gmock/gmock.h"
#include <QVariant>
#include <QtDeclarative/QtDeclarative>
#include <QtDeclarative/QDeclarativeListProperty>
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/Paint>
#include <bb/cascades/layouts/layout.h>
#include <bb/cascades/controls/container.h>

namespace bb {
    namespace cascades {
    class ContainerPrivate;
    class Layout;
    class ContainerMock : public ControlMock
    {
public:
        ContainerMock() { };
        virtual ~ContainerMock() { }
        MOCK_METHOD1(add, void (bb::cascades::Control *control));
        MOCK_METHOD2(insert, void (int index, bb::cascades::Control *control));
        MOCK_METHOD1(remove, bool (bb::cascades::Control *control));
        MOCK_METHOD0(removeAll, void ());
        MOCK_METHOD2(replace, bb::cascades::Control* (int index, bb::cascades::Control *newControl));
        MOCK_METHOD2(swap, void (int indexA, int indexB));
        MOCK_CONST_METHOD1(at, bb::cascades::Control* (int index));
        MOCK_CONST_METHOD1(indexOf, int (bb::cascades::Control *control));
        MOCK_CONST_METHOD0(count, int ());
        MOCK_CONST_METHOD0(layout, bb::cascades::Layout* ());
        MOCK_METHOD1(setLayout, void (bb::cascades::Layout *layout));
        MOCK_METHOD0(resetLayout, void ());
        MOCK_METHOD1(setBackground, void (const bb::cascades::Paint& paint));
        MOCK_CONST_METHOD0(background, QVariant ());
        MOCK_METHOD0(resetBackground, void ());
        MOCK_METHOD1(setClipContentToBounds, void (bool clip));
        MOCK_CONST_METHOD0(clipContentToBounds, bool ());
        MOCK_METHOD0(resetClipContentToBounds, void ());
        MOCK_METHOD1(controlAdded, void (bb::cascades::Control *control));
        MOCK_METHOD2(controlReplaced, void (bb::cascades::Control *oldControl, bb::cascades::Control *newControl));
        MOCK_METHOD1(controlRemoved, void (bb::cascades::Control *control));
        MOCK_METHOD2(controlMoved, void (bb::cascades::Control *control, int newIndex));
        MOCK_METHOD1(layoutChanged, void (bb::cascades::Layout *layout));
        MOCK_METHOD1(backgroundChanged, void (const bb::cascades::Paint& background));
        MOCK_METHOD1(backgroundChanged, void (QVariant background));
        MOCK_METHOD1(clipContentToBoundsChanged, void (bool clipContentToBounds));
public:
    };
}
}




#endif /* CONTAINERMOCK_H_ */
