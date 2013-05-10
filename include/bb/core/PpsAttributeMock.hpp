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

#ifndef BB_CORE_PPSATTRIBUTEMOCK_HPP
#define BB_CORE_PPSATTRIBUTEMOCK_HPP

#include <bb/PpsAttributeFlag>

#include <QList>
#include <QMap>
#include <QSharedDataPointer>
#include <QVariant>

#include "gmock/gmock.h"

namespace bb {
    class PpsAttribute;
    typedef QMap<QString, PpsAttribute> PpsAttributeMap_t;

    class PpsAttributeMock {
    public:
        PpsAttributeMock() {};
        ~PpsAttributeMock() {};

        MOCK_CONST_METHOD1(equals, bool(const PpsAttribute &other));
        MOCK_CONST_METHOD0(isValid, bool());
        MOCK_CONST_METHOD0(type, int());
        MOCK_CONST_METHOD0(flags, PpsAttributeFlag::Types());
        MOCK_CONST_METHOD0(isNumber, bool());
        MOCK_CONST_METHOD0(isBool, bool());
        MOCK_CONST_METHOD0(isString, bool());
        MOCK_CONST_METHOD0(isArray, bool());
        MOCK_CONST_METHOD0(isObject, bool());
        MOCK_CONST_METHOD0(toDouble, double());
        MOCK_CONST_METHOD0(toLongLong, qlonglong());
        MOCK_CONST_METHOD0(toInt, int());
        MOCK_CONST_METHOD0(toBool, bool());
        MOCK_CONST_METHOD0(toString, QString());
        MOCK_CONST_METHOD0(toList, QList<bb::PpsAttribute>());
        MOCK_CONST_METHOD0(toMap, PpsAttributeMap_t());
        MOCK_CONST_METHOD0(toVariant, QVariant());
    };

}  // namespace bb
#endif // BB_CORE_PPSATTRIBUTEMOCK_HPP
