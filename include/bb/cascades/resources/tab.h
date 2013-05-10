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
#ifndef cascades_tab_h
#define cascades_tab_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/resources/abstractactionitem.h>
#include <bb/cascades/resources/image.h>
namespace bb {
    namespace cascades {
      class TabPrivate;
      class AbstractPane;
      class TabbedPane;
      class Tab : public AbstractActionItem
      {
public:
          Tab(TabbedPane * parent = 0);
          virtual ~Tab();
          MOCK_METHOD1(setDescription, void (const QString& description));
          MOCK_METHOD0(resetDescription, void ());
          MOCK_CONST_METHOD0(description, QString ());
          MOCK_CONST_METHOD0(content, bb::cascades::AbstractPane* ());
          MOCK_METHOD1(setContent, void (bb::cascades::AbstractPane* content));
          MOCK_METHOD0(resetContent, void ());
          MOCK_METHOD1(setNewContentAvailable, void (bool isNewContentAvailable));
          MOCK_METHOD0(resetNewContentAvailable, void ());
          MOCK_CONST_METHOD0(isNewContentAvailable, bool ());
          MOCK_METHOD1(setUnreadContentCount, void (int unreadContentCount));
          MOCK_METHOD0(resetUnreadContentCount, void ());
          MOCK_CONST_METHOD0(unreadContentCount, int ());
          MOCK_METHOD1(descriptionChanged, void (QString description));
          MOCK_METHOD1(contentChanged, void (bb::cascades::AbstractPane* content));
          MOCK_METHOD1(newContentAvailableChanged, void (bool isNewContentAvailable));
          MOCK_METHOD1(unreadContentCountChanged, void (int unreadContentCount));
public:
          typedef Tab ThisClass;
          typedef AbstractActionItem BaseClass;
          template <typename BuilderType, typename BuiltType>
          class TBuilder : public BaseClass::TBuilder<BuilderType, BuiltType> {
          protected:
              TBuilder(BuiltType* node) : BaseClass::TBuilder<BuilderType, BuiltType>(node) {
              }
          public:
              BuilderType& description(const QString &title) {
                  this->instance().setDescription(title);
                  return this->builder();
              }
              BuilderType& content(AbstractPane *content)
              {
                  this->instance().setContent(content);
                  return this->builder();
              }
              BuilderType& newContent(bool isNewContentAvailable) {
                  this->instance().setNewContentAvailable(isNewContentAvailable);
                  return this->builder();
              }
              BuilderType& unreadContent(int unreadContentCount) {
                this->instance().setUnreadContentCount(unreadContentCount);
                return this->builder();
              }
          };
          class Builder : public TBuilder<Builder, Tab>
          {
          public:
              Builder() : TBuilder<Builder, Tab>(new Tab()) {}
          };
        static Builder create() {
              return Builder();
          }
      };
    }
}
#endif 
