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

#ifndef STATIONARYSEARCHER3_HPP
#define STATIONARYSEARCHER3_HPP

#include <Core/Parents/Searchers/StationarySearcher.hpp>
#include <Core/Parents/States/State.hpp>
#include <Core/RNG/RNGCache.hpp>
#include <mutex>

class StationarySearcher3 : public StationarySearcher
{
public:
    StationarySearcher3() = default;
    StationarySearcher3(u16 tid, u16 sid, u8 genderRatio, Method method, const StateFilter &filter);
    void startSearch(const std::array<u8, 6> &min, const std::array<u8, 6> &max);
    void cancelSearch();
    std::vector<State> getResults();
    int getProgress() const;

private:
    RNGCache cache;
    u8 ivAdvance;

    bool searching;
    int progress;
    std::vector<State> results;
    std::mutex mutex;

    std::vector<State> search(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<State> searchMethod124(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<State> searchMethod1Reverse(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<State> searchLocked16Bit(u16 seed) const;
    std::vector<State> searchWishmaker(u16 seed) const;
};

#endif // STATIONARYSEARCHER3_HPP
