/****************************************************************************
   Dino - A simple pattern based MIDI sequencer
   
   Copyright (C) 2006  Lars Luthman <larsl@users.sourceforge.net>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
****************************************************************************/

#ifndef CONTROLLER_NUMBERS_HPP
#define CONTROLLER_NUMBERS_HPP

// Most of these functions are adapted from the DSSI header

namespace Dino {
  
  static const long g_controller_cc_bits = 0x20000000;
  static const long g_controller_nrpn_bits = 0x40000000;
  
  static const long g_controller_none = -1;
  
  
  /** Returns an invalid ID. */
  static inline long make_invalid() {
    return g_controller_none;
  }
  
  
  /** Returns @c true if the given @c id is actually a controller number. */
  static inline bool controller_is_set(long id) {
    return (g_controller_none != id);
  }
  
  
  /** Returns the Dino controller number for the given MIDI @c cc number. */
  static inline long make_cc(long cc) {
    return g_controller_cc_bits | cc;
  }
  
  
  /** Returns @c true if the given Dino controller number is a MIDI CC. */
  static inline bool is_cc(long id) {
    return g_controller_cc_bits & id;
  }
  
  
  /** Returns the MIDI CC number for the given Dino controller number @c id. */
  static inline long cc_number(long id) {
    return id & 0x7f;
  }
  

  /** Returns the Dino controller number for the given MIDI @c nrpn number. */
  static inline long make_nrpn(long nrpn) {
    return g_controller_nrpn_bits | (nrpn << 8);
  }
  
  
  /** Returns @c true if the given Dino controller number is a MIDI NRPN. */
  static inline bool is_nrpn(long id) {
    return g_controller_nrpn_bits & id;
  }

  
  /** Returns the MIDI NRPN number for the given Dino controller 
      number @c id. */
  static inline long nrpn_number(long id) {
    return (id >> 8) & 0x3fff;
  }
  
  
  /** Returns the Dino controller number for MIDI pitchbend. */
  static inline long make_pbend() {
    return 128;
  }
  
  
  /** Returns @c true if the given Dino controller number is MIDI pitchbend. */
  static inline bool is_pbend(long id) {
    return (id == 128);
  }


}

#endif
