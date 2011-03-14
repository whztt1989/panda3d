// Filename: oSphereLens.h
// Created by:  drose (25Feb11)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#ifndef OSPHERELENS_H
#define OSPHERELENS_H

#include "pandabase.h"

#include "lens.h"

////////////////////////////////////////////////////////////////////
//       Class : OSphereLens
// Description : A OSphereLens is a special nonlinear lens that
//               doesn't correspond to any real physical lenses.  It's
//               primarily useful for generating 360-degree wraparound
//               images while avoiding the distortion associated with
//               fisheye images.
//
//               A OSphereLens is similar to a Cylindrical lens and
//               PSphereLens, except that it is orthographic in the
//               vertical direction.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDAFX OSphereLens : public Lens {
PUBLISHED:
  INLINE OSphereLens();

public:
  INLINE OSphereLens(const OSphereLens &copy);
  INLINE void operator = (const OSphereLens &copy);

public:
  virtual PT(Lens) make_copy() const;

protected:
  virtual bool extrude_impl(const LPoint3f &point2d,
                            LPoint3f &near_point, LPoint3f &far_point) const;
  virtual bool project_impl(const LPoint3f &point3d, LPoint3f &point2d) const;

  virtual float fov_to_film(float fov, float focal_length, bool horiz) const;
  virtual float fov_to_focal_length(float fov, float film_size, bool horiz) const;
  virtual float film_to_fov(float film_size, float focal_length, bool horiz) const;

public:
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    Lens::init_type();
    register_type(_type_handle, "OSphereLens",
                  Lens::get_class_type());
  }

private:
  static TypeHandle _type_handle;
};

#include "oSphereLens.I"

#endif
