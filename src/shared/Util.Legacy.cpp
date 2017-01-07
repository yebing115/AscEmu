/*
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (C) 2014-2016 AscEmu Team <http://www.ascemu.org/>
 * Copyright (C) 2008-2012 ArcEmu Team <http://www.ArcEmu.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Util.hpp"

int32 GetTimePeriodFromString(const char* str)
{
    uint32 time_to_ban = 0;
    char* p = (char*)str;
    uint32 multiplier;
    std::string number_temp;
    uint32 multipliee;
    number_temp.reserve(10);
    while(*p != 0)
    {
        // always starts with a number.
        if(!isdigit(*p))
            break;
        number_temp.clear();
        while(isdigit(*p) && *p != 0)
        {
            number_temp += *p;
            ++p;
        }
        // try to find a letter
        if(*p != 0)
        {
            // check the type
            switch(tolower(*p))
            {
                case 'y':
                    multiplier = TIME_YEAR;        // eek!
                    break;
                case 'm':
                    multiplier = TIME_MONTH;
                    break;
                case 'd':
                    multiplier = TIME_DAY;
                    break;
                case 'h':
                    multiplier = TIME_HOUR;
                    break;
                default:
                    return -1;
                    break;
            }
            ++p;
        }
        else
            multiplier = TIME_MINUTE; // Defaults to MINUTES, if no letter is given
        multipliee = atoi(number_temp.c_str());
        time_to_ban += (multiplier * multipliee);
    }
    return time_to_ban;
}

uint32 DecimalToMask(uint32 dec)
{
    return ((uint32)1 << (dec - 1));
}

#ifdef WIN32
static char _StringConversionStorage[2048];
#endif

