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
#ifndef cascades_webnavigationrequest_h
#define cascades_webnavigationrequest_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <bb/cascades/controls/webview.h>
#include <bb/cascades/web/webnavigationrequestaction.h>
#include <bb/cascades/web/webnavigationtype.h>
#include <QtCore/QObject>
#include <QtCore/QUrl>
namespace bb {
  namespace cascades {
    class WebNavigationRequestPrivate;
    class WebNavigationRequest : public QObject 
    {
public:
        WebNavigationRequest(const QUrl& url, bb::cascades::WebNavigationType::Type navigationType, QObject* parent = 0);
        ~WebNavigationRequest();
        MOCK_CONST_METHOD0(url, QUrl ());
        MOCK_CONST_METHOD0(navigationType, bb::cascades::WebNavigationType::Type ());
        MOCK_CONST_METHOD0(action, bb::cascades::WebNavigationRequestAction::Type ());
        MOCK_METHOD1(setAction, void (bb::cascades::WebNavigationRequestAction::Type action));
        MOCK_METHOD0(accept, void ());
        MOCK_METHOD0(ignore, void ());
        MOCK_METHOD1(actionChanged, void (bb::cascades::WebNavigationRequestAction::Type action));
    };
  } 
} 
#endif 
