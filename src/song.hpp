#ifndef SONG_HPP
#define SONG_HPP

#include <map>
#include <string>

#include <glibmm/thread.h>
#include <sigc++/signal.h>

#include "track.hpp"


using namespace Glib;
using namespace sigc;
using namespace std;


class Song {
public:
  
  Song();
  
  // accessors
  const string& get_title() const;
  const string& get_author() const;
  const string& get_info() const;
  const map<int, Track>& get_tracks() const;
  map<int, Track>& get_tracks();
  int get_length() const;
  Mutex& get_big_lock() const;
  
  // mutators
  void set_title(const string& title);
  void set_author(const string& author);
  void set_info(const string& info);
  int add_track();
  bool remove_track(int id);
  
  // XML I/O
  bool is_dirty() const;
  bool write_file(const string& filename) const;
  bool load_file(const string& filename);
  void clear();
  
public:
  
  mutable signal<void, const string&> signal_title_changed;
  mutable signal<void, const string&> signal_author_changed;
  mutable signal<void, const string&> signal_info_changed;
  mutable signal<void, int> signal_length_changed;
  mutable signal<void, int> signal_track_added;
  mutable signal<void, int> signal_track_removed;
  
private:
  
  // non-copyable for now
  Song& operator=(const Song&) { return *this; }
  
  string m_title;
  string m_author;
  string m_info;
  map<int, Track> m_tracks;
  int m_length;

  mutable Mutex m_big_lock;
  
  mutable bool m_dirty;
};


#endif
