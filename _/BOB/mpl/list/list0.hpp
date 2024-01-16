
#ifndef BOOST_MPL_LIST_LIST0_HPP_INCLUDED
#define BOOST_MPL_LIST_LIST0_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <../BOB/mpl/long.hpp>
#include <../BOB/mpl/aux_/na.hpp>
#include <../BOB/mpl/list/aux_/push_front.hpp>
#include <../BOB/mpl/list/aux_/pop_front.hpp>
#include <../BOB/mpl/list/aux_/push_back.hpp>
#include <../BOB/mpl/list/aux_/front.hpp>
#include <../BOB/mpl/list/aux_/clear.hpp>
#include <../BOB/mpl/list/aux_/O1_size.hpp>
#include <../BOB/mpl/list/aux_/size.hpp>
#include <../BOB/mpl/list/aux_/empty.hpp>
#include <../BOB/mpl/list/aux_/begin_end.hpp>
#include <../BOB/mpl/list/aux_/item.hpp>

namespace boost { namespace mpl {

template< typename Dummy = na > struct list0;

template<> struct list0<na>
    : l_end
{
    typedef l_end type;
};

}}

#endif // BOOST_MPL_LIST_LIST0_HPP_INCLUDED
