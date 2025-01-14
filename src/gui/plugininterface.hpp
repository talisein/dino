#ifndef PLUGININTERFACE_HPP
#define PLUGININTERFACE_HPP

#include <string>
#include <gtkmm.h>


namespace Dino {
  class Song;
  class Sequencer;
}

class DinoGUI;


class GUIPage : public Gtk::HBox {
public:
  
  enum Flags {
    PageNoFlags = 0,
    PageSupportsClipboard = (1 << 0)
  };
  
  GUIPage(Flags flags = PageNoFlags) : m_flags(flags) { }
  
  Flags get_flags() const { return m_flags; }
  
  virtual void cut_selection() { }
  virtual void copy_selection() { }
  virtual void paste() { }
  virtual void delete_selection() { }
  virtual void select_all() { }
  
  virtual void reset_gui() { }
  
private:
  
  Flags m_flags;
  
};


/** An object of this class is passed to Plugin::initialise() when Dino loads
    a plugin. It can be used to access the functions and data structures
    available to the plugin. */
class PluginInterface {
public:
  
  virtual ~PluginInterface() { }
  
  /** Add a page to the main notebook. */
  virtual void add_page(const std::string& label, GUIPage& widget) = 0;

  /** Remove a page from the main notebook. */
  virtual void remove_page(GUIPage& widget) = 0;
  
  /** Returns the used Dino::Song object. */
  virtual Dino::Song& get_song() = 0;
  
  /** Returns the used Dino::Sequencer object. */
  virtual Dino::Sequencer& get_sequencer() = 0;
  
};


/** This is the superclass for all plugins. Every Dino plugin should have
    a global variable with the name @c dino_plugin whose type is a subclass
    of this class. */
class Plugin {
public:
  
  /** All plugins _must_ implement this. It should return a short 
      human-readable name for the plugin, e.g. "Version checker" or
      "DSSI host" */
  virtual std::string get_name() const = 0;
  
  /** This function will be called when the plugin has been loaded and Dino
      wants to use it. You should probably override this. */
  virtual void initialise(PluginInterface& plif) { }
  
  /** This function will be called when the plugin is unloaded. Free your 
      resources here. Remember that initialise() may not have been called
      before this function - for example, Dino will load all plugins it can
      find when it starts, call their get_name() functions, and unload them 
      again. */
  virtual ~Plugin() { }
  
};


#endif
