#ifndef DINO_HPP
#define DINO_HPP

#include <gtkmm.h>
#include <libglademm.h>
#include <ladcca/ladcca.h>

#include "cceditor.hpp"
#include "patterneditor.hpp"
#include "ruler.hpp"
#include "sequencer.hpp"
#include "singletextcombo.hpp"
#include "song.hpp"


using namespace Glib;
using namespace Gnome::Glade;
using namespace Gtk;
using namespace sigc;
using namespace std;


/** This is the main class. It connects our custom widgets to the rest of the
    GUI and sets up all signals and initial values. */
class Dino {
public:
  Dino(int argc, char** argv, RefPtr<Xml> xml);
  
  Gtk::Window* get_window();
  
  // menu and toolbutton callbacks
  void slot_file_new();
  void slot_file_open();
  void slot_file_save();
  void slot_file_save_as();
  void slot_file_quit();
  
  void slot_edit_cut();
  void slot_edit_copy();
  void slot_edit_paste();
  void slot_edit_delete();
  void slot_edit_add_track();
  void slot_edit_delete_track();
  void slot_edit_add_pattern();
  void slot_edit_delete_pattern();
  
  void slot_transport_play();
  void slot_transport_stop();
  void slot_transport_go_to_start();
  
  void slot_help_about_dino();
  
private:
  
  /** This is a convenience function that returns a pointer of type @c T* to
      the widget with name @c name. If there is no widget in @c xml with that
      name it returns NULL. */
  template <class T>
  inline T* w(const string& name) {
    return dynamic_cast<T*>(m_xml->get_widget(name));
  }
  
  void update_track_widgets();
  void update_track_combo(int activeTrack = -1);
  void update_pattern_combo(int activePattern = -1);
  void update_editor_widgets();
  void active_track_changed();
  void init_pattern_editor();
  void init_sequence_editor();
  void init_info_editor();
  void init_menus();
  bool init_lash(int argc, char** argv);
  
  // internal callbacks
  void slot_cc_number_changed();
  void slot_cc_editor_size_changed();
  bool slot_check_ladcca_events();
  
  RefPtr<Xml> m_xml;
  Gtk::Window* m_window;
  PatternEditor m_pe;
  CCEditor m_cce;
  VBox* m_vbx_track_editor;
  VBox* m_vbx_track_labels;
  
  SingleTextCombo m_cmb_track;
  SingleTextCombo m_cmb_pattern;
  connection m_track_pattern_connection;
  connection m_pattern_editor_connection;
  connection m_pattern_added_connection;
  connection m_pattern_removed_connection;
  SpinButton* m_sb_cc_number;
  Label* m_lb_cc_description;
  SpinButton* m_sb_cc_editor_size;
  ::Ruler m_sequence_ruler;
  ::Ruler m_pattern_ruler_1;
  Entry* m_ent_title;
  Entry* m_ent_author;
  TextView* m_text_info;

  static char* cc_descriptions[];
  
  Song m_song;
  
  Dialog* m_about_dialog;
  
  Sequencer m_seq;
  
  cca_client_t* m_lash_client;
};


#endif


// For the Doxygen main page:
/** @mainpage Dino source code documentation
    This source code documentation is generated in order to help people
    (including me) understand how Dino works, or is supposed to work. 
    But it's not meant to be a complete API reference, so many functions and
    types will be undocumented.
    
    Send questions and comments to larsl@users.sourceforge.net. 
*/
