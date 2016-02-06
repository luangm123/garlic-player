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
#include "factory.h"

TFactory::TFactory(TBase *parent)
{
    Q_UNUSED(parent);
}

TMedia* TFactory::createMedia(QString media_type, TBase *parent)
{
    if (media_type == "img")
        return new TImage(parent);
    else if (media_type == "video")
        return new TVideo(parent);
    else if (media_type == "audio")
        return new TAudio(parent);
    else if (media_type == "web")
        return new TWeb(parent);
    return NULL;
}


TPlaylist* TFactory::createPlaylist(QString playlist_type, TBase *parent)
{
    if (playlist_type == "seq")
        return new TSeq(parent);
    else if (playlist_type == "par")
        return new TPar(parent);
    else if (playlist_type == "excl")
        return new TExcl(parent);
    else if (playlist_type == "body")
        return new TBody();
    return NULL;
}
