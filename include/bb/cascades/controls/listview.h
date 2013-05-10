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
#ifndef cascades_listview_h
#define cascades_listview_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QObject>
#include <bb/cascades/controls/control.h>
#include <bb/cascades/databinding/datamodel.h>
#include <bb/cascades/controls/listitemprovider.h>
#include <bb/cascades/controls/listitemtypemapper.h>
#include <bb/cascades/controls/snapmode.h>
#include <bb/cascades/controls/scrollposition.h>
#include <bb/cascades/controls/scrollindicatormode.h>
#include <bb/cascades/core/visualnode.h>
#include <bb/cascades/layouts/listlayout.h>
#include <bb/cascades/resources/scrollanimation.h>
namespace bb {
    namespace cascades {
    class Container;
    class ListViewPrivate;
    class MultiSelectHandler;
    class MultiSelectActionItem;
    class ListView : public Control {
public:
        const QVariantList AllItems;
        ListView(Container *parent = 0) { }
        ListView(bb::cascades::DataModel *dataModel, Container *parent = 0) { }
        virtual ~ListView() { }
        MOCK_CONST_METHOD0(layout, bb::cascades::ListLayout* ());
        MOCK_METHOD1(setLayout, void (bb::cascades::ListLayout *layout));
        MOCK_METHOD0(resetLayout, void ());
        MOCK_METHOD1(setDataModel, void (bb::cascades::DataModel *pDataModel));
        MOCK_CONST_METHOD0(dataModel, DataModel *());
        MOCK_METHOD0(resetDataModel, void ());
        MOCK_METHOD1(setListItemProvider, void (bb::cascades::ListItemProvider *pItemProvider));
        MOCK_CONST_METHOD0(listItemProvider, ListItemProvider *());
        MOCK_METHOD0(resetListItemProvider, void ());
        MOCK_METHOD1(setListItemTypeMapper, void (ListItemTypeMapper *pItemTypeMapper));
        MOCK_CONST_METHOD0(listItemTypeMapper, ListItemTypeMapper *());
        MOCK_METHOD0(resetListItemTypeMapper, void ());
        MOCK_METHOD1(setRootIndexPath, void (const QVariantList &rootIndexPath));
        MOCK_CONST_METHOD0(rootIndexPath, QVariantList ());
        MOCK_METHOD0(resetRootIndexPath, void ());
        MOCK_METHOD1(setSnapMode, void ( bb::cascades::SnapMode::Type mode ));
        MOCK_CONST_METHOD0(snapMode, bb::cascades::SnapMode::Type ());
        MOCK_METHOD0(resetSnapMode, void ());
        MOCK_CONST_METHOD0(multiSelectHandler, bb::cascades::MultiSelectHandler* ());
        MOCK_CONST_METHOD0(multiSelectAction, bb::cascades::MultiSelectActionItem* ());
        MOCK_METHOD1(setMultiSelectAction, void (bb::cascades::MultiSelectActionItem* multiSelectAction));
        MOCK_METHOD0(resetMultiSelectAction, void ());
        MOCK_METHOD1(setScrollIndicatorMode, void (bb::cascades::ScrollIndicatorMode::Type mode));
        MOCK_CONST_METHOD0(scrollIndicatorMode, bb::cascades::ScrollIndicatorMode::Type ());
        MOCK_METHOD0(resetScrollIndicatorMode, void ());
        MOCK_CONST_METHOD1(isSelected, bool ( const QVariantList &indexPath ));
        MOCK_METHOD2(select, void ( const QVariantList &indexPath, bool select));
        MOCK_METHOD1(select, void ( const QVariantList &indexPath));
        MOCK_METHOD1(toggleSelection, void ( const QVariantList &indexPath ));
        MOCK_METHOD0(clearSelection, void ());
        MOCK_METHOD0(selectAll, void ());
        MOCK_CONST_METHOD0(selected, QVariantList ());
        MOCK_CONST_METHOD0(selectionList, QVariantList ());
        MOCK_METHOD2(scroll, void (float offset, bb::cascades::ScrollAnimation::Type scrollAnimation));
        MOCK_METHOD1(scroll, void (float offset));
        MOCK_METHOD2(scrollToItem, void (const QVariantList &indexPath, bb::cascades::ScrollAnimation::Type scrollAnimation));
        MOCK_METHOD1(scrollToItem, void (const QVariantList &indexPath));
        MOCK_METHOD2(scrollToPosition, void (bb::cascades::ScrollPosition::Type position, bb::cascades::ScrollAnimation::Type scrollAnimation));
        MOCK_METHOD1(scrollToPosition, void (bb::cascades::ScrollPosition::Type position));
        MOCK_METHOD2(scroll, void (float offset, int scrollAnimation ));
        MOCK_METHOD2(scrollToItem, void (const QVariantList &indexPath, int scrollAnimation ));
        MOCK_METHOD2(scrollToPosition, void (int position, int scrollAnimation ));
         MOCK_CONST_METHOD0(leadingVisual, bb::cascades::VisualNode* ());
        MOCK_METHOD0(resetLeadingVisual, void ());
        MOCK_METHOD1(setLeadingVisual, void (bb::cascades::VisualNode* pLeadingVisual));
        MOCK_CONST_METHOD0(scrollStops, QVariantList ());
        MOCK_METHOD1(setScrollStops, void ( const QVariantList& indexPaths ));
        MOCK_METHOD1(layoutChanged, void (bb::cascades::ListLayout *layout));
        MOCK_METHOD1(dataModelChanged, void (bb::cascades::DataModel *dataModel));
        MOCK_METHOD1(listItemProviderChanged, void (bb::cascades::ListItemProvider *listItemProvider));
        MOCK_METHOD1(rootIndexPathChanged, void (QVariantList rootIndexPath));
        MOCK_METHOD1(scrollIndicatorModeChanged, void (bb::cascades::ScrollIndicatorMode::Type newScrollIndicatorMode));
        MOCK_METHOD1(snapModeChanged, void (bb::cascades::SnapMode::Type newSnapMode));
        MOCK_METHOD1(multiSelectActionChanged, void (bb::cascades::MultiSelectActionItem *multiSelectAction));
        MOCK_METHOD2(activationChanged, void (QVariantList indexPath, bool active));
        MOCK_METHOD2(selectionChanged, void (QVariantList indexPath, bool selected));
        MOCK_METHOD1(triggered, void (QVariantList indexPath));
        MOCK_METHOD1(leadingVisualChanged, void (bb::cascades::VisualNode* pLeadingVisual));
public:
        typedef ListView ThisClass;
        typedef Control BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {}
        public:
            BuilderType& layout(bb::cascades::ListLayout *_layout)
            {
                this->instance().setLayout(_layout);
                return this->builder();
            }
            BuilderType& dataModel(DataModel *pDataModel) {
                this->instance().setDataModel(pDataModel);
                return this->builder();
            }
            BuilderType& listItemProvider(ListItemProvider *pItemProvider) {
                this->instance().setListItemProvider(pItemProvider);
                return this->builder();
            }
            BuilderType& rootIndexPath(const QVariantList &rootIndexPath) {
                this->instance().setRootIndexPath(rootIndexPath);
                return this->builder();
            }
            BuilderType& scrollIndicatorMode(bb::cascades::ScrollIndicatorMode::Type eMode) {
                this->instance().setScrollIndicatorMode(eMode);
                return this->builder();
            }
            BuilderType& snapMode(bb::cascades::SnapMode::Type eMode) {
                this->instance().setSnapMode(eMode);
                return this->builder();
            }
            BuilderType& leadingVisual(VisualNode *pLeadingVisual) {
                this->instance().setLeadingVisual(pLeadingVisual);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, ListView> {
        public:
            Builder() : TBuilder<Builder, ListView>(new ListView()) {}
        };
        static Builder create() {
            return Builder();
        }
    };
}
}
#endif 
