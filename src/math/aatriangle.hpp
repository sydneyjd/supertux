//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_MATH_AATRIANGLE_HPP
#define HEADER_SUPERTUX_MATH_AATRIANGLE_HPP

#include "math/vector.hpp"

/**
 * An axis-aligned triangle (ie. a triangle where 2 sides are parallel to the x-
 * and y-axis.
 */
class AATriangle
{
public:
  /** Directions:
   *
   *    SOUTHEWEST    NORTHEAST   SOUTHEAST    NORTHWEST
   *    *      or      *---*   or      *    or *---*
   *    | \             \  |         / |       |  /
   *    |  \             \ |        /  |       | /
   *    *---*              *       *---*       *
   *
   * Deform flags: (see docs/aatriangletypes.png for details)
   */
  enum Direction {
    SOUTHWEST = 0,
    NORTHEAST,
    SOUTHEAST,
    NORTHWEST,
    DIRECTION_MASK = 0x0003,
    DEFORM1 = 0x0010,
    DEFORM2 = 0x0020,
    DEFORM3 = 0x0030,
    DEFORM4 = 0x0040,
    DEFORM_MASK = 0x0070
  };

  static int vertical_flip(int dir);

public:
  AATriangle() :
    p1(),
    p2(),
    dir(SOUTHWEST)
  {
  }
  AATriangle(const Vector& v1, const Vector& v2, int newdir) :
    p1(v1),
    p2(v2),
    dir(newdir)
  {
  }

  float get_width() const
  {
    return p2.x - p1.x; 
  }

  float get_height() const
  { 
    return p2.y - p1.y; 
  }

public:
  Vector p1;
  Vector p2;
  int dir;
};

#endif

/* EOF */
