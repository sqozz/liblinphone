/*
 * conference-event.cpp
 * Copyright (C) 2010-2017 Belledonne Communications SARL
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "address/address.h"
#include "conference-event-p.h"

// =============================================================================

using namespace std;

LINPHONE_BEGIN_NAMESPACE

ConferenceEvent::ConferenceEvent (Type type, const Address &address) :
	EventLog(*new ConferenceEventPrivate, type) {
	L_D();
	L_ASSERT(type == Type::ConferenceCreated || type == Type::ConferenceDestroyed);
	d->address = address;
}

ConferenceEvent::ConferenceEvent (const ConferenceEvent &src) : ConferenceEvent(src.getType(), src.getAddress()) {}

ConferenceEvent::ConferenceEvent (ConferenceEventPrivate &p, Type type, const Address &address) :
	EventLog(p, type) {
	L_D();
	d->address = address;
}

ConferenceEvent &ConferenceEvent::operator= (const ConferenceEvent &src) {
	L_D();
	if (this != &src) {
		EventLog::operator=(src);
		d->address = src.getPrivate()->address;
	}

	return *this;
}

const Address &ConferenceEvent::getAddress () const {
	L_D();
	return d->address;
}

LINPHONE_END_NAMESPACE
