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
#ifndef cascades_container_h
#define cascades_container_h
#include "gmock/gmock.h"
#include <QVariant>
#include <QtDeclarative/QtDeclarative>
#include <QtDeclarative/QDeclarativeListProperty> 
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/Paint>
#include <bb/cascades/controls/containermock.h>

namespace bb {
    namespace cascades {
    class ContainerPrivate;
    class Layout;
    class Container : public Control
    {
public:
    	Container(bb::cascades::Container * parent = 0): Control(parent) { };

        virtual ~Container() { }
        /* MOCK_METHOD1(add, void (bb::cascades::Control *control)); */
        void add (bb::cascades::Control *control) {
        	mock<ContainerMock>()->add(control);
        }

        /* MOCK_METHOD2(insert, void (int index, bb::cascades::Control *control)); */
        void insert (int index, bb::cascades::Control *control) {
        	mock<ContainerMock>()->insert(index, control);
        }

        /* MOCK_METHOD1(remove, bool (bb::cascades::Control *control)); */
        bool remove (bb::cascades::Control *control) {
        	return mock<ContainerMock>()->remove(control);
        }

        /* MOCK_METHOD0(removeAll, void ()); */
        void removeAll() {
        	mock<ContainerMock>()->removeAll();
        }
        /* MOCK_METHOD2(replace, bb::cascades::Control* (int index, bb::cascades::Control *newControl)); */
        bb::cascades::Control * replace (int index, bb::cascades::Control *control) {
        	return mock<ContainerMock>()->replace(index, control);
        }

        /* MOCK_METHOD2(swap, void (int indexA, int indexB)); */
        void swap(int indexA, int indexB) {
        	mock<ContainerMock>()->swap(indexA, indexB);
        }

        /* MOCK_CONST_METHOD1(at, bb::cascades::Control* (int index)); */
        bb::cascades::Control * at(int index) {
        	return mock<ContainerMock>()->at(index);
        }
        /* MOCK_CONST_METHOD1(indexOf, int (bb::cascades::Control *control)); */
        int indexOf(bb::cascades::Control *control) {
        	return mock<ContainerMock>()->indexOf(control);
        }

        /* MOCK_CONST_METHOD0(count, int ()); */
        int count() {
        	return mock<ContainerMock>()->count();
        }

        /* MOCK_CONST_METHOD0(layout, bb::cascades::Layout* ()); */
        bb::cascades::Layout* layout() {
        	return mock<ContainerMock>()->layout();
        }

        /* MOCK_METHOD1(setLayout, void (bb::cascades::Layout *layout)); */
        void setLayout(bb::cascades::Layout *layout) {
        	mock<ContainerMock>()->setLayout(layout);
        }

        /* MOCK_METHOD0(resetLayout, void ()); */
        void resetlayout() {
        	mock<ContainerMock>()->resetLayout();
        }

        /* MOCK_METHOD1(setBackground, void (const bb::cascades::Paint& paint)); */
        void setBackground (const bb::cascades::Paint& paint) {
        	mock<ContainerMock>()->setBackground(paint);
        }

        /* MOCK_CONST_METHOD0(background, QVariant ()); */
        QVariant background() {
        	return mock<ContainerMock>()->background();
        }

        /* MOCK_METHOD0(resetBackground, void ()); */
        void resetBackground() {
        	mock<ContainerMock>()->resetBackground();
        }

        /* MOCK_METHOD1(setClipContentToBounds, void (bool clip)); */
        void setClipContentToBounds (bool clip) {
        	mock<ContainerMock>()->setClipContentToBounds(clip);
        }

        /* MOCK_CONST_METHOD0(clipContentToBounds, bool ()); */
        bool clipContentToBounds () {
        	return mock<ContainerMock>()->clipContentToBounds();
        }

        /* MOCK_METHOD0(resetClipContentToBounds, void ()); */
        void resetClipContenttoBounds() {
        	mock<ContainerMock>()->resetClipContentToBounds();
        }

        /* MOCK_METHOD1(controlAdded, void (bb::cascades::Control *control)); */
        void controlAdded(bb::cascades::Control *control) {
        	mock<ContainerMock>()->controlAdded(control);
        }

        /* MOCK_METHOD2(controlReplaced, void (bb::cascades::Control *oldControl, bb::cascades::Control *newControl)); */
        void controlReplaced(bb::cascades::Control *oldControl, bb::cascades::Control *newControl) {
        	mock<ContainerMock>()->controlReplaced(oldControl, newControl);
        }

        /* MOCK_METHOD1(controlRemoved, void (bb::cascades::Control *control)); */
        void controlRemoved(bb::cascades::Control *control) {
        	mock<ContainerMock>()->controlRemoved(control);
        }

        /* MOCK_METHOD2(controlMoved, void (bb::cascades::Control *control, int newIndex)); */
        void controlMoved(bb::cascades::Control *control, int newIndex) {
        	mock<ContainerMock>()->controlMoved(control, newIndex);
        }

        /* MOCK_METHOD1(layoutChanged, void (bb::cascades::Layout *layout)); */
        void layoutChanged(bb::cascades::Layout *layout) {
        	mock<ContainerMock>()->layoutChanged(layout);
        }

        /* MOCK_METHOD1(backgroundChanged, void (const bb::cascades::Paint& background)); */
        void backgroundChanged(const bb::cascades::Paint& background) {
        	mock<ContainerMock>()->backgroundChanged(background);
        }

        /* MOCK_METHOD1(backgroundChanged, void (QVariant background)); */
        void backgroundChanged(QVariant background) {
        	mock<ContainerMock>()->backgroundChanged(background);
        }

        /* MOCK_METHOD1(clipContentToBoundsChanged, void (bool clipContentToBounds)); */
        void clipContentToBoundsChanged(bool clipContentToBounds) {
        	mock<ContainerMock>()->clipContentToBoundsChanged(clipContentToBounds);
        }
public:
        typedef Container ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType>
        {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node)
            {
            }
        public:
            BuilderType& add(Control *control)
            {
                this->instance().add(control);
                return this->builder();
            }
            BuilderType& layout(bb::cascades::Layout *layout)
            {
                this->instance().setLayout(layout);
                return this->builder();
            }
            BuilderType& background(const bb::cascades::Paint &paint)
            {
                this->instance().setBackground(paint);
                return this->builder();
            }
            BuilderType& clip(bool clip)
            {
                this->instance().setClipContentToBounds(clip);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, Container>
        {
        public:
            Builder() : TBuilder<Builder, Container>(new Container())
            {
            }
        };
        static Builder create()
        {
            return Builder();
        }
    };
}
}
#endif	
