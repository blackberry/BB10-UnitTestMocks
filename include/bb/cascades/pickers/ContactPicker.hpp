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
#ifndef BB_CASCADES_PICKERS_CONTACTPICKER_HPP
#define BB_CASCADES_PICKERS_CONTACTPICKER_HPP
#include "gtest/gtest.h"
#include <bb/cascades/pickers/ContactSelectionMode>
#include <bb/cascades/pickers/SelectedContactAttribute>
#include <bb/cascades/pickers/Global>
#include <bb/pim/contacts/ContactConsts>
#include <QObject>
#include <QFlags>
#include <QtDeclarative>
namespace bb
{
namespace cascades
{
namespace pickers
{
class ContactPickerPrivate;
class QT_CASCADES_EXPORT BB_CASCADES_PICKERS_EXPORT ContactPicker : public QObject{
public:
    ContactPicker(QObject *parent = 0);
    virtual ~ContactPicker();
    MOCK_METHOD0(open, void ());
    MOCK_METHOD0(close, void ());
    MOCK_METHOD1(setMode, void (bb::cascades::pickers::ContactSelectionMode::Type mode));
    MOCK_CONST_METHOD0(mode, bb::cascades::pickers::ContactSelectionMode::Type ());
    MOCK_METHOD1(setTitle, void (const QString &title));
    MOCK_CONST_METHOD0(title, QString ());
    MOCK_METHOD1(setAccount, void (int accountId));
    MOCK_CONST_METHOD0(account, int ());
    MOCK_METHOD1(setConfirmButtonLabel, void (const QString &confirmButtonLabel));
    MOCK_CONST_METHOD0(confirmButtonLabel, QString ());
    MOCK_METHOD1(setKindFilters, void (const QSet<bb::pim::contacts::AttributeKind::Type> &kindFilters));
    MOCK_CONST_METHOD0(kindFilters, QSet<bb::pim::contacts::AttributeKind::Type> ());
    MOCK_METHOD1(setSubKindFilters, void (const QSet<bb::pim::contacts::KindSubKindSpecifier> &subKindFilters));
    MOCK_CONST_METHOD0(subKindFilters, QSet<bb::pim::contacts::KindSubKindSpecifier> ());
    MOCK_CONST_METHOD0(selectedContactId, int ());
    MOCK_CONST_METHOD0(selectedContactsIds, QList<int> ());
    MOCK_CONST_METHOD0(selectedContactAttribute, SelectedContactAttribute ());
    MOCK_METHOD0(canceled, void ());
    MOCK_METHOD0(error, void ());
    MOCK_METHOD1(contactSelected, void (int contactId));
    MOCK_METHOD1(contactsSelected, void (const QList<int> &contactIds));
    MOCK_METHOD1(contactAttributeSelected, void (const bb::cascades::pickers::SelectedContactAttribute &attribute));
    MOCK_METHOD1(modeChanged, void (bb::cascades::pickers::ContactSelectionMode::Type newMode));
    MOCK_METHOD1(confirmButtonLabelChanged, void (const QString &newLabel));
    MOCK_METHOD1(kindFiltersChanged, void (const QSet<bb::pim::contacts::AttributeKind::Type> &kindFilters));
    MOCK_METHOD1(subKindFiltersChanged, void (const QSet<bb::pim::contacts::KindSubKindSpecifier> &subKindFilters));
    MOCK_METHOD1(titleChanged, void (const QString &newTitle));
    MOCK_METHOD1(accountChanged, void (int newAccount));
};
} 
} 
} 
#endif 
