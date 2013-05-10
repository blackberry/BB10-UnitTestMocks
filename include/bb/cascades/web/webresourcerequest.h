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
#ifndef cascades_webresourcerequest_h
#define cascades_webresourcerequest_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QByteArray>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QUrl>
namespace bb {
  namespace cascades {
    class WebPagePrivate;
    class WebResourceRequestPrivate;
    class WebResourceRequest : public QObject
    {
public:
        WebResourceRequest(WebResourceRequestPrivate* dd_ptr, QObject* parent = 0);
        virtual ~WebResourceRequest();
        MOCK_CONST_METHOD0(url, QUrl ());
        MOCK_CONST_METHOD0(referrer, QUrl ());
        MOCK_CONST_METHOD0(body, QByteArray ());
public:
        MOCK_METHOD2(notifyOpen, void (int statusCode, const QString& message));
        MOCK_METHOD2(notifyHeaderReceived, void (const QString& key, const QString& value));
        MOCK_METHOD1(notifyDataReceived, void (const QByteArray& data));
        MOCK_METHOD0(notifyDone, void ());
    };
  } 
} 
#endif 
