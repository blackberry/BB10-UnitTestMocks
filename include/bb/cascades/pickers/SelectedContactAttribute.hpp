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
#ifndef BB_CASCADES_PICKERS_SELECTEDCONTACTATTRIBUTE_HPP_
#define BB_CASCADES_PICKERS_SELECTEDCONTACTATTRIBUTE_HPP_
#include "gtest/gtest.h"
#include <bb/cascades/pickers/Global>
#include <bb/pim/contacts/ContactConsts>
#include <QtDeclarative>
#include <QSharedData>
namespace bb
{
namespace cascades
{
namespace pickers
{
class SelectedContactAttributePrivate;
class QT_CASCADES_EXPORT BB_CASCADES_PICKERS_EXPORT SelectedContactAttribute{
public:
    SelectedContactAttribute();
    SelectedContactAttribute(const SelectedContactAttribute &copy);
    bool operator==(const SelectedContactAttribute &operand) const;
    SelectedContactAttribute& operator=(const SelectedContactAttribute &operand);
    bool operator!=(const SelectedContactAttribute &operand) const;
    virtual ~SelectedContactAttribute();
    MOCK_METHOD1(setAttributeKind, void (bb::pim::contacts::AttributeKind::Type attributeKind));
    MOCK_CONST_METHOD0(attributeKind, bb::pim::contacts::AttributeKind::Type ());
    MOCK_METHOD1(setAttributeSubKind, void (bb::pim::contacts::AttributeSubKind::Type attributeSubKind));
    MOCK_CONST_METHOD0(attributeSubKind, bb::pim::contacts::AttributeSubKind::Type ());
    MOCK_METHOD1(setContactId, void (int contactId));
    MOCK_CONST_METHOD0(contactId, int ());
    MOCK_METHOD1(setValue, void (const QString &value));
    MOCK_CONST_METHOD0(value, QString ());
};
} 
} 
} 
#endif 
