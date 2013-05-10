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
#ifndef cascades_gridlistlayout_h
#define cascades_gridlistlayout_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/layouts/listlayout.h>
#include <bb/cascades/layouts/layoutorientation.h>
#include <bb/cascades/layouts/listheadermode.h>
namespace bb {
    namespace cascades {
    class GridListLayoutPrivate;
    class GridListLayout : public ListLayout {
public:
        GridListLayout();
        virtual ~GridListLayout();
        MOCK_CONST_METHOD0(orientation, bb::cascades::LayoutOrientation::Type ());
        MOCK_METHOD1(setOrientation, void (bb::cascades::LayoutOrientation::Type orientation));
        MOCK_METHOD0(resetOrientation, void ());
        MOCK_CONST_METHOD0(columnCount, int ());
        MOCK_METHOD1(setColumnCount, void (int columnCount));
        MOCK_METHOD0(resetColumnCount, void ());
        MOCK_CONST_METHOD0(cellAspectRatio, float ());
        MOCK_METHOD1(setCellAspectRatio, void (float ratio));
        MOCK_METHOD0(resetCellAspectRatio, void ());
        MOCK_CONST_METHOD0(horizontalCellSpacing, float ());
        MOCK_METHOD1(setHorizontalCellSpacing, void (float spacing));
        MOCK_METHOD0(resetHorizontalCellSpacing, void ());
        MOCK_CONST_METHOD0(verticalCellSpacing, float ());
        MOCK_METHOD1(setVerticalCellSpacing, void (float spacing));
        MOCK_METHOD0(resetVerticalCellSpacing, void ());
        MOCK_CONST_METHOD0(spacingBeforeHeader, float ());
        MOCK_METHOD1(setSpacingBeforeHeader, void (float spacing));
        MOCK_METHOD0(resetSpacingBeforeHeader, void ());
        MOCK_CONST_METHOD0(spacingAfterHeader, float ());
        MOCK_METHOD1(setSpacingAfterHeader, void (float spacing));
        MOCK_METHOD0(resetSpacingAfterHeader, void ());
        MOCK_CONST_METHOD0(headerMode, bb::cascades::ListHeaderMode::Type ());
        MOCK_METHOD1(setHeaderMode, void (bb::cascades::ListHeaderMode::Type newHeaderMode));
        MOCK_METHOD0(resetHeaderMode, void ());
        MOCK_METHOD1(orientationChanged, void (bb::cascades::LayoutOrientation::Type newOrientation));
        MOCK_METHOD1(columnCountChanged, void (int columnCount));
        MOCK_METHOD1(cellAspectRatioChanged, void (float cellAspectRatio));
        MOCK_METHOD1(horizontalCellSpacingChanged, void (float horizontalCellSpacing));
        MOCK_METHOD1(verticalCellSpacingChanged, void (float verticalCellSpacing));
        MOCK_METHOD1(spacingBeforeHeaderChanged, void (float spacingBeforeHeader));
        MOCK_METHOD1(spacingAfterHeaderChanged, void (float spacingAfterHeader));
        MOCK_METHOD1(headerModeChanged, void (bb::cascades::ListHeaderMode::Type newHeaderMode));
public:
        typedef GridListLayout ThisClass;
        typedef ListLayout BaseClass;
        template <typename BuilderType, typename BuiltType>
        class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
        protected:
            TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
            }
        public:
            BuilderType& orientation(bb::cascades::LayoutOrientation::Type orientation) {
                this->instance().setOrientation(orientation);
                return this->builder();
            }
            BuilderType& columnCount(int columnCount) {
                this->instance().setColumnCount(columnCount);
                return this->builder();
            }
            BuilderType& cellAspectRatio(float ratio) {
                this->instance().setCellAspectRatio(ratio);
                return this->builder();
            }
            BuilderType& headerMode(bb::cascades::ListHeaderMode::Type newHeaderMode) {
                this->instance().setHeaderMode(newHeaderMode);
                return this->builder();
            }
        };
        class Builder : public TBuilder<Builder, GridListLayout>
        {
        public:
            Builder() : TBuilder<Builder, GridListLayout>(new GridListLayout()) {
            }
        };
      static Builder create() {
            return Builder();
        }
    }; 
} 
}
#endif	
