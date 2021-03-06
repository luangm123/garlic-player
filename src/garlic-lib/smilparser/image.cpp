/*************************************************************************************
    garlic-player: SMIL Player for Digital Signage
    Copyright (C) 2016 Nikolaos Saghiadinos <ns@smil-control.com>
    This file is part of the garlic-player source code

    This program is free software: you can redistribute it and/or  modify
    it under the terms of the GNU Affero General Public License, version 3,
    as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************************/

#include "image.h"

TImage::TImage(TContainer *pc, QObject *parent) : TMedia(parent)
{
    parent_container = pc;
    initTimer();
    setObjectName("TImage");
}

TImage::~TImage()
{
    deleteTimer();
}

void TImage::setDurationTimerBeforePlay()
{
    if (isDownloaded() && (hasDurAttribute() || end_timer->isActive()))
    {
        if (!is_resumed)
            emit startedMedia(parent_container, this);
    }
    else // set a duration otherwise it runs in a recursion stack overflow when no dur set or download is not complete
        setInternalDefaultDur();
}

void TImage::play()
{
    qDebug(Develop) << getID() << "played";
    status = _playing;
}

void TImage::pause()
{
    qDebug(Develop) << getID() << "paused" << end_remaining;
    status = _paused;
}

void TImage::stop()
{
    qDebug(Develop) << getID() << "stopped";
    status = _stopped;
}

// ====================  protected methods =================================

void TImage::setAttributes()
{
    setBaseMediaAttributes();
}

// ====================  private methods =================================
