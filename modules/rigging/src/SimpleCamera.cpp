/**
 * rigging: SimpleCamera.cpp
 * Copyright (c) Torr Vision Group, University of Oxford, 2015. All rights reserved.
 */

#include "SimpleCamera.h"

namespace rigging {

//#################### CONSTRUCTORS ####################

SimpleCamera::SimpleCamera(const Eigen::Vector3f& position, const Eigen::Vector3f& look, const Eigen::Vector3f& up)
: m_n(look), m_position(position), m_v(up)
{
  m_n.normalize();
  m_v.normalize();

  // Compute the camera's u axis from the up vector that was passed in and its n axis.
  m_u = m_v.cross(m_n);
  m_u.normalize();

  // Compute the camera's v axis from its n and u axes.
  m_v = m_n.cross(m_u);
  m_v.normalize();
}

//#################### PUBLIC MEMBER FUNCTIONS ####################

SimpleCamera& SimpleCamera::move(const Eigen::Vector3f& dir, float delta)
{
  m_position += delta * dir;
  return *this;
}

SimpleCamera& SimpleCamera::move_n(float delta)
{
  m_position += delta * m_n;
  return *this;
}

SimpleCamera& SimpleCamera::move_u(float delta)
{
  m_position += delta * m_u;
  return *this;
}

SimpleCamera& SimpleCamera::move_v(float delta)
{
  m_position += delta * m_v;
  return *this;
}

Eigen::Vector3f SimpleCamera::n() const
{
  return m_n;
}

Eigen::Vector3f SimpleCamera::p() const
{
  return m_position;
}

SimpleCamera& SimpleCamera::rotate(const Eigen::Vector3f& axis, float angle)
{
  Eigen::AngleAxisf rot(angle, axis);
  m_n = rot * m_n;
  m_u = rot * m_u;
  m_v = rot * m_v;
  return *this;
}

SimpleCamera& SimpleCamera::set_from(const Camera& rhs)
{
  m_position = rhs.p();
  m_n = rhs.n();
  m_u = rhs.u();
  m_v = rhs.v();
  return *this;
}

Eigen::Vector3f SimpleCamera::u() const
{
  return m_u;
}

Eigen::Vector3f SimpleCamera::v() const
{
  return m_v;
}

}
