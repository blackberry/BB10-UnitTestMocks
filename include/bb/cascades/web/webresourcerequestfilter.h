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
#ifndef cascades_webresourcerequestfilter_h
#define cascades_webresourcerequestfilter_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QString>
#include <QUrl>
namespace bb {
  namespace cascades {
    class WebResourceRequest;
    class WebResourceRequestFilter
    {
public:
        virtual ~WebResourceRequestFilter();
        enum FilterAction {
            Accept,       
            Deny,         
            Substitute,   
            Filter,       
        };
        enum RequestPurpose {
            Unknown,        
            MainFrame,
            Subframe,
            Subresource,    
            XmlHttpRequest, 
            Worker,         
            SharedWorker,
            FileDownload,   
            StyleSheet,
            Script,
            Font,
            Image,
            Object,
            Media,
        };
        MOCK_METHOD2(filterResourceRequest, FilterAction (WebResourceRequest* request, RequestPurpose purpose));
        MOCK_METHOD3(filterResourceError, bool (int status, const QUrl& url, const QString& message));
        MOCK_METHOD3(filterResourceOpened, bool (WebResourceRequest* request, int& status, QString& message));
        MOCK_METHOD3(filterResourceHeader, bool (WebResourceRequest* request, QString& key, QString& value));
        MOCK_METHOD2(filterResourceData, bool (WebResourceRequest* request, QByteArray& data));
        MOCK_METHOD1(filterResourceDone, bool (WebResourceRequest* request));
    };
  } 
} 
#endif 
