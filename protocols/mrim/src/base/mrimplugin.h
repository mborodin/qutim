/****************************************************************************
**
** qutIM - instant messenger
**
** Copyright © 2011 Rusanov Peter <peter.rusanov@gmail.com>
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

#ifndef MRIMPLUGIN_H
#define MRIMPLUGIN_H

#include <qutim/plugin.h>

using namespace qutim_sdk_0_3;

class MrimPlugin : public Plugin
{
    Q_OBJECT
    Q_CLASSINFO("DebugName","MRIM")
public:
    MrimPlugin();
    void init();
    bool load();
    bool unload();
};

#endif // MRIMPLUGIN_H

