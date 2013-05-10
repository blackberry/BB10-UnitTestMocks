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

#ifndef BB_CORE_PPSOBJECTMOCK_HPP
#define BB_CORE_PPSOBJECTMOCK_HPP

#include <bb/PpsAttribute>
#include <bb/PpsOpenMode>

#include <QMap>
#include <QObject>
#include <QVariantMap>

#include "gmock/gmock.h"

namespace bb
{
typedef QMap<QString, PpsAttribute> PpsAttributeMap_t;
class PpsObjectMock {
public:
    MOCK_CONST_METHOD0(error, int());
    MOCK_CONST_METHOD0(errorString, QString());
    MOCK_CONST_METHOD0(isReadyReadEnabled, bool());
    MOCK_CONST_METHOD0(isBlocking, bool());
    MOCK_METHOD1(setBlocking, bool(bool enable));
    MOCK_CONST_METHOD0(isOpen, bool());
    MOCK_METHOD1(open, bool(PpsOpenMode::Types));
    MOCK_METHOD0(close, bool());
    MOCK_METHOD1(read, QByteArray(bool));
    MOCK_METHOD1(write, bool(const QByteArray &byteArray));
    MOCK_METHOD0(remove, bool());
    MOCK_METHOD1(setReadyReadEnabled, void(bool enable));

    MOCK_METHOD2(decode, QVariantMap(const QByteArray &rawData, bool * ok));
    MOCK_METHOD2(decodeWithFlags, PpsAttributeMap_t(const QByteArray &rawData, bool * ok));
    MOCK_METHOD2(encode, QByteArray(const QVariantMap &ppsData, bool * ok));
};
} // namespace bb

#endif // BB_CORE_PPSOBJECTMOCK_HPP
