// SPDX-FileCopyrightText: 2018 - 2022 UnionTech Software Technology Co., Ltd.
// 
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "dbusproxybase.hpp"
#include "session_org_deepin_dde_Notification1.h"

class SessionNotification1Proxy : public DBusProxyBase {
public:
    SessionNotification1Proxy(QString dbusName, QString dbusPath, QString dbusInterface,
        QString proxyDbusName, QString proxyDbusPath, QString proxyDbusInterface,
        QDBusConnection::BusType dbusType, QObject *parent = nullptr) 
        : DBusProxyBase(dbusName, dbusPath, dbusInterface, proxyDbusName, proxyDbusPath, proxyDbusInterface, dbusType, parent)
    {
        InitFilterProperies(QStringList({}));
        InitFilterMethods(QStringList({"Nofity"}));
        ServiceStart();
    }
    virtual DDBusExtendedAbstractInterface *initConnect()
    {
        m_dbusProxy = new org::deepin::dde::Notification1(m_dbusName, m_dbusPath, QDBusConnection::sessionBus(), this);
        return m_dbusProxy;
    }
    
private:
    org::deepin::dde::Notification1 *m_dbusProxy;
};


