/*
 * $Id$
 *
 * Copyright (C) 2002-2004 Andreas Oberritter <obi@saftware.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <dvbsi++/byte_stream.h>
#include <dvbsi++/data_broadcast_id_descriptor.h>

DataBroadcastIdDescriptor::DataBroadcastIdDescriptor(const uint8_t * const buffer) : Descriptor(buffer)
{
	dataBroadcastId = UINT16(&buffer[2]);

	for (size_t i = 0; i < descriptorLength - 2; ++i)
		idSelectorBytes.push_back(buffer[i + 4]);
}

uint16_t DataBroadcastIdDescriptor::getDataBroadcastId(void) const
{
	return dataBroadcastId;
}

const IdSelectorByteList *DataBroadcastIdDescriptor::getIdSelectorBytes(void) const
{
	return &idSelectorBytes;
}

