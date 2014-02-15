////////////////////////////////////////////////////////////////////////////////
//
// Package:   pan_tilt
//
// File:      pan_tilt.h
//
/*! \file
 *
 * $LastChangedDate$
 * $Rev$
 *
 * \brief Top-level pan_tilt library include file.
 *
 * \author Robin Knight (robin.knight@roadnarrows.com)
 * \author Daniel Packard (daniel@roadnarrows.com)
 *
 * \par Copyright:
 * (C) 2014  RoadNarrows
 * (http://www.RoadNarrows.com)
 * \n All Rights Reserved
 */
/*
 * @EulaBegin@
 * 
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that
 * (1) The above copyright notice and the following two paragraphs
 * appear in all copies of the source code and (2) redistributions
 * including binaries reproduces these notices in the supporting
 * documentation.   Substantial modifications to this software may be
 * copyrighted by their authors and need not follow the licensing terms
 * described here, provided that the new terms are clearly indicated in
 * all files where they apply.
 * 
 * IN NO EVENT SHALL THE AUTHOR, ROADNARROWS LLC, OR ANY MEMBERS/EMPLOYEES
 * OF ROADNARROW LLC OR DISTRIBUTORS OF THIS SOFTWARE BE LIABLE TO ANY
 * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
 * DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
 * EVEN IF THE AUTHORS OR ANY OF THE ABOVE PARTIES HAVE BEEN ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE AUTHOR AND ROADNARROWS LLC SPECIFICALLY DISCLAIM ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN
 * "AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 * 
 * @EulaEnd@
 */
////////////////////////////////////////////////////////////////////////////////

#ifndef _PAN_TILT_H
#define _PAN_TILT_H

/*!
 *  \brief The pan_tilt namespace encapsulates all pan-tilt related constructs.
 */
namespace pan_tilt
{

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  /*!
   * \ingroup pan_tilt_h
   * \defgroup pt_ecodes  Pan-Tilt Robot Error Codes
   *
   * Pan-Tilt package-wide error codes.
   *
   * \{
   */
  static const int PT_OK              =  0; ///< not an error, success

  static const int PT_ECODE_GEN       =  1; ///< general, unspecified error
  static const int PT_ECODE_SYS       =  2; ///< system (errno) error
  static const int PT_ECODE_INTERNAL  =  3; ///< internal error (bug)
  static const int PT_ECODE_BAD_VAL   =  4; ///< bad value general error
  static const int PT_ECODE_TOO_BIG   =  5; ///< value/list/size too big
  static const int PT_ECODE_TOO_SMALL =  6; ///< value/list/size too small
  static const int PT_ECODE_RANGE     =  7; ///< value out-of-range
  static const int PT_ECODE_BAD_OP    =  8; ///< invalid operation error
  static const int PT_ECODE_TIMEDOUT  =  9; ///< operation timed out error
  static const int PT_ECODE_NO_DEV    = 10; ///< device not found error
  static const int PT_ECODE_NO_RSRC   = 11; ///< no resource available error
  static const int PT_ECODE_BUSY      = 12; ///< resource busy error
  static const int PT_ECODE_NO_EXEC   = 13; ///< cannot execute error
  static const int PT_ECODE_PERM      = 14; ///< no permissions error
  static const int PT_ECODE_DYNA      = 15; ///< dynamixel error
  static const int PT_ECODE_FORMAT    = 16; ///< bad format
  static const int PT_ECODE_NO_FILE   = 17; ///< file not found
  static const int PT_ECODE_XML       = 18; ///< XML error
  static const int PT_ECODE_ALARMED   = 19; ///< robot is alarmed
  static const int PT_ECODE_INTR      = 20; ///< operation interrupted
  static const int PT_ECODE_COLLISION = 21; ///< robot link(s) in collision
  static const int PT_ECODE_ESTOP     = 22; ///< robot emergency stopped

  static const int PT_ECODE_BADEC     = 23; ///< bad error code

  static const int PT_ECODE_NUMOF     = 24; ///< number of error codes
  /*! \} */

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  /*!
   *
   * \ingroup pan_tilt_h
   * \defgroup pt_prod  Pan-Tilt Product Identifiers
   *
   * Pan-tilt product ids, names, and descriptions.
   *
   *  Products ids are classified by class, family, size, dof, and special 
   *  fields.
   *
   * \{
   */

  /*!
   * \brief Convert version triplet to integer equivalent.
   *
   * \param major     Major version number.
   * \param minor     Minor version number.
   * \param revision  Revision number.
   */
  #define PT_VERSION(major, minor, revision) \
    ((((major)&0xff)<<24) | (((minor)&0xff)<<16) | ((revision)&0xffff))

  /*!
   * \brief Get version major number from version.
   *
   * \param ver       Version number.
   *
   * \return Major number.
   */
  #define PT_VER_MAJOR(ver)    (((ver)>>24) &0xff)

  /*!
   * \brief Get version minor number from version.
   *
   * \param ver       Version number.
   *
   * \return Minor number.
   */
  #define PT_VER_MINOR(ver)    (((ver)>>16) &0xff)

  /*!
   * \brief Get revision number from version.
   *
   * \param ver       Version number.
   *
   * \return Revision number.
   */
  #define PT_VER_REV(ver)    ((ver) & 0xffff)


  const char* const PanTiltProdFamily = "Pan-Tilt"; ///< product family name
  const int PanTiltProdFamilyUnknown  = 0; ///< unknown/undefined product family
  const int PanTiltProdIdUnknown      = 0; ///< unknown/undefined product id

  /*!
   * \brief Pan-Tilt product size codes.
   */
  enum PanTiltProdSize
  {
    PanTiltProdSizeUnknown  = 0,    ///< unknown size
    PanTiltProdSizeStd      = 1,    ///< standard (normal) size

    PanTiltProdSizeNumOf    = 2     ///< number of
  };

  /*!
   * \brief Common Pan-Tilt product size codes as strings.
   */
  const char* const PanTiltProdSizeStrUnknown = "?"; ///< unknown base size
  const char* const PanTiltProdSizeStrStd     = "N"; ///< standard (normal) size
  /*! \} */

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  /*!
   * \ingroup pt_spec
   *
   * \defgroup pt_common_spec  Pan-Tilt Common Specs
   *
   * Pan-Tilt product family specifications.
   *
   * \{
   */
  // base servo ids
  static const int PanTiltServoIdPan    = 1;  ///< continuous rotating base
  static const int PanTiltServoIdTilt   = 2;  ///< left shoulder
  /*! \} */

  // . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

  /*!
   *
   * \ingroup pan_tilt_h
   * \defgroup pt_types  Pan-Tilt Common Simple Types
   *
   *  Common types used to control and report robot information.
   *  fields.
   *
   * \{
   */

  /*!
   * \brief Pan-Tilt tri-state type.
   *
   * Basically, a tri-state value is either unknown, 0, or 1.
   */
  enum PanTiltTriState
  {
    // unknown
    PanTiltTriStateUnknown  = -1,     ///< unknown state

    // low state synonyms
    PanTiltTriStateFalse    = 0,      ///< false
    PanTiltTriStateOff      = 0,      ///< off
    PanTiltTriStateDisabled = 0,      ///< disabled
    PanTiltTriStateLow      = 0,      ///< low
    PanTiltTriStateOpen     = 0,      ///< open
    PanTiltTriStateDark     = 0,      ///< dark

    // high state synonyms
    PanTiltTriStateTrue     = 1,      ///< true
    PanTiltTriStateOn       = 1,      ///< on
    PanTiltTriStateEnabled  = 1,      ///< enabled
    PanTiltTriStateHigh     = 1,      ///< high
    PanTiltTriStateClosed   = 1,      ///< closed
    PanTiltTriStateLight    = 1       ///< light
  };

  /*!
   * \brief Pan-Tilt mode of operation.
   *
   * Robot mode of operation.
   */
  enum PanTiltRobotMode
  {
    PanTiltRobotModeUnknown = -1, ///< unknown mode state
    PanTiltRobotModeManual  =  1, ///< can only operate locally, not remotely
    PanTiltRobotModeAuto    =  2  ///< fully available
  };

  /*!
   * \brief Robot or joint operational states.
   */
  enum PanTiltOpState
  {
    PanTiltOpStateUncalibrated  = 0,    ///< uncalibrated
    PanTiltOpStateCalibrating   = 1,    ///< calibrating
    PanTiltOpStateCalibrated    = 2     ///< calibrated
  };

  /*!
   * \brief Asynchronous task state.
   */
  enum PanTiltAsyncTaskState
  {
    PanTiltAsyncTaskStateIdle     = 0,    ///< idle, no async task running
    PanTiltAsyncTaskStateWorking  = 1     ///< async task running
  };

  /*! \} */

} // namespace pan_tilt


#endif // _PAN_TILT_H