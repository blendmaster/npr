
#include <string>
#include <map>
#include <vector>
#include <utility>

#pragma once

namespace EZGraphics {

  /* -------------------------------------- */

  class MenuCreator {

  public:
    typedef void (*MENUHANDLER)();
    typedef std::pair < std::pair<std::string, int>, std::pair<int, MENUHANDLER> > MENUENTRY;
  
  private:

    enum CODE { ENTRY=0, BEGIN=-1, BEGINSUB=-3, ENDSUB=-4, COLLAPSEDSUB=-5 };

    static std::vector<MENUENTRY> s;
    static int currentval;
    static std::map<int,MENUHANDLER> HandlerFunc;

  public:

    static void beginMenu();
    static void addMenuEntry ( const char *name, MENUHANDLER handler );
    static void beginSubMenu ( const char *name );
    static int endSubMenu ( );
    static int endMenu();

    static void menuHandlerBase ( int );

  };

  /* -------------------------------------- */

};
