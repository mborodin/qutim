/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2012 Ruslan Nigmatullin <euroelessar@yandex.ru>
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

#include "contactlistfrontmodel.h"
#include "contactlistplainmodel.h"
#include <QtDebug>

ContactListFrontModel::ContactListFrontModel(QObject *parent)
    : QSortFilterProxyModel(parent), m_showOffline(true)
{
//	QVariantMap order = config.value("order", QVariantMap());
//	for (QVariantMap::Iterator it = order.begin(); it != order.end(); ++it)
//		m_order[it.key()] = it.value().toStringList();

    m_accounts = m_manager.enabledAccounts();
    connect(&m_manager, &AccountManager::enabledAccountsChanged,
            this, &ContactListFrontModel::onAccountsChanged);

	setFilterCaseSensitivity(Qt::CaseInsensitive);
	setSortCaseSensitivity(Qt::CaseInsensitive);
	sort(0);
	setDynamicSortFilter(true);
    setBaseModel(new ContactListPlainModel(this));
}

bool ContactListFrontModel::offlineVisibility() const
{
	return m_showOffline;
}

void ContactListFrontModel::setOfflineVisibility(bool showOffline)
{
	if (m_showOffline != showOffline) {
		m_showOffline = showOffline;
		emit offlineVisibilityChanged(showOffline);
		invalidateFilter();
	}
}

QStringList ContactListFrontModel::tags() const
{
    return m_model ? m_model->tags() : QStringList();
}

QStringList ContactListFrontModel::filterTags() const
{
	return m_filterTags;
}

QStringList ContactListFrontModel::mimeTypes() const
{
	return QStringList();
//			<< ContactListMimeData::objectMimeType()
//			<< ContactListMimeData::modelIndexListMimeType();
}

QMimeData *ContactListFrontModel::mimeData(const QModelIndexList &indexes) const
{
    return NULL;
//	QModelIndexList filteredList;
//	QObject *contact = NULL;
//	foreach (const QModelIndex &index, indexes) {
//		switch (index.data(ItemTypeRole).toInt()) {
//		case ContactType:
//			contact = index.data(ContactRole).value<QObject*>();
//			Q_ASSERT(qobject_cast<Contact*>(contact));
//			// fall through
//		case TagType:
//			filteredList << index;
//		default:
//			break;
//		}
//	}
//	if (filteredList.isEmpty())
//		return NULL;
//	ContactListMimeData *mimeData = new ContactListMimeData();
//	mimeData->setIndexes(filteredList);
//	mimeData->setObject(contact);
//	return mimeData;
}

struct ContactListOrderComparator
{
	const QStringList &order;

	inline bool operator() (const QString &leftName, const QString &rightName) const
	{
		const int leftIndex = order.indexOf(leftName);
		const int rightIndex = order.indexOf(rightName);
		return leftIndex < rightIndex
				|| (leftIndex == rightIndex
					&& leftName.compare(rightName, Qt::CaseInsensitive) < 0);
	}
};

bool ContactListFrontModel::dropMimeData(const QMimeData *genericData, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    return false;
//	Q_UNUSED(column);
//	const ContactListMimeData *data = qobject_cast<const ContactListMimeData*>(genericData);
//	QPersistentModelIndex persistentIndex = data->indexes().value(0);
//	if (!persistentIndex.isValid())
//		return false;
//	QModelIndex index = persistentIndex;
//	const ContactListItemType parentType = static_cast<ContactListItemType>(parent.data(ItemTypeRole).toInt());
//	const ContactListItemType type = static_cast<ContactListItemType>(index.data(ItemTypeRole).toInt());
//	if (parentType == TagType && type == ContactType) {
//		const QString tag = parent.data(TagNameRole).toString();
//		Contact *contact = qobject_cast<Contact*>(index.data(ContactRole).value<QObject*>());
//		Q_ASSERT(contact);
//		QStringList tags = contact->tags();
//		if (tags.contains(tag))
//			return false;
//		if (action == Qt::MoveAction)
//			tags.removeOne(index.parent().data(TagNameRole).toString());
//		tags.append(tag);
//		contact->setTags(tags);
//		return true;
//	} else if (parent == index.parent()) {
//		const QString parentName = parent.data(TagNameRole).toString();
//		const QString indexName = index.data(TagNameRole).toString();

//		QStringList &order = m_order[parentName];

//		ContactListOrderComparator comparator = { order };
//		QModelIndex sourceParent = mapToSource(parent);
//		QStringList allNames;
//		for (int i = 0, count = sourceModel()->rowCount(sourceParent); i < count; ++i)
//			allNames << sourceModel()->index(i, 0, sourceParent).data(TagNameRole).toString();
//		qSort(allNames.begin(), allNames.end(), comparator);

//		order = allNames;

//		const int currentIndex = allNames.indexOf(indexName);
//		allNames.removeOne(indexName);
//		const QString targetName = QSortFilterProxyModel::index(row, 0, parent).data(TagNameRole).toString();

//		int newIndex = allNames.indexOf(targetName);
//		if (newIndex == -1) newIndex = allNames.count();
//		if (newIndex != currentIndex && newIndex >= 0) {
//			order.move(currentIndex, newIndex);

//			Config config;
//			config.beginGroup("contactList");
//			config.beginGroup("order");
//			config.setValue(parentName, order);

//			invalidate();
//		}

//		return true;
//	} else if (parentType == type && type == ContactType) {
//		// TODO: Implement metacontacts creating
//		return false;
//	} else {
//		return false;
//	}
}

Qt::DropActions ContactListFrontModel::supportedDropActions() const
{
    return Qt::IgnoreAction;
//	return Qt::CopyAction | Qt::MoveAction;
}

Qt::ItemFlags ContactListFrontModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags flags = QAbstractItemModel::flags(index);

	const ContactListItemType type = static_cast<ContactListItemType>(index.data(ItemTypeRole).toInt());
	switch (type) {
	case ContactType:
		flags |= Qt::ItemIsEditable;
		// fall through
	case TagType:
		flags |= Qt::ItemIsDragEnabled;
		// fall through
	case AccountType:
	default:
		flags |= Qt::ItemIsDropEnabled;
		break;
	}

    return flags;
}

QHash<int, QByteArray> ContactListFrontModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames.insert(IdRole, "id");
    roleNames.insert(Qt::DisplayRole, "title");
    roleNames.insert(StatusTextRole, "statusText");
    roleNames.insert(StatusIconNameRole, "statusName");
    roleNames.insert(StatusTypeRole, "statusType");
    roleNames.insert(StatusIdRole, "statusId");
    roleNames.insert(ContactsCountRole, "totalCount");
    roleNames.insert(OnlineContactsCountRole, "onlineCount");
    roleNames.insert(TagNameRole, "name");
    roleNames.insert(NotificationRole, "notification");
    roleNames.insert(ItemTypeRole, "itemType");
    roleNames.insert(ContactRole, "contact");
    roleNames.insert(AlphabetRole, "alphabet");
    roleNames.insert(AvatarRole, "avatar");
    return roleNames;
}

void ContactListFrontModel::setFilterTags(const QStringList &filterTags)
{
	if (m_filterTags == filterTags)
		return;
	m_filterTags = filterTags;
	emit filterTagsChanged(m_filterTags);
	invalidateFilter();
}

void ContactListFrontModel::inverseOfflineVisibility()
{
	setOfflineVisibility(!m_showOffline);
}

void ContactListFrontModel::addContact(Contact *contact)
{
	static_cast<ContactListBaseModel*>(sourceModel())->onContactAdded(contact);
}

void ContactListFrontModel::removeContact(Contact *contact)
{
	static_cast<ContactListBaseModel*>(sourceModel())->onContactRemoved(contact);
}

//void ContactListFrontModel::onServiceChanged(const QByteArray &name, QObject *newObject, QObject *oldObject)
//{
//	Q_UNUSED(newObject);
//	Q_UNUSED(oldObject);
//	if (name == m_comparator.name()) {
//		connect(m_comparator, SIGNAL(contactChanged(Contact*)),
//				sourceModel(), SLOT(onContactChanged(Contact*)));
//		invalidate();
//	} else if (name == m_model.name()) {
//		ContactListBaseModel *oldModel = qobject_cast<ContactListBaseModel*>(oldObject);
//		ContactListBaseModel *newModel = qobject_cast<ContactListBaseModel*>(newObject);
//		if (newModel) {
//			connect(newModel, SIGNAL(tagsChanged(QStringList)),
//					this, SIGNAL(tagsChanged(QStringList)));
//			connect(m_comparator, SIGNAL(contactChanged(Contact*)),
//					newModel, SLOT(onContactChanged(Contact*)));
//			foreach(Protocol *proto, Protocol::all()) {
//				connect(proto, SIGNAL(accountCreated(Account*)),
//						newModel, SLOT(onAccountCreated(Account*)));
//				connect(proto, SIGNAL(accountRemoved(Account*)),
//						newModel, SLOT(onAccountRemoved(Account*)));
//				foreach(Account *account, proto->accounts())
//					newModel->onAccountCreated(account, !oldModel);
//			}
//			if (oldModel) {
//				QSet<Contact*> contacts;
//				oldModel->findContacts(contacts, oldModel->rootNode());
//				foreach (Contact *contact, contacts)
//					newModel->addContact(contact);
//			}
//		}
//		setSourceModel(newModel);
//	} else if (name == m_metaManager.name()) {
//		if (MetaContactManager *oldManager = qobject_cast<MetaContactManager*>(oldObject))
//			m_model->onAccountRemoved(oldManager);
//		if (m_metaManager)
//			m_model->onAccountCreated(m_metaManager);
//	}
//}

bool ContactListFrontModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
	QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
	const QRegExp regexp = filterRegExp();
	switch (index.data(ItemTypeRole).toInt()) {
	case ContactType: {
		Contact *contact = index.data(ContactRole).value<Contact*>();
		Q_ASSERT(contact);
		if (!regexp.isEmpty()) {
			return contact->id().contains(regexp) || contact->alias().contains(regexp);
		} else {
//			if (index.data(NotificationRole).toInt() >= Notification::IncomingMessage)
//				return true;
			if (!m_filterTags.isEmpty()) {
				bool hasAny = false;
				for (const QString &tag : contact->groups()) {
					hasAny |= bool(m_filterTags.contains(tag));
					if (hasAny)
						break;
				}
				if (!hasAny)
					return false;
			}
			if (!m_showOffline) {
				const Presence status = index.data(StatusRole).value<Presence>();
				return status.isOnline();
			}
		}
		break;
	}
	case TagType: {
		if (!m_filterTags.isEmpty() && !m_filterTags.contains(index.data(TagNameRole).toString()))
			return false;
		int count = sourceModel()->rowCount(index);
		for (int i = 0; i < count; ++i) {
			if (filterAcceptsRow(i, index))
				return true;
		}
		return false;
	}
	default:
		break;
	};
	return true;
}

bool ContactListFrontModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
	const ContactListItemType leftType = static_cast<ContactListItemType>(left.data(ItemTypeRole).toInt());
	const ContactListItemType rightType = static_cast<ContactListItemType>(right.data(ItemTypeRole).toInt());
	if (leftType != rightType)
		return leftType < rightType;

	switch (leftType) {
	case ContactType: {
		Contact *leftContact = left.data(ContactRole).value<Contact*>();
		Contact *rightContact = right.data(ContactRole).value<Contact*>();
		Q_ASSERT(leftContact);
		Q_ASSERT(rightContact);
        return leftContact->alias() < rightContact->alias();
//		return m_comparator->compare(leftContact, rightContact) < 0;
	}
	case TagType:
	case AccountType: {
		const QString parentName = left.parent().data(TagNameRole).toString();
		const ContactListOrderComparator comparator = { m_order[parentName] };
		const QString leftName = left.data(TagNameRole).toString();
		const QString rightName = right.data(TagNameRole).toString();
		return comparator(leftName, rightName);
	}
	default:
		break;
	}
	return false;
}

void ContactListFrontModel::setBaseModel(ContactListBaseModel *model)
{
    if (m_model)
        m_model->deleteLater();

    if (model) {
        connect(model, &ContactListBaseModel::tagsChanged,
                this, &ContactListFrontModel::tagsChanged);

//        connect(m_comparator, SIGNAL(contactChanged(Contact*)),
//                model, SLOT(onContactChanged(Contact*)));

        for (Account *account : m_accounts)
            model->onAccountCreated(account, !m_model);

        if (m_model) {
            QSet<Contact*> contacts;
            m_model->findContacts(contacts, m_model->rootNode());
            for (Contact *contact : contacts)
                model->addContact(contact);
        }
    }
    m_model = model;
    setSourceModel(model);
}

void ContactListFrontModel::onAccountsChanged(const QList<Account *> &accounts)
{
    for (Account *account: accounts) {
        if (!m_accounts.contains(account))
            m_model->onAccountCreated(account);
    }
    for (Account *account: m_accounts) {
        if (!accounts.contains(account))
            m_model->onAccountRemoved(account);
    }
    m_accounts = accounts;
}