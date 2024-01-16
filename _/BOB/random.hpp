/* boost random.hpp header file
 *
 * Copyright Jens Maurer 2000-2001
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/random for documentation.
 *
 * $Id$
 *
 * Revision history
 *  2000-02-18  portability fixes (thanks to Beman Dawes)
 *  2000-02-21  shuffle_output, inversive_congruential_schrage,
 *              generator_iterator, uniform_smallint
 *  2000-02-23  generic modulus arithmetic helper, removed *_schrage classes,
 *              implemented Streamable and EqualityComparable concepts for 
 *              generators, added Bernoulli distribution and Box-Muller
 *              transform
 *  2000-03-01  cauchy, lognormal, triangle distributions; fixed 
 *              uniform_smallint; renamed gaussian to normal distribution
 *  2000-03-05  implemented iterator syntax for distribution functions
 *  2000-04-21  removed some optimizations for better BCC/MSVC compatibility
 *  2000-05-10  adapted to BCC and MSVC
 *  2000-06-13  incorporated review results
 *  2000-07-06  moved basic templates from namespace detail to random
 *  2000-09-23  warning removals and int64 fixes (Ed Brey)
 *  2000-09-24  added lagged_fibonacci generator (Matthias Troyer)
 *  2001-02-18  moved to individual header files
 */

#ifndef BOOST_RANDOM_HPP
#define BOOST_RANDOM_HPP

// generators
#include <../BOB/random/additive_combine.hpp>
#include <../BOB/random/discard_block.hpp>
#include <../BOB/random/independent_bits.hpp>
#include <../BOB/random/inversive_congruential.hpp>
#include <../BOB/random/lagged_fibonacci.hpp>
#include <../BOB/random/linear_congruential.hpp>
#include <../BOB/random/linear_feedback_shift.hpp>
#include <../BOB/random/mersenne_twister.hpp>
#include <../BOB/random/mixmax.hpp>
#include <../BOB/random/ranlux.hpp>
#include <../BOB/random/shuffle_order.hpp>
#include <../BOB/random/shuffle_output.hpp>
#include <../BOB/random/subtract_with_carry.hpp>
#include <../BOB/random/taus88.hpp>
#include <../BOB/random/xor_combine.hpp>

// misc
#include <../BOB/random/generate_canonical.hpp>
#include <../BOB/random/seed_seq.hpp>
#include <../BOB/random/random_number_generator.hpp>
#include <../BOB/random/variate_generator.hpp>

// distributions
#include <../BOB/random/bernoulli_distribution.hpp>
#include <../BOB/random/beta_distribution.hpp>
#include <../BOB/random/binomial_distribution.hpp>
#include <../BOB/random/cauchy_distribution.hpp>
#include <../BOB/random/chi_squared_distribution.hpp>
#include <../BOB/random/discrete_distribution.hpp>
#include <../BOB/random/exponential_distribution.hpp>
#include <../BOB/random/extreme_value_distribution.hpp>
#include <../BOB/random/fisher_f_distribution.hpp>
#include <../BOB/random/gamma_distribution.hpp>
#include <../BOB/random/geometric_distribution.hpp>
#include <../BOB/random/hyperexponential_distribution.hpp>
#include <../BOB/random/laplace_distribution.hpp>
#include <../BOB/random/lognormal_distribution.hpp>
#include <../BOB/random/negative_binomial_distribution.hpp>
#include <../BOB/random/non_central_chi_squared_distribution.hpp>
#include <../BOB/random/normal_distribution.hpp>
#include <../BOB/random/piecewise_constant_distribution.hpp>
#include <../BOB/random/piecewise_linear_distribution.hpp>
#include <../BOB/random/poisson_distribution.hpp>
#include <../BOB/random/student_t_distribution.hpp>
#include <../BOB/random/triangle_distribution.hpp>
#include <../BOB/random/uniform_01.hpp>
#include <../BOB/random/uniform_int.hpp>
#include <../BOB/random/uniform_int_distribution.hpp>
#include <../BOB/random/uniform_on_sphere.hpp>
#include <../BOB/random/uniform_real.hpp>
#include <../BOB/random/uniform_real_distribution.hpp>
#include <../BOB/random/uniform_smallint.hpp>
#include <../BOB/random/weibull_distribution.hpp>

#include <../BOB/random/generate_canonical.hpp>

#endif // BOOST_RANDOM_HPP
