/**
 * PANDA 3D SOFTWARE
 * Copyright (c) Carnegie Mellon University.  All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nodeCachedReferenceCount.cxx
 * @author drose
 * @date 2005-05-07
 */

#include "nodeCachedReferenceCount.h"

TypeHandle NodeCachedReferenceCount::_type_handle;

/**
 * Does some easy checks to make sure that the reference count isn't
 * completely bogus.
 */
bool NodeCachedReferenceCount::
do_test_ref_count_integrity() const {
  nassertr(this != NULL, false);

  // If this assertion fails, we're trying to delete an object that was just
  // deleted.  Possibly you used a real pointer instead of a PointerTo at some
  // point, and the object was deleted when the PointerTo went out of scope.
  // Maybe you tried to create an automatic (local variable) instance of a
  // class that derives from ReferenceCount.  Or maybe your headers are out of
  // sync, and you need to make clean in direct or some higher tree.
  nassertr(_node_ref_count != -100, false);

  // If this assertion fails, the reference counts are all screwed up
  // altogether.  Maybe some errant code stomped all over memory somewhere.
  nassertr(_node_ref_count >= 0, false);

  return CachedTypedWritableReferenceCount::do_test_ref_count_integrity();
}
