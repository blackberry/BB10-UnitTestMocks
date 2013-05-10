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
#ifndef cascades_webstorage_h
#define cascades_webstorage_h
#include "gmock/gmock.h"
#include <bb/cascades/bbcascades_global.h>
#include <QtCore/QObject>
#include <QtDeclarative/QtDeclarative>
namespace bb {
  namespace cascades {
    class WebStoragePrivate;
    class WebStorage : public QObject
    {
public:
        MOCK_METHOD0(clear, void ());
        MOCK_METHOD0(clearAutofillData, void ());
        MOCK_METHOD0(clearCache, void ());
        MOCK_METHOD0(clearCookies, void ());
        MOCK_METHOD0(clearCredentials, void ());
        MOCK_METHOD0(clearDatabases, void ());
        MOCK_METHOD0(clearLocalStorage, void ());
public:
        WebStorage(WebStoragePrivate &dd);
        virtual ~WebStorage();
    };
}
}
#endif	
