// Copyright (c) 1999,2007
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL: https://github.com/CGAL/cgal/blob/v5.6/Number_types/include/CGAL/number_type_basic.h $
// $Id: number_type_basic.h ac8b6d4 2022-06-10T07:59:39+02:00 Sébastien Loriot
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Stefan Schirra, Michael Hemmer


#ifndef CGAL_NUMBER_TYPE_BASIC_H
#define CGAL_NUMBER_TYPE_BASIC_H

#include <../CGALOSP/number_type_config.h>

#include <../CGALOSP/basic.h>

// basic tools needed in several files
#include <functional>
#include <type_traits>

#include <../CGALOSP/Quotient_fwd.h>

#include <../CGALOSP/Kernel/mpl.h>      // First_if_different
#include <../CGALOSP/enum.h>            // CGAL::Sign etc.
#include <../CGALOSP/tags.h>            // Tag_true / Tag_false

#include <../CGALOSP/Coercion_traits.h>
#include <../CGALOSP/Algebraic_structure_traits.h>
#include <../CGALOSP/Real_embeddable_traits.h>

#include <../CGALOSP/Fraction_traits.h>
#include <../CGALOSP/Rational_traits.h>

#include <../CGALOSP/Scalar_factor_traits.h>       // not part of CGAL 3.3
#include <../CGALOSP/Algebraic_extension_traits.h> // not part of CGAL 3.3

#include <../CGALOSP/Needs_parens_as_product.h>

#include <../CGALOSP/utils_classes.h>
#include <../CGALOSP/utils.h>
#include <../CGALOSP/FPU.h>
#include <../CGALOSP/float.h>
#include <../CGALOSP/double.h>
#include <../CGALOSP/long_double.h>

#include <../CGALOSP/Interval_nt.h> // needed by To_interval(long double), To_interval(long), To_interval(long long)

#include <../CGALOSP/int.h>
#include <../CGALOSP/long_long.h>

#ifdef CGAL_USE_GMP
#ifdef CGAL_USE_GMPXX
#include <../CGALOSP/gmpxx.h>
#endif // CGAL_USE_GMPXX
#endif // CGAL_USE_GMP

#include <../CGALOSP/number_utils.h>
#include <../CGALOSP/number_utils_classes.h>

#endif // CGAL_NUMBER_TYPE_BASIC_H
