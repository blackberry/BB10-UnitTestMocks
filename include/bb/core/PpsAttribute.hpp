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

#ifndef BB_CORE_PPSATTRIBUTE_HPP
#define BB_CORE_PPSATTRIBUTE_HPP

#include <bb/PpsAttributeFlag>

#include <QList>
#include <QMap>
#include <QSharedDataPointer>
#include <QVariant>

#include "gmock/gmock.h"
#include <bb/core/PpsAttributeMock.hpp>
#include <bb/testing/proxybase.h>

namespace bb
{
class PpsAttributePrivate;

// needed for Qt to compile PpsAttribute without errors
class GadgetHelper {
	Q_GADGET
};

class PpsAttribute: public GadgetHelper, public bb::testing::ProxyBase<PpsAttributeMock>
{
    Q_GADGET
    Q_ENUMS(Type)

public:
    enum Type
    {
        None   = 0,
        Number = 1,
        Bool   = 2,
        String = 3,
        Array  = 4,
        Object = 5
    };

    PpsAttribute(){};
    ~PpsAttribute() {};

    bool operator==(const PpsAttribute & other) const {return mock()->equals(other);};
    bool operator!=(const PpsAttribute & other) const {return !mock()->equals(other);};

    bool isValid() const {return mock()->isValid();};
    Type type() const {return (Type) mock()->type();};
    PpsAttributeFlag::Types flags() const {return mock()->flags();};
    bool isNumber() const {return mock()->isNumber();};
    bool isBool() const {return mock()->isBool();};
    bool isString() const {return mock()->isString();};
    bool isArray() const {return mock()->isArray();};
    bool isObject() const {return mock()->isObject();};
    double toDouble() const {return mock()->toDouble();};
    qlonglong toLongLong() const {return mock()->toLongLong();};
    int toInt() const {return mock()->toInt();};
    bool toBool() const {return mock()->toBool();};
    QString toString() const {return mock()->toString();};
    QList<PpsAttribute> toList() const {return mock()->toList();};
    QMap<QString, PpsAttribute> toMap() const {return mock()->toMap();};
    QVariant toVariant() const {return mock()->toVariant();};
};

} // namespace bb

#endif // BB_CORE_PPSOBJECT_HPP
