/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2011 Alexey Prokhin <alexey.prokhin@yandex.ru>
**
*****************************************************************************
**
** $QUTIM_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QUTIM_END_LICENSE$
**
****************************************************************************/

#ifndef CONTACTLISTSETTINGS_H
#define CONTACTLISTSETTINGS_H

#include <qutim/settingswidget.h>
#include <qutim/servicemanager.h>
#include <qutim/simplecontactlist/servicechooser.h>
#include <QRadioButton>
#include <QGroupBox>
#include <QHash>
#include <QSet>

class QLayout;
class QVBoxLayout;

namespace qutim_sdk_0_3 {
	class ObjectGenerator;
}

namespace Core {

using namespace qutim_sdk_0_3;

class ContactListSettings : public SettingsWidget
{
	Q_OBJECT
public:
	ContactListSettings();
	virtual ~ContactListSettings();
protected:
	virtual void loadImpl();
	virtual void saveImpl();
	virtual void cancelImpl();
private:
	void addService(const QByteArray &service, const LocalizedString &title);
	void addExtensionWidget(const QByteArray &service, const ObjectGenerator *gen, bool load);
private slots:
	void onServiceChanged(const QByteArray &newService, const QByteArray &oldService);
	void onModifiedChanged(bool haveChanges);
private:
	QVBoxLayout *m_layout;
	QHash<const ObjectGenerator*, SettingsWidget*> m_widgetCache;
	QHash<QByteArray, ServiceChooser*> m_serviceChoosers;
	QHash<QByteArray, const ObjectGenerator*> m_extensions;
	QHash<QByteArray, SettingsWidget*> m_extensionWidgets;
	QList<SettingsWidget*> m_staticExtensionWidgets;
	QSet<QByteArray> m_services;
	bool m_modified;
};

} // namespace Core

#endif // CONTACTLISTSETTINGS_H

