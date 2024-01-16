// Copyright (c) 2000-2004
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL: https://github.com/CGAL/cgal/blob/v5.6/Cartesian_kernel/include/CGAL/Cartesian/Cartesian_base.h $
// $Id: Cartesian_base.h 0779373 2020-03-26T13:31:46+01:00 Sébastien Loriot
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Sylvain Pion

#ifndef CGAL_CARTESIAN_BASE_H
#define CGAL_CARTESIAN_BASE_H

#include <../CGALOSP/basic.h>
#include <../CGALOSP/basic_classes.h>
#include <../CGALOSP/Kernel/global_functions.h>

#include <../CGALOSP/Cartesian/Point_2.h>
#include <../CGALOSP/Cartesian/Weighted_point_2.h>
#include <../CGALOSP/Cartesian/Vector_2.h>
#include <../CGALOSP/Cartesian/Direction_2.h>
#include <../CGALOSP/Cartesian/Line_2.h>
#include <../CGALOSP/Cartesian/Ray_2.h>
#include <../CGALOSP/Cartesian/Segment_2.h>
#include <../CGALOSP/Cartesian/Triangle_2.h>
#include <../CGALOSP/Cartesian/Circle_2.h>
#include <../CGALOSP/Cartesian/Iso_rectangle_2.h>
#include <../CGALOSP/Cartesian/Aff_transformation_2.h>
#include <../CGALOSP/Cartesian/Data_accessor_2.h>
#include <../CGALOSP/Cartesian/ConicCPA2.h>

#include <../CGALOSP/Cartesian/predicates_on_points_2.h>
#include <../CGALOSP/Cartesian/predicates_on_directions_2.h>
#include <../CGALOSP/Cartesian/basic_constructions_2.h>

#include <../CGALOSP/Cartesian/Point_3.h>
#include <../CGALOSP/Cartesian/Weighted_point_3.h>
#include <../CGALOSP/Cartesian/Vector_3.h>
#include <../CGALOSP/Cartesian/Direction_3.h>
#include <../CGALOSP/Cartesian/Line_3.h>
#include <../CGALOSP/Cartesian/Plane_3.h>
#include <../CGALOSP/Cartesian/Ray_3.h>
#include <../CGALOSP/Cartesian/Segment_3.h>
#include <../CGALOSP/Cartesian/Triangle_3.h>
#include <../CGALOSP/Cartesian/Tetrahedron_3.h>
#include <../CGALOSP/Cartesian/Iso_cuboid_3.h>
#include <../CGALOSP/Cartesian/Sphere_3.h>
#include <../CGALOSP/Cartesian/Circle_3.h>
#include <../CGALOSP/Cartesian/Aff_transformation_3.h>

#include <../CGALOSP/Cartesian/predicates_on_points_3.h>
#include <../CGALOSP/Cartesian/predicates_on_planes_3.h>
#include <../CGALOSP/Cartesian/basic_constructions_3.h>

#include <../CGALOSP/representation_tags.h>
#include <../CGALOSP/Cartesian/function_objects.h>
#include <../CGALOSP/Uncertain.h>

namespace CGAL {

template < typename K_, typename FT_>
struct Cartesian_base
{
    typedef K_                                          Kernel;
    typedef FT_                                         FT;
    typedef Cartesian_base<K_,FT_>                      Self;
    typedef Cartesian_tag                               Rep_tag;
    typedef Cartesian_tag                               Kernel_tag;

    enum { Has_filtered_predicates = false };
    typedef Boolean_tag<Has_filtered_predicates> Has_filtered_predicates_tag;

    typedef CGAL::Object                                Object_2;
    typedef CGAL::Object                                Object_3;

    // Boolean   had originally been Bool. It was renamed to avoid a conflict
    // between a macro defined in Xlib.h poorly chosen to have the same name,
    // that is 'Bool'.
    typedef typename Same_uncertainty_nt<bool, FT>::type
                                                        Boolean;
    typedef typename Same_uncertainty_nt<CGAL::Sign, FT>::type
                                                        Sign;
    typedef typename Same_uncertainty_nt<CGAL::Comparison_result, FT>::type
                                                        Comparison_result;
    typedef typename Same_uncertainty_nt<CGAL::Orientation, FT>::type
                                                        Orientation;
    typedef typename Same_uncertainty_nt<CGAL::Oriented_side, FT>::type
                                                        Oriented_side;
    typedef typename Same_uncertainty_nt<CGAL::Bounded_side, FT>::type
                                                        Bounded_side;
    typedef typename Same_uncertainty_nt<CGAL::Angle, FT>::type
                                                        Angle;

    template <typename T>
    struct Ambient_dimension {
      typedef typename T::Ambient_dimension type;
    };

    template <typename T>
    struct Feature_dimension {
      typedef typename T::Feature_dimension type;
    };

    typedef PointC2<Kernel>                             Point_2;
    typedef VectorC2<Kernel>                            Vector_2;
    typedef DirectionC2<Kernel>                         Direction_2;
    typedef SegmentC2<Kernel>                           Segment_2;
    typedef LineC2<Kernel>                              Line_2;
    typedef RayC2<Kernel>                               Ray_2;
    typedef TriangleC2<Kernel>                          Triangle_2;
    typedef CircleC2<Kernel>                            Circle_2;
    typedef Iso_rectangleC2<Kernel>                     Iso_rectangle_2;
    typedef Aff_transformationC2<Kernel>                Aff_transformation_2;
    typedef Weighted_pointC2<Kernel>                    Weighted_point_2;

    typedef PointC3<Kernel>                             Point_3;
    typedef VectorC3<Kernel>                            Vector_3;
    typedef DirectionC3<Kernel>                         Direction_3;
    typedef LineC3<Kernel>                              Line_3;
    typedef PlaneC3<Kernel>                             Plane_3;
    typedef RayC3<Kernel>                               Ray_3;
    typedef SegmentC3<Kernel>                           Segment_3;
    typedef TriangleC3<Kernel>                          Triangle_3;
    typedef TetrahedronC3<Kernel>                       Tetrahedron_3;
    typedef Iso_cuboidC3<Kernel>                        Iso_cuboid_3;
    typedef SphereC3<Kernel>                            Sphere_3;
    typedef CircleC3<Kernel>                            Circle_3;
    typedef Aff_transformationC3<Kernel>                Aff_transformation_3;
    typedef Weighted_pointC3<Kernel>                    Weighted_point_3;

    typedef typename std::array<FT_, 2>::const_iterator Cartesian_const_iterator_2;
    typedef typename std::array<FT_, 3>::const_iterator Cartesian_const_iterator_3;

    // Undocumented stuff.
    typedef Data_accessorC2<Kernel>                     Data_accessor_2;
    typedef ConicCPA2<Point_2,Data_accessor_2>          Conic_2;
};

} //namespace CGAL

#endif // CGAL_CARTESIAN_BASE_H
