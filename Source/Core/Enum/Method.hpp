/*
 * This file is part of PokéFinder
 * Copyright (C) 2017-2021 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef METHOD_HPP
#define METHOD_HPP

#include <Core/Util/Global.hpp>

enum Method : u8
{
    Method1,
    Method1Reverse,
    Method2,
    Method4,
    MethodH1,
    MethodH2,
    MethodH4,
    Locked16Bit,
    Wishmaker,
    XD,
    Colo,
    XDColo,
    Channel,
    PossibleChannel,
    Ageto,
    Ageto0Difference,
    EBred,
    EBredSplit,
    EBredAlternate,
    EBredPID,
    RSBred,
    RSBredSplit,
    RSBredAlternate,
    FRLGBred,
    FRLGBredSplit,
    FRLGBredAlternate,
    FRLGBredMixed,
    MethodJ,
    MethodK,
    Manaphy,
    ChainedShiny,
    WondercardIVs,
    Gen4Normal,
    Gen4Masuda,
    PokeWalkerPID,
    PokeWalkerIVs,
    DPPtIVs,
    HGSSIVs,
    Gen4Combined,
    Method5IVs,
    Method5CGear,
    Method5,
    BWBred,
    BW2Bred,
    DreamRadar,
    Method5Event
    // TODO: Add Gen 5 egg/events
};

#endif // METHOD_HPP
