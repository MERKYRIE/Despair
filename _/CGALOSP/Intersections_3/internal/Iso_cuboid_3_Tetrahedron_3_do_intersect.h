// Copyright (c) 2018 GeometryFactory
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL: https://github.com/CGAL/cgal/blob/v5.6/Intersections_3/include/CGAL/Intersections_3/internal/Iso_cuboid_3_Tetrahedron_3_do_intersect.h $
// $Id: Iso_cuboid_3_Tetrahedron_3_do_intersect.h c2d1adf 2021-06-23T17:34:48+02:00 Mael Rouxel-Labbé
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Andreas Fabri

#ifndef CGAL_INTERNAL_INTERSECTIONS_3_ISO_CUBOID_3_TETRAHEDRON_3_DO_INTERSECT_H
#define CGAL_INTERNAL_INTERSECTIONS_3_ISO_CUBOID_3_TETRAHEDRON_3_DO_INTERSECT_H

#include <../CGALOSP/Intersections_3/internal/Tetrahedron_3_Bounded_3_do_intersect.h>

namespace CGAL {
namespace Intersections {
namespace internal {

template <class K>
inline
typename K::Boolean
do_intersect(const typename K::Tetrahedron_3& tet,
             const typename K::Iso_cuboid_3& ic,
             const K& k)
{
  return do_intersect_tetrahedron_bounded(ic, tet, ic[0], k);
}

template <class K>
inline
typename K::Boolean
do_intersect(const typename K::Iso_cuboid_3& ic,
             const typename K::Tetrahedron_3& tet,
             const K& k)
{
  return do_intersect_tetrahedron_bounded(ic, tet, ic[0], k);
}

} // namespace internal
} // namespace Intersections
} // namespace CGAL

#endif // CGAL_INTERNAL_INTERSECTIONS_3_ISO_CUBOID_3_TETRAHEDRON_3_DO_INTERSECT_H
