/****************************************************************************
 *
 *  This file is part of qutIM
 *
 *  Copyright (c) 2010 by Nigmatullin Ruslan <euroelessar@gmail.com>
 *
 ***************************************************************************
 *                                                                         *
 *   This file is part of free software; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License as        *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 ***************************************************************************
 ****************************************************************************/

#include "phononsoundbackend.h"
#ifdef HAS_SYSTEMINTEGRATION
#include <qutim/systemintegration.h>
#endif

PhononSoundBackend::PhononSoundBackend()
{
	// FIXME
#ifdef HAS_SYSTEMINTEGRATION
	SystemIntegration *system = SystemIntegration::instance();
#endif
	QStringList mimeTypes = Phonon::BackendCapabilities::availableMimeTypes();
	foreach (const QString &mime, mimeTypes) {
#ifdef HAS_SYSTEMINTEGRATION
		QVariant var = system->value(SystemIntegration::ExtensionsForMimeType, mime);
		m_formats << var.toStringList();
#else
		if (mime.startsWith(QLatin1String("audio/x-")))
			m_formats << mime.mid(8);
		else if (mime.startsWith(QLatin1String("audio/")))
			m_formats << mime.mid(6);
#endif
	}
	m_formats.removeDuplicates();
}

void PhononSoundBackend::playSound(const QString &filename)
{
	PathData data;
	data.mediaObject = new Phonon::MediaObject(this);
	data.mediaObject->setCurrentSource(Phonon::MediaSource(filename));
	data.audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	data.path = Phonon::createPath(data.mediaObject, data.audioOutput);
	connect(data.mediaObject, SIGNAL(finished()), this, SLOT(finishedPlaying()));
	m_cache.insert(data.mediaObject, data);
	data.mediaObject->play();
}

QStringList PhononSoundBackend::supportedFormats()
{
	return m_formats;
}

void PhononSoundBackend::finishedPlaying()
{
	Phonon::MediaObject *mediaObject = qobject_cast<Phonon::MediaObject*>(sender());
	PathData path = m_cache.take(mediaObject);
	path.path.disconnect();
	path.mediaObject->deleteLater();
	path.audioOutput->deleteLater();
}
