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

#ifndef CCEDITOR_HPP
#define CCEDITOR_HPP

#include <utility>

#include <gtkmm.h>


namespace Dino {
  class Pattern;
}


class CCEditor : public Gtk::DrawingArea {
public:
  
  CCEditor();
  
  void set_controller(Dino::Pattern* pat, long controller);
  void set_step_width(int width);
  
protected:
  
  virtual bool on_button_press_event(GdkEventButton* event);
  virtual bool on_button_release_event(GdkEventButton* event);
  virtual bool on_motion_notify_event(GdkEventMotion* event);
  virtual void on_realize();
  virtual bool on_expose_event(GdkEventExpose* event);
  
  int value2ypix(int value);
  int ypix2value(int value);
  int step2xpix(int value);
  int xpix2step(int value);
  
  Glib::RefPtr<Gdk::GC> m_gc;
  Gdk::Color m_bg_colour1, m_bg_colour2, m_grid_colour, 
    m_edge_colour, m_fg_colour;
  
  unsigned m_step_width;
  
  Dino::Pattern* m_pat;
  long m_controller;
  
  int m_drag_step;
};


#endif
