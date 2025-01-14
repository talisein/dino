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

#include <iostream>

#include "octavelabel.hpp"


using namespace std;
using namespace Gtk;
using namespace Gdk;


OctaveLabel::OctaveLabel(int width, int note_height)
  : m_width(width), m_note_height(note_height) {
  m_bg_color.set_rgb(60000, 60000, 65535);
  m_fg_color.set_rgb(40000, 40000, 40000);
  m_colormap = Colormap::get_system();
  m_colormap->alloc_color(m_bg_color);
  m_colormap->alloc_color(m_fg_color);
  set_size_request(m_width, 128 * m_note_height + 1);
}

  
void OctaveLabel::on_realize() {
  Gtk::DrawingArea::on_realize();
  Glib::RefPtr<Gdk::Window> win = get_window();
  m_gc = GC::create(win);
  win->clear();
}


bool OctaveLabel::on_expose_event(GdkEventExpose* event) {

  Glib::RefPtr<Gdk::Window> win = get_window();
  win->clear();
  m_gc->set_foreground(m_bg_color);
  win->draw_rectangle(m_gc, true, 0, 0, m_width, 128 * m_note_height);
  
  Pango::FontDescription fd("helvetica bold 9");
  get_pango_context()->set_font_description(fd);
  char tmp[10];
  
  Glib::RefPtr<Pango::Layout> l = Pango::Layout::create(get_pango_context());
  
  m_gc->set_foreground(m_fg_color);
  for (int i = 0; i < 11; ++i) {
    win->draw_line(m_gc, 0, m_note_height * (128 - 12 * i), 
		   m_width, m_note_height * (128 - 12 * i));
    sprintf(tmp, "%d", i);
    l->set_text(tmp);
    Pango::Rectangle rect = l->get_pixel_logical_extents();
    win->draw_layout(m_gc, (m_width - rect.get_width()) / 2,
		     (128 - 12*i - 6) * m_note_height - rect.get_height() / 2,
		     l);
  }
  //win->draw_line(m_gc, 0, 0, m_width - 1, 0);
  //win->draw_line(m_gc, 0, 0, 0, m_note_height * 128);
  //win->draw_line(m_gc, m_width - 1, 0, m_width, m_note_height * 128);

  return true;
}


