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

#include "pattern.hpp"
#include "ruler.hpp"
#include "song.hpp"
#include "track.hpp"


using namespace std;
using namespace Gdk;
using namespace Dino;


Ruler::Ruler(int length, int subs, int interval, int size, int height)
  : m_length(length), m_subs(subs), m_interval(interval), 
    m_div_size(size), m_height(height) {
  set_size_request(m_length * m_div_size + 1, m_height);
  add_events(BUTTON_PRESS_MASK | BUTTON_RELEASE_MASK | BUTTON_MOTION_MASK);
}

  
void Ruler::set_length(int length) {
  m_length = length;
  set_size_request(m_length * m_div_size + 1, m_height);
}


void Ruler::set_subdivisions(int subs) {
  m_subs = subs;
}


void Ruler::set_interval(int interval) {
  m_interval = interval;
}


void Ruler::set_division_size(int size) {
  m_div_size = size;
  set_size_request(m_length * m_div_size + 1, m_height);
}


void Ruler::on_realize() {
  Gtk::DrawingArea::on_realize();
  Glib::RefPtr<Gdk::Window> win = get_window();
  m_gc = GC::create(win);
  win->clear();
}


bool Ruler::on_expose_event(GdkEventExpose* event) {

  Glib::RefPtr<Gdk::Window> win = get_window();
  win->clear();
  if (m_length <= 0)
    return true;
  
  Pango::FontDescription fd("helvetica bold 9");
  get_pango_context()->set_font_description(fd);

  for (int i = 0; i <= m_length; ++i) {
    win->draw_line(m_gc, i * m_div_size, m_height - 4, 
		   i * m_div_size, m_height);
    if (i % m_interval == 0 && i != 0) {
      Glib::RefPtr<Pango::Layout> l = 
	Pango::Layout::create(get_pango_context());
      l->set_text(std::to_string(i));
      Pango::Rectangle rect = l->get_pixel_logical_extents();
      win->draw_layout(m_gc, i * m_div_size - rect.get_width() / 2, 
		       (m_height - 4 - rect.get_height()) / 2, l);
    }
    if (i == m_length)
      break;
    for (int j = 1; j < m_subs; ++j) {
      win->draw_line(m_gc, i * m_div_size + j * m_div_size / m_subs, 
		     m_height- 2, i * m_div_size + j * m_div_size / m_subs, 
		     m_height);
    }
  }
  return true;
}


bool Ruler::on_button_press_event(GdkEventButton* event) {
  double pos = event->x / m_div_size;
  signal_clicked(pos, event->button);
  return true;
}


PatternRuler::PatternRuler()
  : Ruler(0, 1, 1, 20, 20),
    m_song(0) {

}


void PatternRuler::set_song(const Song* song) {
  m_song = song;
}


void PatternRuler::set_pattern(int track, int pattern) {
  if (track != -1 && pattern != -1) {
    // XXX need to connect to the length and steps signals
    const Pattern* pat = &*m_song->tracks_find(track)->pat_find(pattern);
    set_length(pat->get_length());
    set_subdivisions(pat->get_steps());
    set_interval(1);
    set_division_size(8 * pat->get_steps());
  }
  else
    set_length(0);
}
