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

#ifndef BB_CORE_PPSOBJECT_HPP
#define BB_CORE_PPSOBJECT_HPP

#include <bb/PpsAttribute>
#include <bb/PpsOpenMode>

#include <QDebug>
#include <QMap>
#include <QObject>
#include <QVariantMap>

#include "gmock/gmock.h"
#include <bb/core/PpsObjectMock.hpp>
#include <bb/testing/proxybase.h>

namespace bb
{
class PpsObject : public QObject, public bb::testing::ProxyBase<PpsObjectMock>
{
    Q_OBJECT

public:
    explicit PpsObject(const QString &path, QObject *parent = 0): QObject(parent) { (void)path; };
    virtual ~PpsObject() {};

    int error() const { return mock()->error(); };
    QString errorString() const { return mock()->errorString(); };
    bool isReadyReadEnabled() const { return mock()->isReadyReadEnabled(); };
    bool isBlocking() const { return mock()->isBlocking(); };
    bool isOpen() const { return mock()->isOpen(); };
    bool setBlocking(bool enable) { return mock()->setBlocking(enable); };
    bool close() { return mock()->close(); };
    bool remove() { return mock()->remove(); };

    bool open(PpsOpenMode::Types mode = PpsOpenMode::PublishSubscribe) { return mock()->open(mode); };
    QByteArray read(bool * ok = 0) { return mock()->read(ok); };
    bool write(const QByteArray &byteArray) { return mock()->write(byteArray); };

    static QVariantMap decode(const QByteArray &rawData, bool * ok = 0) { return staticMock()->decode(rawData, ok); };
    static QMap<QString, PpsAttribute> decodeWithFlags(const QByteArray &rawData, bool * ok = 0) { return staticMock()->decodeWithFlags(rawData, ok); };
    static QByteArray encode(const QVariantMap &ppsData, bool * ok = 0) { return staticMock()->encode(ppsData, ok); };

public Q_SLOTS:
    void setReadyReadEnabled(bool enable) { return mock()->setReadyReadEnabled(enable); };

Q_SIGNALS:
    void readyRead();
};

static inline QDebug operator<<(QDebug dbg, const PpsAttribute &attribute) {
    dbg << "PpsAttribute " << ((int) &attribute);
    return dbg;
}

} // namespace bb

#endif // BB_CORE_PPSOBJECT_HPP
